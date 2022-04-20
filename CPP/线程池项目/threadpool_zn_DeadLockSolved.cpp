
#include "threadpool_zn.h"
#include <functional>
#include <thread>
#include <iostream>

const int TASK_MAX_THRESHHOLD = 4;// INT32_MAX; //用4测试是否会提交失败
const int THREAD_MAX_THRESHHOLD = 1024;
const int THREAD_MAX_IDLE_TIME = 60; // 单位：秒

// 线程池构造
ThreadPool::ThreadPool()
	: initThreadSize_(0) //start时会赋值
	, taskSize_(0)
	, idleThreadSize_(0)
	, curThreadSize_(0)
	, taskQueMaxThreshHold_(TASK_MAX_THRESHHOLD)
	, threadSizeThreshHold_(THREAD_MAX_THRESHHOLD)
	, poolMode_(PoolMode::MODE_FIXED)
	, isPoolRunning_(false)
{}

// 线程池析构
ThreadPool::~ThreadPool()
{
	isPoolRunning_ = false;

/*
析构时，运行到notEmpty_.notify_all()时
threadFunc可能有三种状态：
1.阻塞在notEmpty_.wait(lock)上，此时被notEmpty_.notify_all唤醒，发现isPoolRunning_不满足，自己销毁线程退出
2.走到while (isPoolRunning_)中的下半部分，正在执行任务，当执行完任务回头判断while (isPoolRunning_)不满足了，也能成功销毁并退出退出
3.进了while (isPoolRunning_)，但还没运行到notEmpty_.wait(lock)，当运行到时已经错过了析构时的notEmpty_.notify_all()，所以这一部分线程notEmpty_.wait(lock)永远不会被唤醒。
对于第三种情况无论那边先获取lock都会阻塞到notEmpty_.wait(lock)上。
解决方法：
修改三处代码，①先lock后notify；②内层循环双重判断；③内层循环退出后增加判断isPoolRunning_不满足后就销毁线程并退出的代码。
析构时先lock，确保threadFunc即使进入while (isPoolRunning_)也拿不到锁阻塞，登到析构函数中释放锁后，threadFunc拿到锁，但判断isPoolRunning_不满足退出内层循环，紧接着销毁线程并退出
*/


	////！！！notify放这里就会死锁，放lock下面就能解决死锁问题！！！
	//通知threadFunc中在notEmpty_上wait的,此时有的线程在执行任务，有的在睡眠等待，所以要exitCond_.wait等待执行任务的或睡眠的的起来后都把线程销毁后才能析构
	//notEmpty_.notify_all();

	//// 等待线程池里面所有的线程返回  有两种状态：阻塞 & 正在执行任务中
	std::unique_lock<std::mutex> lock(taskQueMtx_);
	
	notEmpty_.notify_all();//放这里才不会死锁，先lock再notify就不会死锁为什么？ //解决死锁之修改①

	//这里一定要有人通知，bingqie满足后面的条件才会唤醒，不然会一直阻塞阻塞
	exitCond_.wait(lock, [&]()->bool {return threads_.size() == 0; });//每个线程解决时都会发信号，但只有当hreads_.size() == 0才有用
	std::cout << "now deconstruct ThreadPool!" << std::endl;
}

// 设置线程池的工作模式
void ThreadPool::setMode(PoolMode mode)
{
	if (checkRunningState())
		return;
	poolMode_ = mode;
}
//void ThreadPool::setInitThredSize(int size)
//{
//	initThreadSize_ = size;
//}

// 设置task任务队列上线阈值
void ThreadPool::setTaskQueMaxThreshHold(int threshhold)
{
	//if (checkRunningState())
	//	return;
	taskQueMaxThreshHold_ = threshhold;
}

// 设置线程池cached模式下线程阈值
void ThreadPool::setThreadSizeThreshHold(int threshhold)
{
	if (checkRunningState())
		return;
	if (poolMode_ == PoolMode::MODE_CACHED)
	{
		threadSizeThreshHold_ = threshhold;
	}
}


//用户给线程池提交任务  用户调用该接口，传入任务对象，生产任务-->生产者
Result  ThreadPool::submitTask(std::shared_ptr<Task> sp)
{
	// 获取锁
	std::unique_lock<std::mutex> lock(taskQueMtx_);

	// 线程的通信  等待任务队列有空余   wait   wait_for   wait_until
	// 用户提交任务，最长不能阻塞超过1s，否则判断提交任务失败，返回
	if (!notFull_.wait_for(lock, std::chrono::seconds(1),[&]()->bool { return tskQue_.size() < (size_t)taskQueMaxThreshHold_; }))//wait_for 等1s未满足条件，返回false
	{
		// 表示notFull_等待1s种，条件依然没有满足
		std::cerr << "task queue is full, submit task fail." << std::endl;
		// return task->getResult();  //为什么不行  Task  Result   线程执行完task，就pop，task对象就被析构掉了
		return Result(sp, false);
	}

	// 如果有空余，把任务放入任务队列中
	tskQue_.emplace(sp);
	taskSize_++;

	// 因为新放了任务，任务队列肯定不空了，在notEmpty_上进行通知，赶快分配线程执行任务
	notEmpty_.notify_all();

	// cached模式 任务处理比较紧急 场景：小而快的任务 需要根据任务数量和空闲线程的数量，判断是否需要创建新的线程出来
	if (poolMode_ == PoolMode::MODE_CACHED
		&& taskSize_ > idleThreadSize_ //空闲线程数已经不够执行这么多任务
		&& curThreadSize_ < threadSizeThreshHold_) //不能超过最大线程数量
	{
		std::cout << ">>> create new thread..." << std::endl;

		// 创建新的线程对象，把ThreadPool中的函数对象绑定到Thread上的func_
		auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
		int threadId = ptr->getId();
		threads_.emplace(threadId, std::move(ptr));//放入线程列表

		// 创建后启动线程
		threads_[threadId]->start();
		// 修改线程个数相关的变量
		curThreadSize_++;//可以用map容器的size表示
		idleThreadSize_++;
	}

	// 返回任务的Result对象
	return Result(sp);


	// return task->getResult();
}


// 开启线程池
void ThreadPool::start(int initThreadSize)
{
	// 设置整个线程池的运行状态
	isPoolRunning_ = true;

	// 记录初始线程个数
	initThreadSize_ = initThreadSize;
	curThreadSize_ = initThreadSize;

	// 创建线程对象
	for (int i = 0; i < initThreadSize_; i++)
	{
		// 创建thread线程对象的时候，把线程函数给到thread线程对象
		//auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
		auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
		int threadId = ptr->getId();
		threads_.emplace(threadId, std::move(ptr));

		//threads_.emplace_back(ptr);//unique_ptr不允许直接拷贝复制
		 //threads_.emplace(std::move(ptr));
	}

	// 启动所有线程  std::vector<Thread*> threads_;
	for (int i = 0; i < initThreadSize_; i++)
	{
		threads_[i]->start(); // 需要去执行创建一个线程，并执行线程函数
		idleThreadSize_++;    // 记录初始空闲线程的数量
	}
}

//定义线程函数  线程池的所有线程从任务队列里面消费任务
void ThreadPool::threadFunc(int threadid)// 线程函数返回，相应的线程也就结束了//初始4个线程都执行这个函数，到task队列取任务执行
{
	//std::cout << "begin threadFunc tid:" <<std::this_thread::get_id()
	//	<< std::endl;

	//std::cout << "end threadFunc tid:" << std::this_thread::get_id()
	//	<< std::endl;
	auto lastTime = std::chrono::high_resolution_clock().now();

	while (isPoolRunning_)
	{
		std::shared_ptr<Task> task;//空指针
		
		{//用于限定作用域
			//获取锁-->保证取task队列安全执行
			std::unique_lock<std::mutex> lock(taskQueMtx_);

			std::cout << "tid:" << std::this_thread::get_id()
				<< "尝试获取任务..." << std::endl;


			// cached模式下，有可能已经创建了很多的线程，但是空闲时间超过60s，应该把多余的线程
			// 结束回收掉（超过initThreadSize_数量的线程要进行回收）
			// 当前时间 - 上一次线程执行的时间 > 60s

			// 每一秒中返回一次   怎么区分：超时返回？还是有任务待执行返回
			// 锁 + 双重判断
			while (tskQue_.size() == 0 && isPoolRunning_) //解决死锁之修改②:双重判断
			{
				// 线程池要结束，回收线程资源
				//if (!isPoolRunning_)
				//{
				//	threads_.erase(threadid); // std::this_thread::getid()
				//	std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
				//		<< std::endl;
				//	exitCond_.notify_all();
				//	return; // 线程函数结束，线程结束
				//}

				if (poolMode_ == PoolMode::MODE_CACHED)
				{
					// 条件变量，超时返回了
					if (std::cv_status::timeout ==
						notEmpty_.wait_for(lock, std::chrono::seconds(1)))
					{
						auto now = std::chrono::high_resolution_clock().now();
						auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - lastTime);
						if (dur.count() >= THREAD_MAX_IDLE_TIME
							&& curThreadSize_ > initThreadSize_)
						{
							// 开始回收当前线程
							// 记录线程数量的相关变量的值修改
							// 把线程对象从线程列表容器中删除   没有办法 threadFunc《=》thread对象
							// threadid => thread对象 => 删除
							threads_.erase(threadid); // 却别于c++成的id std::this_thread::getid()
							curThreadSize_--;
							idleThreadSize_--;

							std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
								<< std::endl;
							return;
						}
					}
				}
				else //MODE_FIXED
				{
					// 等待notEmpty条件  没有任务就等
					std::cout << "------------------ready to wait on notEmpty!" << std::endl;
					notEmpty_.wait(lock);
					std::cout << "------------------ unlock on notEmpty!" << "threads_.size() =" << threads_.size()<<std::endl;
				}
				//不管哪种模式被唤醒后发现要么线程池要结束，需要回收线程资源，要么有任务要执行，跳出while(tskQue_.size() == 0)
				if (!isPoolRunning_)
				{
					break;
				}
			} //end of while (tskQue_.size() == 0)


			if (!isPoolRunning_) //解决死锁之修改③:不满足isPoolRunning_时要及时销毁线程，同时上面while里可以改成直接break
			{
				threads_.erase(threadid); // std::this_thread::getid()
				std::cout << "threadid:" << std::this_thread::get_id() << " will exit!"
					<< std::endl;
				exitCond_.notify_all();//通知ThreadPool析构函数结束
				return; // 结束线程函数，就是结束当前线程了!
			}

			//有任务了上面的while不满足就退出while
			idleThreadSize_--;//起来后就不空闲了

			std::cout << "tid:" << std::this_thread::get_id()
				<< "获取任务陈工..." << std::endl;

			//从任务队列取一个任务出来
			task = tskQue_.front();
			tskQue_.pop();
			taskSize_--;
			if( tskQue_.size() > 0 )
			{
				notEmpty_.notify_all();
			}
			
			//取出任务要通知,通知可以继续提交生产任务
			notFull_.notify_all();
		}//出这个作用域 就应该释放锁 

 		//当前线程负责执行任务
		if (task != nullptr)
		{
			std::cout << "tid:" << std::this_thread::get_id()
				<< "run task..." << std::endl;
			// task->run(); // 执行任务；把任务的返回值setVal方法给到Result
			task->exec();
			
		}

		idleThreadSize_++;
		lastTime = std::chrono::high_resolution_clock().now(); // 更新线程执行完任务的时间

	} //end of while (isPoolRunning_)
	
	//跳出while ，回收线程
	threads_.erase(threadid); // std::this_thread::getid()
	std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
		<< "threads_.size() ="<< threads_.size()
		<< std::endl;
	exitCond_.notify_all();//执行完任务才能通知ThreadPool析构函数结束

}


bool ThreadPool::checkRunningState() const
{
	return isPoolRunning_;
}

////////////////  线程方法实现
int Thread::generateId_ = 0;  //静态变量需要类外初始化

// 线程构造
Thread::Thread(ThreadFunc func)
	: func_(func) //接受绑定器绑定的函数
	, threadId_(generateId_++)//这个id用户创建用于辨识每一个thread
{}

// 线程析构
Thread::~Thread() {}

// 启动线程
void Thread::start()
{
	// 创建一个线程来执行一个线程函数 pthread_create
	std::thread t(func_, threadId_);  // C++11来说 线程对象t  和线程函数func_
	t.detach(); // 设置分离线程 不然函数会挂掉 -->linux中的  pthread_detach   把pthread_t设置成分离线程
}

int Thread::getId()const
{
	return threadId_;
}

/////////////////  Task方法实现
Task::Task()
	: result_(nullptr)
{}

void Task::exec()
{
	if (result_ != nullptr)
	{
		result_->setVal(run()); // 这里发生多态调用
	}
}

void Task::setResult(Result* res)
{
	result_ = res;
}


/////////////////   Result方法的实现
Result::Result(std::shared_ptr<Task> task, bool isValid)
	: isValid_(isValid)
	, task_(task)
{
	task_->setResult(this);
}

void Result::setVal(Any any)  // 谁调用的呢？？？
{
	// 存储task的返回值
	this->any_ = std::move(any);
	sem_.post(); // 已经获取的任务的返回值，增加信号量资源
}

Any Result::get() // 用户调用的
{
	if (!isValid_)
	{
		return "";
	}
	sem_.wait(); // task任务如果没有执行完，这里会阻塞用户的线程
	return std::move(any_);//any_对象不是函数中的局部对象，所以默认不会匹配到右值
}



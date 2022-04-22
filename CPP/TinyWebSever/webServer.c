#include "task.h"
#include "thread_pool.h"
 
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
	    printf("usage : %s port\n", argv[0]);
	    return 1;
    }
 
    int sockfd, connfd;
	struct sockaddr_in servaddr, client;
	
    int port = atoi(argv[1]);  //获取端口
    printGreen("port:%d",port);
    //设置服务端的sockaddr_in
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
    //1.创建socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
    printf("socket error\n");
    return 1;
    }
	
    //2.绑定
    int ret = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if(ret < 0)
    {
    printf("bind error\n");
    return 1;
    }
	
    //3.监听
    ret = listen(sockfd, 10);
    if(ret < 0)
    {
    printf("listen error\n");
    return 1;
    }
	
    //4.创建线程池,20个线程
    threadpool<task> pool(20);
    pool.start();  //线程池开始运行

int i = 0;
    while(1)
    {
    	printGreen("the %dth connection\n",++i);
        socklen_t len = sizeof(client);
		
        //5.接受连接, 只能accept绑定了socket的端口
        connfd = accept(sockfd, (struct sockaddr *)&client, &len);
        task *ta = new task(connfd);
		
        //6.向线程池添加任务
        pool.append_task(ta);
		
    }
    return 0;
}
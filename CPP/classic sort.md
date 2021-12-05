# 经典排序实现

各种排序的复杂度：

![img](https://images2018.cnblogs.com/blog/849589/201804/849589-20180402133438219-1946132192.png)





## 1.冒泡

## 2.选择

## 3.插入

## 4.归并

## 5.快速排序 (忽略)

```c++

#include <vector>
#include<time.h>
#include <iostream>
#include <algorithm>
using namespace std;


//冒泡排序 ：比较相邻元素，直到序列变为有序为止
void BubbleSort(vector<int> &v, size_t len)
{
	if (len == 0)
	{
		cout << "error!" << endl;
		return;
	}

	for (int i = 0; i < len - 1; i++)//i是次数
	{
		for (int j = 0; j < len - 1 - i; j++)//j才是具体下标
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}

    return;
 }



//选择排序
void SelectionSort(vector<int> &v, size_t len)
{
	if (len == 0)
	{
		cout << "error!" << endl;
		return;
	}

	for (int i = 0; i < len-1; i++)
	{
		int minIndex = i;//先假设一个最小值的位置
		for (int j = i + 1; j < len; j++)
		{
			if (v[minIndex] > v[j])
			{
				minIndex = j;//找出真正最小值的index
			}
		}
		swap(v[i], v[minIndex]);//把每一轮找到的真正最小值放到正确的位置

	}
	return;
}

//插入排序：将无序的元素插入到有序的元素序列中，插入后仍然有序

/*
实现思路：

1.从数组的第二个数据开始往前比较，即一开始用第二个数和他前面的一个比较，如果 符合条件（比前面的大或者小，自定义），则让他们交换位置。

2.然后再用第三个数和第二个比较，符合则交换，但是此处还得继续往前比较，比如有 5个数8，15，20，45, 17, 17比45小，需要交换，但是17也比20小，也要交换，当不需 要和15交换以后，说明也不需要和15前面的数据比较了，肯定不需要交换，因为前 面的数据都是有序的。

3.重复步骤二，一直到数据全都排完。

*/
void InsertSort(vector<int> &v, size_t len)
{
	if (len <= 1) 
		return;

	int i, j;
	//i是次数，也即排好的个数(即0 到i-1都是有序)，也即接下来要插入的元素的index;j是继续排
	for (i = 1; i<len; ++i) //元素0不考虑吗？
		for (j = i; j>0; --j)//j从i开始逐个往前进行比较，若发现比前面的小则交换
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
			else
				break;

			return;
}

//归并排序
//1.先实现合并两个已排序的子序列
void merge_sort_two_vect(vector<int> &v1, vector<int>&v2, vector<int> &v)//v1和v2是已经排序好的序列
{
	int i = 0, j = 0;
	while ( i < v1.size() && j<v2.size() )
	{

		if (v1[i] <= v2[j])
		{
			v.push_back(v1[i]);
			i++;
		}
		else
		{
			v.push_back(v2[j]);
			j++;
		}

	}
	//v1或v2中剩余的项插入
	for (; i < v1.size(); i++)
	{
		v.push_back(v1[i]);
	}

	for (; j < v2.size(); j++)
	{
		v.push_back(v2[j]);
	}
}
//2.实现单个序列的排序
void merg_sort(vector<int> &vect)
{
	if (vect.size() < 2)
	{
		return;
	}
	vector<int> sub1;
	vector<int> sub2;
	int mid = vect.size() / 2;
	for (int i = 0; i < mid; i++)
	{
		sub1.push_back(vect[i]);
	}

	for (int i = mid; i < vect.size(); i++)
	{
		sub2.push_back(vect[i]);
	}

	merg_sort(sub1);
	merg_sort(sub2);
	vect.clear();
	merge_sort_two_vect(sub1, sub2,vect);
}
void myPrintf(int val)
{
	cout << val << "" << endl;
}

int main()
{
	srand((int)time(0));//是的每两次产生不同的随机数
	vector<int> arr;
	int num;
	for (int i = 0; i < 20; i++)
	{
		num = rand() % 20 + 1;//产生1-20随机数
		arr.push_back(num);
	}
	int len = arr.size();
	//BubbleSort(arr, len);
	//SelectionSort(arr, len);
	//InsertSort(arr, len);
	merg_sort(arr);
	//快速排序暂时考虑，太难了
	for_each(arr.begin(), arr.end(), myPrintf);
	system("pause");
	return 0;
}
```

如何实现反序冒泡？


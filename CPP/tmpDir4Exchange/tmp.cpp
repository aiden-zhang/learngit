/*************************************************
File: main.cpp
Copyright: C.L.Wang
Author: C.L.Wang
Date: 2014-04-01
Description: explicit
Email: morndragon@126.com
**************************************************/

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <queue>
#include <deque>
#include <array>

using namespace std;

int main()
{
	//vector<int>v1{0,1,2,3,4,5};
	//cout << "*v1.begin():" << *v1.begin()<< "*v1.end():"<<*(v1.end()-1)<<endl;
	//for (auto it = v1.begin(); it <v1.end(); it++)
	//{
	//	
	//	cout << "*it:" << *it << endl;
	//}

	map<string, string> m{ {"z","11"},{"a","22"},{"b","dd"},{"c","00"},{"aa","11" } };
	for (auto it = m.begin(); it != m.end(); it++)
		cout << "map :" << it->first <<":"<<it->second<< endl;//自动排序

	unordered_map<string, string> um{ { "z","11" },{ "a","22" },{ "b","dd" },{ "c","00" },{ "aa","11" } };
	for (auto it = um.begin(); it != um.end(); it++)
		cout << "unordered_map:" << it->first<<":" << it->second << endl;//打印结果是乱序
	
	set<string> s{ "c","b","a","d" };
	for (auto it = s.begin(); it != s.end(); it++)
		cout << "set:"  <<*it<< endl;//自动排序

	unordered_set<string> us{ "c","b","a","d" };
	for (auto it = us.begin(); it != us.end(); it++)
		cout << "unordered_set:" << *it << endl;//和插入的顺序一致

	list<string> lst{ "c","b","a","d" };
	for (auto it = lst.begin(); it != lst.end(); it++)
		cout << "list:" << *it << endl;//和插入的顺序一致

	forward_list<string> flst{ "c","b","a","d" };
	for (auto it = flst.begin(); it != flst.end(); it++)
		cout << "forward_list:" << *it << endl;//和插入的顺序一致

	//queue<string> qu{ "c","b","a","d" };//queue和dequeue没有迭代器,也没有和前面容易一样的初始化方式,访问元素的唯一方式是遍历容器内容，并移除访问过的每一个元素
	while (!qu.empty())
	{
		cout << "queue:" << qu.front() << endl;
		qu.pop();
	}


	system("pause");
	return 0;
}
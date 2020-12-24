//STL（standard template library）标准模板库
//主要分为六大组件：容器，算法，迭代器，仿函数，适配器，空间配置器

#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<algorithm>


void myprint(int val)
{
	cout << val << endl;
}



void test01()
{
	//创建一个vector容器，数组(一般都是数组？
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器访问容器中数据
	vector<int>::iterator numbegin = v.begin();
	vector<int>::iterator numend = v.end();

	//第一种遍历
	/*while (numbegin != numend)
	{
		cout << *numbegin << endl;
		numbegin++;
	}*/

	//第二种遍历
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	for_each(v.begin(), v.end(), myprint);

}




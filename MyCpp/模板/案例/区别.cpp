#include<iostream>
#include<string>
using namespace std;

//1。普通函数调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型，可以发生隐式类型转换


void myswap1(int a, int b);

void test04()
{
	int a = 20;
	int b = 10;
	myswap1(a, b);
	cout << a << endl;
	cout << b << endl;

	//cout << myAdd<int>(a, b);
}

void myswap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

//int main() {
//	test04();
//
//	system("pause");
//	return 0;
//}
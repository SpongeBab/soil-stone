#include<iostream>
using namespace std;

//实现通用对 数组进行排序的函数
//规则从大到小
//算法 选择
//测试 char 数组、int数组


template<typename T>
void myswap(T& a, T& b);
//排序算法
template<typename T>  // typename可以用class代替
void sort(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		int max = i;  //设定最大值下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] > arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{		
			//需要先声明才能使用
			myswap(arr[max], arr[i]);
		}
	}
}

//交换函数模板
template<typename T>
void myswap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

//打印数组模板
template<typename T>
void printfArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]  ;
	}
	cout << endl;
}


void test() {
	//测试char数组
	char charArray[] = "hfsha";
	int num = sizeof(charArray) / sizeof(char);  //计算数组的长度
	//sizeof(char)是一个整型表达式,计算出运算对象在计算机的内存中所占用的字节数量，该表达式的返回值是一个整数，
	sort(charArray, num-1); //num-1去掉"\0"
	printfArray(charArray,num);
}

void test02()
{
	int numArray[] = { 4,2,5,7,8,1 };
	int num = sizeof(numArray) / sizeof(int);
	sort(numArray, num);
	printfArray(numArray, num);
}



void test03()
{
	int a = 10;
	int b = 20;
	myswap(a, b);
	cout << a << endl;
	cout << b << endl;
	/*printf(a, b);*/
}























//int main() {
//
//	test02();
//
//	system("pause");
//	return 0;
//}


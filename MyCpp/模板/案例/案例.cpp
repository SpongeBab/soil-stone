#include<iostream>
using namespace std;

//实现通用对 数组进行排序的函数
//规则从大到小
//算法 选择
//测试 char 数组、int数组

//排序算法
template<typename T>  // typename可以用class代替
void sort(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		int max = i;  //设定最大值下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			
			myswap(arr[max], arr[i]);
		}
	}
}


void test01() {
	//测试
	char charArray[] = "hfsha";
	int num = sizeof(charArray) / sizeof(char);
	myswap()
}

//交换函数模板
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test02()
{
	int a = 10;
	int b = 20;
	myswap(a, b);
	cout << a << endl;
	cout << b << endl;
	/*printf(a, b);*/
}



int main() {


	test02();

	system("pause");
	return 0;
}
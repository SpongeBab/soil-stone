#include<iostream>
#include<string>
using namespace std;

//1����ͨ�������ÿ��Է�����ʽ����ת��
//2.����ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��


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
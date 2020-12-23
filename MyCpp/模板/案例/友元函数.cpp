#include<iostream>
#include<string>
using namespace std;

template<typename T1, typename T2>
class Person;

template <typename T1, typename T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "类外" << p.m_age << p.m_Name << endl;
}


template<typename T1,typename T2>
class Person
{
	//全局函数，类内实现
	friend void printPerson(Person<T1,T2> p) 
	{
		cout << "姓名：" << p.m_Name << "年龄:" << p.m_age << endl;
	}

	//全局函数，类内定义，类外实现
	friend void printPerson2<>(Person<T1, T2> p);


public:
	Person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_Name = name;
	}
	
	//~Person();

private:
	T1 m_Name;
	T2 m_age;
};



//Person::Person()
//{
//}
//
//Person::~Person()
//{
//}

void test01()
{
	Person<string, int> p("tom", 12);
	printPerson2(p);
}

int main() {
	test01();

	system("pause");
	return 0;
}
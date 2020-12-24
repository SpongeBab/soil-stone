#include<iostream>
using namespace std;

#include<vector>


class Person
{
public:
	string  m_name;
	int m_age;

	Person(string name, int age);
	~Person();

private:

};

Person::Person(string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

Person::~Person()
{
}



void myprint(string name, int age)
{
	cout << name << endl;
}

void test02()
{
	//容器存放类，容器实例化，类实例化
	vector<Person> v;
	Person p("xxx",20);
}

int main()
{
	test02();
	system("pause");
	return 0;
}
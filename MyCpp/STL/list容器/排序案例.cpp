#include<iostream>
using namespace std;
#include<list>
#include<string>

class Person
{
public:
	Person(string name, int gae, int height);
	


	string m_Name;
	int m_age;
	int m_height;

	~Person();

private:

};

Person::Person(string name, int age, int height)
{
	this->m_Name = name;
	this->m_age = age;
	this->m_height = height;
}

Person::~Person()
{
}


//制定  排序规则，逻辑
bool comparePerson(Person& p1, Person& p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height < p2.m_height;
	}
	return p1.m_age < p2.m_age ;

}



void test()
{
	list<Person>l;

	//数据
	Person p1("刘备", 23, 180);
	Person p2("关羽", 26, 183);
	Person p3("张飞", 20, 186);
	Person p4("曹操", 24, 188);
	Person p5("赵云", 29, 189);
	Person p6("孙权", 20, 181);

	//将数据插入链表
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person>::iterator i = l.begin(); i != l.end(); i++)
	{
		//printf只能输出C语言内置的数据，
		//而string不是内置的，只是一个扩展的类，string不等于char*
		//printf_s("%s", (*i).m_Name); 
		cout << "姓名：" << (*i).m_Name << "  年龄：" << i->m_age << "  身高：" << i->m_height << endl;
	}

	//排序
	l.sort(comparePerson);
	cout << "排序后：" << endl;
	for (list<Person>::iterator i = l.begin(); i != l.end(); i++)
	{
		
		cout << "姓名：" << (*i).m_Name << "  年龄：" << i->m_age << "  身高：" << i->m_height << endl;
	}

}


int main() 
{
	test();

	system("pause");
	return 0;
}
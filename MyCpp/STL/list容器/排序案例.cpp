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


//�ƶ�  ��������߼�
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

	//����
	Person p1("����", 23, 180);
	Person p2("����", 26, 183);
	Person p3("�ŷ�", 20, 186);
	Person p4("�ܲ�", 24, 188);
	Person p5("����", 29, 189);
	Person p6("��Ȩ", 20, 181);

	//�����ݲ�������
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person>::iterator i = l.begin(); i != l.end(); i++)
	{
		//printfֻ�����C�������õ����ݣ�
		//��string�������õģ�ֻ��һ����չ���࣬string������char*
		//printf_s("%s", (*i).m_Name); 
		cout << "������" << (*i).m_Name << "  ���䣺" << i->m_age << "  ��ߣ�" << i->m_height << endl;
	}

	//����
	l.sort(comparePerson);
	cout << "�����" << endl;
	for (list<Person>::iterator i = l.begin(); i != l.end(); i++)
	{
		
		cout << "������" << (*i).m_Name << "  ���䣺" << i->m_age << "  ��ߣ�" << i->m_height << endl;
	}

}


int main() 
{
	test();

	system("pause");
	return 0;
}
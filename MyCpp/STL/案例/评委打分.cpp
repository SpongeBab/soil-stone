#include<iostream>
using namespace std;

#include<vector>


//5名选手，选手ABCDE，10个评委分别对每一名选手打分，去除最高分，最低分，取平均分
//选手类

class Person
{
public:
	Person(string name, int age);
	~Person();



	string m_name;
	string m_age;



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

void createPerson(vector<Person>&v, int num)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < num; i++)
	{
		vector<Person>
	}
}


int main()
{
	//1.创建5名选手，       vector是一个类模板，括号中应该是类
	vector<Person> v;
	createPerson(v);

	//2.给5名选手打分


	//3.显示最后的平均分

	system("pause");
	return 0;
}
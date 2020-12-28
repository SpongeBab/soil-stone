#include<iostream>
using namespace std;
#include<ctime>

#include<vector>
#include<deque>
#include<string>
#include<algorithm>

//5名选手，选手ABCDE，10个评委分别对每一名选手打分，去除最高分，最低分，取平均分
//选手类

class Person
{
public:
	Person(string name, int score);
	~Person();


	string m_name;
	int m_score;


private:

};

Person::Person(string name, int score)
{
	this->m_name = name;
	this->m_score = score;
}

Person::~Person()
{
}

void createPerson(vector<Person>&v, int num)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < num; i++)
	{
		string name = "选手";
		name += nameseed[i];

		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}

void Score(vector<Person>&v, int num)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放到deque容器中
		deque<int> d;
		for (int i = 0; i < num; i++)
		{		
			int score = rand() % 40 + 61;  //60-100
			d.push_back(score);
		}
		//sort
		sort(d.begin(), d.end());

		//拿出最高，最低
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		int average = sum / d.size();

		it->m_score = average;
	}
}

//void Average(vector<Person>& v, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		deque<
//	}
//}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_name << "平均分：" << it->m_score << endl;
	}
}



int main()
{
	srand((unsigned int)time(NULL));
	//1.创建5名选手，       vector是一个类模板，括号中应该是类
	vector<Person> v;
	createPerson(v, 5);

	//2.给5名选手打分
	
	Score(v, 10);

	//3.显示最后的平均分
	showScore(v);

	system("pause");
	return 0;
}
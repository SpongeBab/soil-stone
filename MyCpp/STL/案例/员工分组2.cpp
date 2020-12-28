#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<math.h>
#include<string>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	Worker(string name, int salary);
	~Worker();

	string m_name;
	int m_salary = 0;

private:

};

Worker::Worker(string name, int salary)
{
	this->m_name = name;
	this->m_salary = salary;
}

Worker::~Worker()
{
}

//将职工插入到集合中，生成部门id,一起插入
void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator iv = v.begin(); iv != v.end(); iv++)
	{
		int dId = rand() % 3;

		//key部门编号，value具体员工
		m.insert(make_pair(dId, *iv));
	}
}



void createWorker(vector<Worker>& v, int num)
{
	//指针必须要初始化！！！
	Worker* worker = new Worker("初始化", 1);
	string nameseed = "ABCDEFGHIJKLMNOPQR";
	for (int i = 0; i < num; i++)
	{
		
		/*char nameseed[26] = { (char)rand() % 26 + 'a' };*/
		worker->m_name= "职工";
		worker->m_name += nameseed[i];

		worker->m_salary = rand() % 10000 + 10000;  //rand() % n：等概率地获取，0 ～ n-1 中的任一元素。

		v.push_back(*worker);
	}
}


void showWorkerByGroup(multimap<int, Worker>&m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA); //定义pos
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
	}

	cout << "----------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(CEHUA);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
	}

	cout << "----------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
	}
}


void printfinfo(vector<Worker>& v)
{
	for (vector<Worker>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "姓名:" << (*i).m_name << "  工资:" << (*i).m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker> vWorker;

	createWorker(vWorker, 10);
	//分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	printfinfo(vWorker);

	//分组显示员工
	showWorkerByGroup(mWorker);

	system("pause");
	return 0;
}


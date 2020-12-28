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

//��ְ�����뵽�����У����ɲ���id,һ�����
void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator iv = v.begin(); iv != v.end(); iv++)
	{
		int dId = rand() % 3;

		//key���ű�ţ�value����Ա��
		m.insert(make_pair(dId, *iv));
	}
}



void createWorker(vector<Worker>& v, int num)
{
	//ָ�����Ҫ��ʼ��������
	Worker* worker = new Worker("��ʼ��", 1);
	string nameseed = "ABCDEFGHIJKLMNOPQR";
	for (int i = 0; i < num; i++)
	{
		
		/*char nameseed[26] = { (char)rand() % 26 + 'a' };*/
		worker->m_name= "ְ��";
		worker->m_name += nameseed[i];

		worker->m_salary = rand() % 10000 + 10000;  //rand() % n���ȸ��ʵػ�ȡ��0 �� n-1 �е���һԪ�ء�

		v.push_back(*worker);
	}
}


void showWorkerByGroup(multimap<int, Worker>&m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA); //����pos
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
	}

	cout << "----------------" << endl;
	cout << "�������ţ�" << endl;
	pos = m.find(CEHUA);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
	}

	cout << "----------------" << endl;
	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
	}
}


void printfinfo(vector<Worker>& v)
{
	for (vector<Worker>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "����:" << (*i).m_name << "  ����:" << (*i).m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker> vWorker;

	createWorker(vWorker, 10);
	//����
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	printfinfo(vWorker);

	//������ʾԱ��
	showWorkerByGroup(mWorker);

	system("pause");
	return 0;
}


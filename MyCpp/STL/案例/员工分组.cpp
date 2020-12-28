//#include<iostream>
//using namespace std;
//#include<vector>
//
//class Worker
//{
//public:
//	Worker();
//	~Worker();
//
//	string m_name;
//	int m_salary = 0;
//
//private:
//
//};
//
//Worker::Worker()
//{
//}
//
//Worker::~Worker()
//{
//}
//
//
//void createWorker(vector<Worker>&v, int num)
//{
//	string nameseed = "ABCDEFGHIJK";
//	for (int i = 0; i < num; i++)
//	{	
//		Worker worker;
//		worker.m_name = "职工";
//		worker.m_name += nameseed[i];
//
//		worker.m_salary= rand() % 10000 + 10000;
//		
//		v.push_back(worker);
//	}
//}
//
//void printfinfo(vector<Worker>&v)
//{
//	for (vector<Worker>::iterator i = v.begin(); i != v.end(); i++)
//	{
//		cout << "姓名:" << (*i).m_name <<"  工资:" <<  (*i).m_salary << endl;
//	}
//}
//
////int main()
////{
////	srand((unsigned int)time(NULL));
////	vector<Worker> vWorker;
////	createWorker(vWorker, 10);
////	printfinfo(vWorker);
////
////	system("pause");
////	return 0;
////}
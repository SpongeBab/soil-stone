#pragma once
using namespace std;
#include"worker.h"

//�̳�worker
class Employee :public worker {
public:

	//���캯��
	Employee(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();	

};
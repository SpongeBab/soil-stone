#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager:public worker
{
public:
	//���캯��
	Manager(int id, string name, int dID);


	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();


	Manager();
	~Manager();

private:

};

Manager::Manager()
{
}

Manager::~Manager()
{
}
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class boss :public worker
{
public:
	boss(int id, string name, int dID);


	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();

	boss();
	~boss();

private:

};

boss::boss()
{
}

boss::~boss()
{
}

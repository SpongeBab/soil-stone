#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager:public worker
{
public:
	//构造函数
	Manager(int id, string name, int dID);


	//显示个人信息
	virtual void showInfo();

	//获取岗位信息
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
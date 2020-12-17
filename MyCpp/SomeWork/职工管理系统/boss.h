#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class boss :public worker
{
public:
	boss(int id, string name, int dID);


	//显示个人信息
	virtual void showInfo();

	//获取岗位信息
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

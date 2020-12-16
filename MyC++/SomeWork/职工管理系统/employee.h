#pragma once
using namespace std;
#include"worker.h"

//继承worker
class Employee :public worker {
public:

	//构造函数
	Employee(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位信息
	virtual string getDeptName();	

};
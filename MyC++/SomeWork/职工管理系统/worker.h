#pragma once
#include<iostream>
using namespace std;
#include<string>


//创建抽象职工类
class worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	
	//获取岗位信息
	virtual string getDeptName() = 0;

	int m_Id;
	string m_name;
	int m_DeptID; //职工所在部门名称编号

private:

};


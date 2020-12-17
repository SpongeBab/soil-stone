#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class workermanager
{
public:
	//构造函数
	workermanager();

	//析构函数
	~workermanager();

	//展示菜单
	void Show_menu();

	//退出
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针    一个数组，里面全是指针？
	worker** m_EmpArray;

	void Add_Emp();

private:

};


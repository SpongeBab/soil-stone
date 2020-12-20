#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"manager.h"
#include"boss.h"
#include"employee.h"

#include<fstream>
#define FILENAME "empFile.txt"

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

	//添加成员
	void Add_Emp();

	//保存文件
	void save();

	//统计人数
	int get_EmpNum();

	//初始化成员
	void init_Emp();

	//显示成员
	void Show_Emp();

	void Del_Emp();

	int IsExist(int id);


	//判断文件是否为空
	bool m_Fileempty;


private:

};


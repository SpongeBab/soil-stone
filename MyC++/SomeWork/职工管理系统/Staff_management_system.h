#pragma once  // 简单理解，防止一个头文件被include两次
#include<iostream>
using namespace std;

//在头文件定义（声明）
//在cpp文件中实现

class Staff_management_system
{
public:
	//构造函数
	Staff_management_system(); //如果在类外实现，这里不能有花括号
	
	void Show_menu();

	void exitSystem();

	void addStaff();

	void deleteStaff();

	void searchStaff();

	void alternateStaff();

	void showStaff();

	void Sort();

	void deleteAll();


	~Staff_management_system();

private:

};


#pragma once  // ����⣬��ֹһ��ͷ�ļ���include����
#include<iostream>
using namespace std;

//��ͷ�ļ����壨������
//��cpp�ļ���ʵ��

class Staff_management_system
{
public:
	//���캯��
	Staff_management_system(); //���������ʵ�֣����ﲻ���л�����
	
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


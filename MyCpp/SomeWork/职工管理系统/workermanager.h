#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"manager.h"
#include"boss.h"
#include"employee.h"

class workermanager
{
public:
	//���캯��
	workermanager();

	//��������
	~workermanager();

	//չʾ�˵�
	void Show_menu();

	//�˳�
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��    һ�����飬����ȫ��ָ�룿
	worker** m_EmpArray;

	void Add_Emp();

private:

};


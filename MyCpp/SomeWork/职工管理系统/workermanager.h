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

	//��ӳ�Ա
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int get_EmpNum();

	//��ʼ����Ա
	void init_Emp();

	//��ʾ��Ա
	void Show_Emp();

	void Del_Emp();

	int IsExist(int id);


	//�ж��ļ��Ƿ�Ϊ��
	bool m_Fileempty;


private:

};


#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"manager.h"
#include"boss.h"
#include"employee.h"
<<<<<<< HEAD

#include<fstream>
#define FILENAME "empFile.txt"
=======
>>>>>>> 29f8e05eb2eb9275eec002dc8a96a7659c2b0efa

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

	//�ж��ļ��Ƿ�Ϊ��
	bool m_Fileempty;


private:

};


#pragma once
#include<iostream>
using namespace std;
#include<string>


//��������ְ����
class worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	
	//��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;

	int m_Id;
	string m_name;
	int m_DeptID; //ְ�����ڲ������Ʊ��

private:

};


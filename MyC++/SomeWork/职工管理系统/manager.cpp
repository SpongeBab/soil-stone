#include"manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_Id = dId;
}


//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "�����ţ�" << this->m_Id << endl;
	cout << "����������" << this->m_name << endl;
	cout << "�������ڲ���ID��" << this->m_DeptID << endl;
	cout << "�����λ��" << this->getDeptName() << endl;
	cout << "���boss���������,�������Ա����" << endl;
}

//��ȡ��λ��Ϣ
string Manager::getDeptName() {
	return string("����");
}
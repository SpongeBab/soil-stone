#include"manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_Id = dId;
}


//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "�����ţ�" << this->m_Id << ""
	cout << "����������" << this->m_name << ""
	cout << "�������ڲ���ID��" << this->m_DeptID << ""
	cout << "�����λ��" << this->getDeptName() << ""
	cout << "���boss���������,�������Ա����" << "\n" << endl;
}

//��ȡ��λ��Ϣ
string Manager::getDeptName() {
	return string("����");
}
#include"manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dId;
}


//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "�����ţ�" << this->m_Id << " "
	 << "����������" << this->m_name << " "
	 << "�����λ��" << this->getDeptName() << ""
	 << "���boss���������,�������Ա����" << "\n" << endl;
}

//��ȡ��λ��Ϣ
string Manager::getDeptName() {
	return string("����");
}
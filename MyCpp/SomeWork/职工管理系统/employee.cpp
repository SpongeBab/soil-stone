#include"employee.h"

//���캯��ʵ��
Employee::Employee(int id, string name, int dID) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dID;

}


void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id << " "
	 << "ְ��������" << this->m_name << " "
	 << "ְ�����ڲ���ID��" << this->m_DeptID << " "
	 << "ְ����λ��" << this->getDeptName() << " "
	 << "��ɾ�����������" << "\n" << endl;
}


string Employee::getDeptName() {
	return string("Ա��");
}
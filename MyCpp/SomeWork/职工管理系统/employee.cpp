#include"employee.h"

//���캯��ʵ��
Employee::Employee(int id, string name, int dID) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dID;

}


void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id << ""
	cout << "ְ��������" << this->m_name << ""
	cout << "ְ�����ڲ���ID��" << this->m_DeptID << ""
	cout << "ְ����λ��" << this->getDeptName() << ""
	cout << "��ɾ�����������" << "\n" << endl;
}


string Employee::getDeptName() {
	return string("Ա��");
}
#include"employee.h"

//���캯��ʵ��
Employee::Employee(int id, string name, int dID) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dID;

}


void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id << endl;
	cout << "ְ��������" << this->m_name << endl;
	cout << "ְ�����ڲ���ID��" << this->m_DeptID << endl;
	cout << "ְ����λ��" << this->getDeptName() << endl;
	cout << "��ɾ�����������" << endl;
}
}


string Employee::getDeptName() {
	return string("Ա��");
}
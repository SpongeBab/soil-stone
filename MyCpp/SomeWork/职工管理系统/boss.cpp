#include"boss.h"

boss::boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_Id = dId;
}


//��ʾ������Ϣ
void boss::showInfo() {
	cout << "�����ţ�" << this->m_Id 
		<<"����������" << this->m_name  
		<< "�������ڲ���ID��" << this->m_DeptID 
		<< "�����λ��" << this->getDeptName() 
		<< "���boss���������,�������Ա����" << "\n"<< endl;
}

//��ȡ��λ��Ϣ
string boss::getDeptName() {
	return string("����");
}



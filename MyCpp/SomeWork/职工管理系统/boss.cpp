#include"boss.h"

boss::boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dId;
}


//��ʾ������Ϣ
void boss::showInfo() {
	cout << "�ϰ��ţ�" << this->m_Id << " "
		<<"�ϰ�������" << this->m_name << " "
		<< "�ϰ��λ��" << this->getDeptName() << " "
		<< "�ϰ��������Ա����" << "\n"<< endl;
}

//��ȡ��λ��Ϣ
string boss::getDeptName() {
	return string("�ϰ�");
}



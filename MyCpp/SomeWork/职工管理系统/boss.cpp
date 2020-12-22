#include"boss.h"

boss::boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dId;
}


//显示个人信息
void boss::showInfo() {
	cout << "老板编号：" << this->m_Id << " "
		<<"老板姓名：" << this->m_name << " "
		<< "老板岗位：" << this->getDeptName() << " "
		<< "老板管理所有员工。" << "\n"<< endl;
}

//获取岗位信息
string boss::getDeptName() {
	return string("老板");
}



#include"manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_Id = dId;
}


//显示个人信息
void Manager::showInfo() {
	cout << "经理编号：" << this->m_Id << ""
	cout << "经理姓名：" << this->m_name << ""
	cout << "经理所在部门ID：" << this->m_DeptID << ""
	cout << "经理岗位：" << this->getDeptName() << ""
	cout << "完成boss分配的任务,并分配给员工。" << "\n" << endl;
}

//获取岗位信息
string Manager::getDeptName() {
	return string("经理");
}
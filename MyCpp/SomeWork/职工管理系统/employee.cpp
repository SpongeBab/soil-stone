#include"employee.h"

//构造函数实现
Employee::Employee(int id, string name, int dID) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dID;

}


void Employee::showInfo() {
	cout << "职工编号：" << this->m_Id << " "
	 << "职工姓名：" << this->m_name << " "
	 << "职工所在部门ID：" << this->m_DeptID << " "
	 << "职工岗位：" << this->getDeptName() << " "
	 << "完成经理分配的任务" << "\n" << endl;
}


string Employee::getDeptName() {
	return string("员工");
}
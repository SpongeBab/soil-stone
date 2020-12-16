#include"employee.h"

//构造函数实现
Employee::Employee(int id, string name, int dID) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptID = dID;

}


void Employee::showInfo() {
	cout << "职工编号：" << this->m_Id << endl;
	cout << "职工姓名：" << this->m_name << endl;
	cout << "职工所在部门ID：" << this->m_DeptID << endl;
	cout << "职工岗位：" << this->getDeptName() << endl;
	cout << "完成经理分配的任务" << endl;
}
}


string Employee::getDeptName() {
	return string("员工");
}
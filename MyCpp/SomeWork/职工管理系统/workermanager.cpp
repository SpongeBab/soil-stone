#include"workermanager.h"


workermanager::workermanager()
{
    //初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;

}

workermanager::~workermanager()
{
}

void workermanager::Show_menu() {
    cout << "1.添加成员" << endl;
    cout << "2.显示职工" << endl;
    cout << "3.删除职工" << endl;
    cout << "4.修改职工" << endl;
    cout << "5.查找职工" << endl;
    cout << "6.按照编号排序" << endl;
    cout << "7.清空所有信息" << endl;
    cout << "0.退出" << endl;
}

void workermanager::ExitSystem() {
    cout << "欢迎下次使用，退出。。。" << endl;
    system("pause");
    exit(0);
}

void workermanager::Add_Emp() {

}






#include "Staff_management_system.h"


Staff_management_system::Staff_management_system()
{
}

Staff_management_system::~Staff_management_system()
{
}

void Staff_management_system::Show_menu() {
    cout << "1.添加成员" << endl;
    cout << "2.显示职工" << endl;
    cout << "3.删除职工" << endl;
    cout << "4.修改职工" << endl;
    cout << "5.查找职工" << endl;
    cout << "6.按照编号排序" << endl;
    cout << "7.清空所有信息" << endl;
    cout << "0.退出" << endl;
}

void Staff_management_system::exitSystem() {
    cout << "欢迎下次使用，退出。。。" << endl;
    system("pause");
    exit(0);
}








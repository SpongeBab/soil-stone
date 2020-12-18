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
    cout << "输入添加职工的数量：" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0) {
        //添加模块
        //因为添加的人数不同，先计算添加的新空间的大小
        int newsize = this->m_EmpNum + addNum; //原来的大小+增加的大小
    }
    else {
        cout << "输入人数非法，请重新输入" << endl;
    }
}






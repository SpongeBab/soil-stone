#include"workermanager.h"


workermanager::workermanager()
{
    //��ʼ������
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;

}

workermanager::~workermanager()
{
}

void workermanager::Show_menu() {
    cout << "1.��ӳ�Ա" << endl;
    cout << "2.��ʾְ��" << endl;
    cout << "3.ɾ��ְ��" << endl;
    cout << "4.�޸�ְ��" << endl;
    cout << "5.����ְ��" << endl;
    cout << "6.���ձ������" << endl;
    cout << "7.���������Ϣ" << endl;
    cout << "0.�˳�" << endl;
}

void workermanager::ExitSystem() {
    cout << "��ӭ�´�ʹ�ã��˳�������" << endl;
    system("pause");
    exit(0);
}

void workermanager::Add_Emp() {

}






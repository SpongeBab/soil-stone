#include "Staff_management_system.h"


Staff_management_system::Staff_management_system()
{
}

Staff_management_system::~Staff_management_system()
{
}

void Staff_management_system::Show_menu() {
    cout << "1.��ӳ�Ա" << endl;
    cout << "2.��ʾְ��" << endl;
    cout << "3.ɾ��ְ��" << endl;
    cout << "4.�޸�ְ��" << endl;
    cout << "5.����ְ��" << endl;
    cout << "6.���ձ������" << endl;
    cout << "7.���������Ϣ" << endl;
    cout << "0.�˳�" << endl;
}

void Staff_management_system::exitSystem() {
    cout << "��ӭ�´�ʹ�ã��˳�������" << endl;
    system("pause");
    exit(0);
}








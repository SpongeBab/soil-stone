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
    cout << "�������ְ����������" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0) {
        //���ģ��
        //��Ϊ��ӵ�������ͬ���ȼ�����ӵ��¿ռ�Ĵ�С
        int newsize = this->m_EmpNum + addNum; //�¿ռ� = ԭ���Ĵ�С+���ӵĴ�С

        //�����¿ռ�
        //worker * [newsize]��һ��ָ�����飬��Ų�ͬ����worker��ָ�룬
        //** newspace�Ƕ���ָ��ָ�����ָ��������׵�ַ
        worker** newSpace = new worker * [newsize];  
        
        //��ԭ���ռ��µ����ݣ��������¿ռ���
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //���������
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;
            
            cout << "�������" << i + 1<< "���˵�ID��" << endl;
            cin >> id;
            /*if��id=NULL) {
            cout << "����Ƿ����������롣" << endl;
                }*/
            cout << "�������" << i + 1<< "���˵�������" << endl;
            cin >> name;
            /*if��name = NULL) {
            cout << "����Ƿ����������롣" << endl;
                }*/
            cout << "�������" << i + 1<< "���˵Ĳ��ţ�" << endl;
            cout << "1.��ͨԱ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dSelect;
            /*if��dSelect = NULL) {
            cout << "����Ƿ����������롣" << endl;
                }*/
            worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new boss(id, name, 1);
                break;
            default:
                break;
            }

            //���´�����ְ������ӵ�������
            newSpace[this->m_EmpNum + i] = worker;

            delete[] this->m_EmpArray;
            //�����¿ռ��ָ��
            this->m_EmpArray = newSpace;
            //�����µ�ְ������
            this->m_EmpNum += newsize;
            //�����ļ������浽���أ�


            //��ʾ��ӳɹ�
            cout << "�ɹ����" << endl;
        }

    }
    else {
        cout << "���������Ƿ�������������" << endl;
    }
    //������һ��
    system("pause");
    system("cls");
}






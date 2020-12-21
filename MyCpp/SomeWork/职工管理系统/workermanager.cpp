#include"workermanager.h"
#include<iostream>
#include<string>

workermanager::workermanager()
{   
    //�ļ�������
    bool m_Fileempty = false;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    

    if (!ifs.is_open()){
        //cout << "�ļ������ڡ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }

    //�ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //cout << "�ļ�Ϊ�ա�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }
    //�ļ����ڣ����Ҽ�¼����
    int num = this->get_EmpNum();
    //cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;

    //���ٿռ䣬
    //����رպ󣬰ѷ��������ռ��ͷŵ��ˣ��ٴδ���Ҫ���ٿռ䣬���ļ��е����ݶ�ȡ���ڴ��У�
    //��ͳ���ļ����м���Ա�����ٸ����鿪�ٶ�Ӧ�ռ��С���ڴ棬Ȼ���ٴ��ļ��ж�ȡ���ݱ��浽������
    this->m_EmpArray = new worker * [this->m_EmpNum];
    //���ļ��е����ݴ�������
    this->init_Emp();

    /*for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id << " "
            << "������" << this->m_EmpArray[i]->m_name << " "
            << "�������ţ�" << this->m_EmpArray[i]->m_DeptID << " ";

    }*/

    //��ʼ������
    /*this->m_EmpNum = 0;
    this->m_EmpArray = NULL;*/

}

int workermanager::get_EmpNum() {
    fstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dID;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dID) {
        num++;
    }
    return num;
}

//��ʼ��Ա��,Ϊ�˽�Ӳ���ϵ����ݼ��ص��ڴ��У�
void workermanager::init_Emp() {
    fstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dID;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dID) {
        worker* worker = NULL;
        if (dID == 1) {
            worker = new Employee(id, name, dID);
        }
        else if (dID == 2){
            worker = new Manager(id, name, dID);
        }
        else if (dID == 3) {
            worker = new boss(id, name, dID);
        }

        this->m_EmpArray[index] = worker; 
        index++;
    }
    //�ر��ļ�
    ifs.close();
}

void workermanager::Show_Emp() {
    if (this->m_Fileempty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else {
        for (int i = 0; i < m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void workermanager::Del_Emp() {
    if (this->m_Fileempty) {
        cout << "�ļ�Ϊ�ա�" << endl;
    }
    else {
        //����ְ�����ɾ��
        cout << "������ɾ����ְ��id��" << endl;

        int id = 0;
        cin >> id;
        int index = this->IsExist(id);

        if (index != -1) {
            //����ǰ�ƣ�����
            for (int i = index; i < m_EmpNum-1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            //����ͬ�����µ��ļ�
            this->save();

            cout << "ɾ���ɹ���" << endl;
        }
        else {
            cout << "ɾ��ʧ�ܡ�" << endl;
        }

    }
    system("pause");
    system("cls");
}

int workermanager::IsExist(int id) {
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            cout << "�ҵ���" << endl;
            index = i;
            break;
        }
    }
    return index;
}

//�޸�
void workermanager::Mod_Emp() {
    if (this->m_Fileempty) {
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1) {
            //����ְ��
            delete this->m_EmpArray[ret];

            int newID = 0;
            string newname ="";
            int dSelect = 0;

            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newID;

            cout << "��������������" << endl;
            cin >> newname;

            cout << "�����λ��" << endl;
            cout << "1.ְ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            
            cin >> dSelect;
            worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newID, newname, dSelect);
                break;
            case 2:
                worker = new Manager(newID, newname, dSelect);
                break;
            case 3:
                worker = new boss(newID, newname, dSelect);
                break;
            }
            //��������
            this->m_EmpArray[ret] = worker;
            cout << "�޸ĳɹ���" << endl;

            //���浽�ļ���
            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܡ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

//����
void workermanager::Find_Emp() {
    if (this->m_Fileempty) {
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������ҷ�ʽ��" << endl;
        cout << "1.��ְ����Ų��ҡ�" << endl;
        cout << "2.��ְ���������ҡ�" << endl;

        int select;
        cin >> select;

        if (select == 1) {
            // ��ְ����Ų���
            int id;
            cout << "��������ҵ�ְ�����:" << endl;

            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "�ɹ���" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "ʧ�ܡ�" << endl;
            }
        }
        else if (select==2){
            // ��ְ����������
            bool flag = false;

            string name;
            cout << "������ҵ�����:" << endl;
            cin >> name;
             
            for (int i = 0; i < m_EmpNum; i++) {
                if (name == this->m_EmpArray[i]->m_name) {
                    cout << "�ɹ���" << endl;
                    this->m_EmpArray[i]->showInfo();

                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "����ʧ�ܡ�" << endl;
            }
        }
        else {
            cout << "����Ƿ����������롣" << endl;
            
        }
        
    }

    system("pause");
    system("cls");
}








workermanager::~workermanager()
{
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}


void workermanager::save() {
    fstream ofs;
    ofs.open(FILENAME, ios::out|ios::app);

    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "   //�����������Ͳ��Ի����
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_DeptID << " " << endl;
    }
    ofs.close();
}

void workermanager::Show_menu() {
    cout << "********************" << endl;
    cout << "********0.�˳�********" << endl;
    cout << "********1.��ӳ�Ա********" << endl;
    cout << "********2.��ʾְ��********" << endl;
    cout << "********3.ɾ��ְ��********" << endl;
    cout << "********4.�޸�ְ��********" << endl;
    cout << "********5.����ְ��********" << endl;
    cout << "********6.���ձ������********" << endl;
    cout << "********7.���������Ϣ********" << endl;
    
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
            worker * worker = NULL;  
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new boss(id, name, 3);
                break;
            default:
                break;
            }

            //���´�����ְ������ӵ�������
            newSpace[this->m_EmpNum + i] = worker;
           
        }

        delete[] this->m_EmpArray;
        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        //�����µ�ְ������
        this->m_EmpNum += newsize;
        //�����ļ���־
        this->m_Fileempty = false;
        //�����ļ������浽���أ�
        this->save();
        //��ʾ��ӳɹ�
        cout << "�ɹ����" << endl;
    }
    else {
        cout << "���������Ƿ������������롣" << endl;
    }
    //������һ��
    system("pause");
    system("cls");
}
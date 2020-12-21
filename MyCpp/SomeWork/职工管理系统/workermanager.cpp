#include"workermanager.h"
#include<iostream>
#include<string>

workermanager::workermanager()
{   
    //文件不存在
    bool m_Fileempty = false;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    

    if (!ifs.is_open()){
        //cout << "文件不存在。" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }

    //文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //cout << "文件为空。" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }
    //文件存在，并且记录数据
    int num = this->get_EmpNum();
    //cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;

    //开辟空间，
    //程序关闭后，把分配的数组空间释放掉了，再次打开需要开辟空间，把文件中的数据读取到内存中！
    //先统计文件中有几个员工，再给数组开辟对应空间大小的内存，然后再从文件中读取数据保存到数组中
    this->m_EmpArray = new worker * [this->m_EmpNum];
    //将文件中的数据存入数组
    this->init_Emp();

    /*for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "职工编号：" << this->m_EmpArray[i]->m_Id << " "
            << "姓名：" << this->m_EmpArray[i]->m_name << " "
            << "所属部门：" << this->m_EmpArray[i]->m_DeptID << " ";

    }*/

    //初始化属性
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

//初始化员工,为了将硬盘上的数据加载到内存中，
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
    //关闭文件
    ifs.close();
}

void workermanager::Show_Emp() {
    if (this->m_Fileempty) {
        cout << "文件不存在或记录为空！" << endl;
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
        cout << "文件为空。" << endl;
    }
    else {
        //按照职工编号删除
        cout << "请输入删除的职工id：" << endl;

        int id = 0;
        cin >> id;
        int index = this->IsExist(id);

        if (index != -1) {
            //数据前移，覆盖
            for (int i = index; i < m_EmpNum-1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            //数据同步更新到文件
            this->save();

            cout << "删除成功。" << endl;
        }
        else {
            cout << "删除失败。" << endl;
        }

    }
    system("pause");
    system("cls");
}

int workermanager::IsExist(int id) {
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            cout << "找到。" << endl;
            index = i;
            break;
        }
    }
    return index;
}

//修改
void workermanager::Mod_Emp() {
    if (this->m_Fileempty) {
        cout << "文件为空！" << endl;
    }
    else {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1) {
            //查找职工
            delete this->m_EmpArray[ret];

            int newID = 0;
            string newname ="";
            int dSelect = 0;

            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newID;

            cout << "请输入新姓名。" << endl;
            cin >> newname;

            cout << "输入岗位：" << endl;
            cout << "1.职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            
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
            //更新数据
            this->m_EmpArray[ret] = worker;
            cout << "修改成功。" << endl;

            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败。" << endl;
        }
    }
    system("pause");
    system("cls");
}

//查找
void workermanager::Find_Emp() {
    if (this->m_Fileempty) {
        cout << "文件为空！" << endl;
    }
    else
    {
        cout << "请输入查找方式：" << endl;
        cout << "1.按职工编号查找。" << endl;
        cout << "2.按职工姓名查找。" << endl;

        int select;
        cin >> select;

        if (select == 1) {
            // 按职工编号查找
            int id;
            cout << "请输入查找的职工编号:" << endl;

            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "成功。" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "失败。" << endl;
            }
        }
        else if (select==2){
            // 按职工姓名查找
            bool flag = false;

            string name;
            cout << "输入查找的姓名:" << endl;
            cin >> name;
             
            for (int i = 0; i < m_EmpNum; i++) {
                if (name == this->m_EmpArray[i]->m_name) {
                    cout << "成功。" << endl;
                    this->m_EmpArray[i]->showInfo();

                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "查找失败。" << endl;
            }
        }
        else {
            cout << "输入非法，重新输入。" << endl;
            
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
        ofs << this->m_EmpArray[i]->m_Id << " "   //如果输入的类型不对会崩溃
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_DeptID << " " << endl;
    }
    ofs.close();
}

void workermanager::Show_menu() {
    cout << "********************" << endl;
    cout << "********0.退出********" << endl;
    cout << "********1.添加成员********" << endl;
    cout << "********2.显示职工********" << endl;
    cout << "********3.删除职工********" << endl;
    cout << "********4.修改职工********" << endl;
    cout << "********5.查找职工********" << endl;
    cout << "********6.按照编号排序********" << endl;
    cout << "********7.清空所有信息********" << endl;
    
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
        int newsize = this->m_EmpNum + addNum; //新空间 = 原来的大小+增加的大小

        //开辟新空间
        //worker * [newsize]是一个指针数组，存放不同种类worker的指针，
        //** newspace是二级指针指向这个指针数组的首地址
        worker** newSpace = new worker * [newsize];  
        
        //将原来空间下的数据，拷贝到新空间下
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //添加新数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;
            
            cout << "请输入第" << i + 1<< "个人的ID：" << endl;
            cin >> id;
            /*if（id=NULL) {
            cout << "输入非法，重新输入。" << endl;
                }*/
            cout << "请输入第" << i + 1<< "个人的姓名：" << endl;
            cin >> name;
            /*if（name = NULL) {
            cout << "输入非法，重新输入。" << endl;
                }*/
            cout << "请输入第" << i + 1<< "个人的部门：" << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;
            /*if（dSelect = NULL) {
            cout << "输入非法，重新输入。" << endl;
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

            //将新创建的职工，添加到数组中
            newSpace[this->m_EmpNum + i] = worker;
           
        }

        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新新的职工人数
        this->m_EmpNum += newsize;
        //更新文件标志
        this->m_Fileempty = false;
        //创建文件，保存到本地！
        this->save();
        //提示添加成功
        cout << "成功添加" << endl;
    }
    else {
        cout << "输入人数非法，请重新输入。" << endl;
    }
    //返回上一级
    system("pause");
    system("cls");
}
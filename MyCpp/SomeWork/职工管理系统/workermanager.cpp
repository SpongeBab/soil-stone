#include"workermanager.h"


workermanager::workermanager()
{   
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()){
        cout << "文件不存在。" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }

    //文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.is_open()) {
        cout << "文件为空。" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_Fileempty = true;
        ifs.close();
        return;
    }

    //初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;

}

workermanager::~workermanager()
{
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
        //创建文件，保存到本地！
        this->save();
        //提示添加成功
        cout << "成功添加。" << endl;

    }
    else {
        cout << "输入人数非法，请重新输入" << endl;
    }
    //返回上一级
    system("pause");
    system("cls");
}






#include<iostream>
#include "Staff_management_system.h"

using namespace std;

#include"worker.h"
#include"employee.h"
#include"workermanager.h"
#include"boss.h"



int main() {    
    //ceshi
    /*worker* worker = NULL;
    worker = new Employee(1, "zhangsan", 1);
    worker->showInfo();  */ 



    //Staff_management_system sms;
    workermanager wm;
    int choice = 0;
    
    while (true)
    {   
        wm.Show_menu();
        cout << "请输入选择：" << endl;
        cin >> choice;
        /* code */
      
        switch (choice)
        {
        case 0:  //退出系统
            wm.ExitSystem();
            break;
        case 1 /* constant-expression */:
            /* 增加职工 */
            wm.Add_Emp();
            break;
        case 2: // 显示职工
            wm.Show_Emp();
            break;
        case 3: //删除职工
            wm.Del_Emp();
            break;
        case 4: //修改职工
            wm.Mod_Emp();
            break;
        case 5: //查找职工
            wm.Find_Emp();
            break;
        case 6: //按照编号排序
            break;
        case 7: //清空所有信息
            break;
        default:
            break;
        }

    }

    system("pause");
    return 0;
}
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
        case 0:
            wm.ExitSystem();
            break;
        case 1 /* constant-expression */:
            /* 增加职工 */
            wm.Add_Emp();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        
        default:
            break;
        }

    }

    system("pause");
    return 0;
}
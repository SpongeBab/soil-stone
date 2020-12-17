#include<iostream>
#include "Staff_management_system.h"

using namespace std;

#include"worker.h"
#include"employee.h"


int main() {    
    //ceshi
    /*worker* worker = NULL;
    worker = new Employee(1, "zhangsan", 1);
    worker->showInfo();  */ 




    Staff_management_system sms;
    int choice = 0;
    
    while (true)
    {   
        sms.Show_menu();
        cout << "请输入选择：" << endl;
        cin >> choice;
        /* code */
      
        switch (choice)
        {
        case 0:
            sms.exitSystem();
            break;
        case 1 /* constant-expression */:
            /*  */
            
            
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
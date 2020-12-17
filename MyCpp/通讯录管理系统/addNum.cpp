#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

#define MAX 1000

using namespace std;

void mainMenu(){
    cout << "1.添加通讯录成员" << endl;
    cout << "2." << endl;
    cout << "3." << endl;
    cout << "4." << endl;
    cout << "5." << endl;
    cout << "6." << endl;
    cout << "0." << endl;
}

//
struct Person
{
    /* data */
    string name;
    int sex; // 1  2 
    int age;
    string phone;
    string addr;
};

struct addressbooks
{
    /* data */
    struct Person personArray[MAX];
    int m_Size;
};



void addPerson(addressbooks * myAddress){
    //
    if (myAddress->m_Size == MAX)
    {
        /* code */
        cout << "通讯录已满！" << endl;
        return;
    }
    else
    {
        /* code */
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        myAddress->personArray[myAddress->m_Size].name = name;
        //
        int sex = 0;
        cout << "请输入性别：选择" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女：" << endl;
        
        while (true)
        {
            cin >> sex ;
            if (sex == 1 || sex == 2){
                myAddress->personArray[myAddress->m_Size].sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，重新输入。" << endl;
            }
        }
        //
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        myAddress->personArray[myAddress->m_Size].age = age;

        // 
        cout << "phonenumber:" << endl;
        string phone;
        cin >> phone;
        myAddress->personArray[myAddress->m_Size].phone = phone;
        
        //
        cout << "address:" << endl;
        string address;
        cin >> address;
        myAddress->personArray[myAddress->m_Size].addr = address;

        //添加后要更新！！
        myAddress->m_Size++;  // 要在main函数中初始化为0
        cout << "success add person!" << endl;

    }
    

}







int main(){
    // 
    addressbooks myAddress;
    // 
    myAddress.m_Size = 0;
    int select = 0;
    //2.
    while (true)
    {
        /* code */
        mainMenu();
        cin >> select;
        switch (select)
        {
        case 1 /* constant-expression */:
            /*  */
            addPerson(&myAddress);
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
        case 0:
            cout << "" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    
    }
}
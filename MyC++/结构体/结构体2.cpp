#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

// 定义学生结构体
struct Student
{
    /* data */
    //name
    string sName;
    //score
    int score;
};

// struct Teacher
struct Teacher
{
    /* data */
    //name
    string tName;
    //属于老师的学生
    struct Student sArray[5];
};

// 定义一个给老师和学生赋值的函数
void allocateSpace(struct Teacher tArray[], int len){
    string nameseed = "ABCDE";
    // 给老师赋值
    for (int i = 0; i < len; i++){
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameseed[i];
        // 给学生赋值
        for (int j = 0; j < 5; j++){
            tArray[i].sArray[j].sName = "student_";
            tArray[i].sArray[j].sName += nameseed[j];

            int random = rand() % 61 + 40;

            tArray[i].sArray[j].score = random; 
        }
    }
}


void printInfo(struct Teacher tArray[], int len){
    for (int i = 0; i < len; i++){
        cout << "teacher name:" << tArray[i].tName << endl;

        for (int j = 0; j < 5; j++){
            cout << "\tstudent name:" << tArray[i].sArray[j].sName << " "
                 << "\n\tstudent score:" << tArray[i].sArray[j].score << endl;
        } 
    }
}


int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建3个老师的数组
    struct Teacher tArray[3];
    //2.给3名老师赋值，给老师的学生赋值
    int tLen = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace (tArray, tLen);
    //3.打印所有信息
    printInfo(tArray, tLen);
    system("pause");
    return 0;
}
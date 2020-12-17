#include<iostream>
#include<stdio.h>

using namespace std;

// 
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
    //
    struct Student sArray[3];
};


int main(){
    //1.
    struct Teacher tArray[3];
    //2.
    //
    tArray[0].tName = "zhangsan";
    tArray[1].tName = "lisi";
    tArray[0].sArray[0].sName = "xuesheng1";
    tArray[0].sArray[0].score = 69;
    tArray[0].sArray[1].sName = "xuesheng2";
    tArray[0].sArray[1].score = 77;
    tArray[2].tName = "wangwu";
    tArray[2].sArray[0].sName = "xuesheng1";
    tArray[2].sArray[0].score = 88;
    //3.
    cout << tArray;
    system("pasuse");
    return 0;
}
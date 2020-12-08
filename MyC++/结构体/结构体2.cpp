#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

// ����ѧ���ṹ��
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
    //������ʦ��ѧ��
    struct Student sArray[5];
};

// ����һ������ʦ��ѧ����ֵ�ĺ���
void allocateSpace(struct Teacher tArray[], int len){
    string nameseed = "ABCDE";
    // ����ʦ��ֵ
    for (int i = 0; i < len; i++){
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameseed[i];
        // ��ѧ����ֵ
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
    //���������
    srand((unsigned int)time(NULL));
    //1.����3����ʦ������
    struct Teacher tArray[3];
    //2.��3����ʦ��ֵ������ʦ��ѧ����ֵ
    int tLen = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace (tArray, tLen);
    //3.��ӡ������Ϣ
    printInfo(tArray, tLen);
    system("pause");
    return 0;
}
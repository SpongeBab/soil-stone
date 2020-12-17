#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

class Calculator
{
private:
    /* data */
public:

    int getResult(string oper){
        if (oper == "+"){
            return m_Num1 + m_Num2 ;
        }
        else if (oper == "-"){
            return m_Num1 - m_Num2 ;
        }
        else if (oper == "*"){
            return m_Num1 * m_Num2 ;
        }
        else if (oper == "%"){
            return m_Num1 % m_Num2;
        }
        return 0;     
    }
    int m_Num1;
    int m_Num2;
};

class AbstractCalculator
{
private:
    /* data */
public:
    // ���麯����û���ر��壬��Ҫ��Ϊ���Ӻ�������
    virtual int getResult(/* args */){
        return 0;
    }
    int m_Num1, m_Num2;
};


//���أ��ӷ�
class AddCalculator :public AbstractCalculator
{
private:
    /* data */
public:
    int getResult(/* args */){
        return m_Num1 + m_Num2;
    }
};


class SubCalculator :public AbstractCalculator
{
private:
    /* data */
public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};


class MulCalculator :public AbstractCalculator
{
public:
    int getResult(){
        return m_Num1 * m_Num2;
    }
};

void test01(int num1, int num2){
    Calculator c;
    c.m_Num1 = num1;
    c.m_Num2 = num2;
    cout << num1 << "+" << num2 << "=" << c.getResult("+") << endl;
}


int main(){
    int num1, num2;
    cout << "���������֣�" << endl;
    cin  >> num1 >> num2; 

    test01(num1, num2);
    system("pause");
    system("cls");
    return 0;
}
//
// Created by С����� on 2020/12/9.
//

#include <iostream>
#include <string>

using namespace std;

class CPU
{
public:
    virtual void Calculate() = 0;
};

class GPU
{
public:
    virtual void Display() = 0;
};

class Memory
{
public:
    virtual void Storage() = 0;
};

class Computer
{
public:
    //ʵ�ֵĽӿ�
    Computer(CPU * cpu, GPU * gpu, Memory * memory){
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    //�����ʵ��
    void work(){
        m_cpu->Calculate();
        m_gpu->Display();
        m_memory->Storage();
    };

    //�ṩ�����������ͷ�3���������,�������ܴ���ڶ�������
    //������û�е����Ŀ��ٿռ䣬 Ӧ���ǲ���Ҫ��������
    ~Computer(){
        if (m_cpu != nullptr){
            delete m_cpu;
            m_cpu = nullptr;
        }

        if (m_gpu != nullptr){
            delete m_gpu;
            m_gpu = nullptr;
        }

        if (m_memory != nullptr){
            delete m_memory;
            m_memory = nullptr;
        }
    }

private:
    CPU * m_cpu;
    GPU * m_gpu;
    Memory * m_memory;
};

class IntelCpu: public CPU{
public:
    void Calculate() override{
        cout << "Intel��ʼ����" << endl;
    }

};

class IntelGpu: public GPU{
public:
    void Display() override{
        cout << "Intel��ʼ��ʾ" << endl;
    }

};

class IntelMemory: public Memory{
public:
    virtual void Storage(){
        cout << "Intel��ʼ�洢" << endl;
    }

};

class LenovoCpu: public CPU
{
public:
    virtual void Calculate(){
        cout << "Lenovo��ʼ����" << endl;
    }
};

class LenovoGpu: public GPU{
public:
    virtual void Display(){
        cout << "Lenovo��ʼxianshi" << endl;
    }

};

class LenovoMemory: public Memory{
public:
    virtual void Storage(){
        cout << "Lenovo��ʼ�洢" << endl;
    }

};

void test(){
    CPU * intelCpu = new IntelCpu;
    GPU * intelGpu = new IntelGpu;
    Memory * intelMemory = new IntelMemory;

    Computer * computer01 = new Computer(intelCpu, intelGpu, intelMemory);
    computer01->work();
    delete computer01;

    Computer * computer02 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
    computer02->work();
    delete computer02;
}



int main(){
    test();

//    system("pause");
    return 0;
}

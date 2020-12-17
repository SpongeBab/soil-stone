#include<iostream>
#include<stdio.h>
#include<string>
#include<time.h>

//
using namespace std;

struct hero
{
    /* data */
    string name;
    int age;
    string sex;
};

// struct hero tt = {
//     "111",

// }

void createHero(struct hero hArray[], int num){
    string name_seed = "ABCDEFGH";
    
    for (int i = 0; i < num; i++){
        hArray[i].name = "hero_";
        hArray[i].name += name_seed[i];
        hArray[i].sex = "nan";
        int random = rand() % 61;
        hArray[i].age = random;

        // struct hero temp = {
        //     name,
        //     4,
        //     "Nan"
        // };
        // Head.next = &temp;
        // Head.next = Head.next;
    }
}


//
void bubbleSort(struct hero hArray[], int len){
    for (int i = 0;i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (hArray[j].age < hArray[j+1].age){
                struct hero temp = hArray[j];
                hArray[j] = hArray[j+1];
                hArray[j+1] = temp;
            }
        }
    }
}

void printfInfo(struct hero hArray[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << hArray[i].age 
        << " " << hArray[i].name 
        << " " << hArray[i].sex << "\t" << endl;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    //
    struct hero hArray[5];
    //
    int len = sizeof(hArray) / sizeof(hArray[0]);
    createHero(hArray, len);
    //
    bubbleSort(hArray, len); 
    //
    printfInfo(hArray, len);
    system("pause");
    return 0;
}
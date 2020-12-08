#include<iostream>
#include<stdio.h>

//
using namespace std;

struct hero
{
    /* data */
    string name;
    int age;
    string sex;
    struct hero *next;
};

// struct hero tt = {
//     "111",

// }

void createHero(struct hero Head, int num){
    string name_seed = "ABCDEFGH";
    for (int i = 0; i < num; i++){
        string name = "hero" + name_seed[i];
        struct hero temp = {
            name,
            4,
            "Nan"
        };
        Head.next = &temp;
        Head.next = Head.next;
    }
}

int main(){
    //
    struct hero Head;
    createHero(Head, 5);
    //

    //

    //
}
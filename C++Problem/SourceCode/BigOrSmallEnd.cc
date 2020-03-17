#include<iostream>
#include <cstdio>
#include<vector>
#include "memory.h"
#include "assert.h"
using namespace std;
/*
//方法一：采用字节的强制转换进行
int main(){
    short int a =0x1122;
    char b=*(char*)&a;
    if(b==0x11){
        cout<<"大端"<<endl;
    }
    else{
        cout<<"小端"<<endl;
    }
    system("pause");
    return 0;
}*/

//采用union的方法进行；
int main(int argc,char* argv[]){

    union temp
    {
        short int a;
        char b;
        /* data */
    }temp;

    temp.a=0x1234;
    if(temp.b==0x12){
        cout<<"BidEnd"<<endl;
    }else{
        cout<<"SmallEnd"<<endl;
    }

    system("pause");
    return 0;
    
}
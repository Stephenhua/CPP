#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

void Question1(){
    char buf[10]="123";
    char buf1[]="123";
    char*p="123";

    cout <<"sizeof(buf)"<<sizeof(buf)<<endl;
    cout <<"sizeof(buf1)"<<sizeof(buf1)<<endl;
    cout <<"sizeof(p)" << strlen(p) << endl;
    cout <<" sizeof(p)" << sizeof(p) << endl;
    return;
}

void Q2(){
    int a = 10;
    int &b =a;
    b =11;
    cout <<"a"<<a<<endl;
    return ;
}

class A{
    public:
        void test1(){
            cout <<"This is AAA:test1"<<endl;
            test2();
        }
        void test2(){
            cout <<"This is AAA: test2"<<endl;
        }
};

class B : public A{
    public:
        void test2(){
            cout <<"This is BBB: test2"<<endl;
        }
};
int main(int argc ,char*argv[]){
    Question1();
    Q2();

    B *p =new B;
    p->test1();
    
    system("pause");
    return 0 ;
}
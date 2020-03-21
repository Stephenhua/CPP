#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include <memory>
//#include <boost>
#include "memory.h"
#include "assert.h"
using namespace std;

//基类
class Base{
    public:
    virtual void mf1()=0;
    virtual void mf1(int);
    virtual void mf2();
    void mf3();
    void mf3(double);
    private:
    int x;
};

//派生类；
class Derived1:public Base{
    public:
    virtual void mf1();
    void mf3();
    void mf4();
   // ...
};

//下面将会产生错误

int main(){
    Derived1 d;
    int x;
    d.mf1();//正确，调用derive1：：mf1;
    d.mf1(x);//错误，因为Derived1::mf1遮掩了Base::mf1;
    d.mf2();//正确，调用Base：：mf2;
    d.mf3();//正确，调用Derive::mf3();
    d.mf3(x);//错误。因为Derived::mf3掩盖了Base：：mf3；

}


//解决办法
class Derived1:public Base{
    public:
    using Base::mf1;//让Base Class内名为mf1和mf3的所有东西
    using Base::mf3;
    virtual void mf1();
    void mf3();
    void mf4();
   // ...
};

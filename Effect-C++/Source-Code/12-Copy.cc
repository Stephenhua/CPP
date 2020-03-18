#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include "memory.h"
#include "assert.h"
using namespace std;

void logCall(const std::string & funName);
class Customer{
public:
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
    private:
    std::string name;
};

Customer::Customer(const Customer& rhs):name(rhs.name){//复制rhs的数据
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs){
    logCall("Customer copy assignment operator");//复制rhs的数据
    name=rhs.name;
    return *this;
}
class Date{

};

class Customer{
public:
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
    private:
    std::string name;
    Date lastTransation;//date类，由于添加了一个成员变量，则需要修改copying函数；
};

//基于Customer的继承
class PriorityCustomer:public Customer{
    public:
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
    private:
    int priority;
};
//default构造函数将针对name和lastTransation执行缺省的初始化动作
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs):priority(rhs.priority){//这会导致PriorityCustomer中的copy构造函数并没与指定实参传递给基类的构造函数，基对于基类的部分将会直接通过默认构造函数初始化
    logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs){
    logCall("PriorityCustomer copy assigment operator");
    priority=rhs.priority;
    return *this;
}

//外加基类函数的初始化
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs):priority(rhs.priority),Customer(rhs){
   logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs){
    logCall("PriorityCustomer copy assigment operator");
    Customer::operator=(rhs);//对基类成分进行赋值动作
    priority=rhs.priority;
    return *this;
}
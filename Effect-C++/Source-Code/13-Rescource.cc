#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include <memory>
#include <boost>
#include "memory.h"
#include "assert.h"
using namespace std;
//using namespace boost;
//基类
class Investment{

};

Investment* createInvestment();//返回指针，指向Investment继承体系内的动态分配对象。调用者有责任删除

void f(){
    Investment * pInv=createInvestment(); //调用上面的函数
    ....
    delete pInv ;//释放PINV所指对象；
}
//如果...中㛮return语句，那么控制流就无法完成 delete动作；2）如果抛出异常，同样会产生问题；

// 为了解决上一个问题： 引出了智能指针，自动释放资源；
void f1(){
    std::auto_ptr<Investment> pInv(createInvestment()); //pInv指向createInvestment返回物；
    std::auto_ptr<Investment> PInv2(pInv1);//现在pInv2指向对象， pInv1b被设置为空指针；
    pInv1=pInv2;
    //....
    //std::auto_ptr<Investment> pInv(createInvestment());
    delete pInv ;//释放PINV所指对象；
}

//采用shared_ptr 写；
void f2(){
    std::shared_ptr<Investment>;
    pInv(createInvestment);//调动factory函数，使用pInv一如既往经由shared_ptr析构函数自动删除PInv；

    std::shared_ptr<Investment>;
    pInv2(pInv);//pInv1和PINv2指向同一个对象，
    pInv1=pInv2;
    
}
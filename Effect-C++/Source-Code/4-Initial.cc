#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include "memory.h"
#include "assert.h"
using namespace std;
class PhoneNumber{};

class ABEntry{
    public:
    ABEntry(const std::string &name ,const std::string & address ,const std::list<PhoneNumber>& phones);
    private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numeTimesConsulted;
};
//此为赋值初始化，而赋值
ABEntry::ABEntry(const std::string &name ,const std::string & address ,const std::list<PhoneNumber>& phones){
    theName=name;
    theAddress=address;
    thePhones=phones;
    numeTimesConsulted=0;
}

//初始化：成员初值列
ABEntry::ABEntry(const std::string &name ,const std::string & address ,const std::list<PhoneNumber>& phones):theName(name),theAddress(address),thePhones(phones),numeTimesConsulted(0){}


成员处置列的效率要高，

方法一：
1）调用default构造函数赋初值，然后在立刻赋新值；这会导致default构造函数的工作浪费

方法二：
1）成员初列值中针对各个成员变量二设的参数，拿去作为各成员变量之构造函数的实参；只调用一次copy函数；


针对特殊的成员变量，const或者references 需要初值，不能被赋值；


初始化的顺序按照声明的次序初始化；


stactics对象，函数内的static对象称为local static 对象；
其他static对象称为non-local static对象；
在程序的结束时候将会被自动销毁；

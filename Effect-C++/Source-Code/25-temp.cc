#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include <memory>
//#include <boost>
#include "memory.h"
#include "assert.h"
using namespace std;

class WidgetImp1{
    public:


    private:
     int a,b,c;
     std::vector<double> v;
};

class Wight{
    public:
     Wight(const Wight& rhs);
     Wight& operator= (const Wight& rhs){//复制wight时，令它复制其widgetImp1对象；
           
           *pIm1=*(rhs.pIm1);
     }

    void swap(Wight& other){
        using std::swap;
        swap(pIm1,other.pIm1);//若要置换类，则需要进行置换其指针
    }
     private:
      WidgetImp1* pIm1;
};

//如果置换两个Wight对象值，需要做的是置换其pImp1指针，但默认的swap并不知道这一点，

//如何告诉swap进行置换指针，将std::swap针对Wight特化，；

namespace std//修订后的std：：swap特化版本；
{
    template<>
    void swap<Wight>(Wight& a, Wight&b){/// 对T进行特例化
        a.swap(b);//只需要置换指针就可以
    }
    
} // namespace std

/*
如果对类模板进行交换类，该如何操作？
声明一个非成员swap，让其调用成员swap，并且不再将非成员swap声明为swap的特化版，或者是重载版；
*/
namespace WidgetStuff{

    template<typename T>
    class Widget{

    };
    template<typename Y>
    void swap(Widget<T>& a,Widget<T>& b){
        a.swap(b);
    }
};
template<typename T>
void doSomething(T& obj1,T& obj2){
    using std::swap;//令std::swap在此函数中可用

    swap(obj1,obj2);//为T型对象调用最佳swap版本；
}
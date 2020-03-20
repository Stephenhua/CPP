#include<iostream>
#include <cstdio>
#include<vector>
#include <list>
#include <memory>
//#include <boost>
#include "memory.h"
#include "assert.h"
using namespace std;

//网页浏览器清除数据
class WebBrower{
    public:
     void clearCache();
     void clearHistory();
     void removeCookies();
};

//成员函数
class ClearWbeBrower{
    public:
     void ClearEverything();//调用上面的三个函数；
};


//非成员函数,采用非成员函数进行清除
void  ClearBrowser(WebBrower&  wb){
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

#include<iostream>
#include <cstdio>
#include<vector>
#include "memory.h"
#include "assert.h"
using namespace std;

//explicited的解释说明；

class Circle{
    private:
    double R;
    double X;
    double Y;
 public:
    Circle(double r):R(r){}
    Circle(int x, int y=0):X(x),Y(y){}
    Circle(const Circle& c):R(c.R),X(c.X),Y(c.Y){ }
};

 int _tmain(int argc, char* argv[])  
 {  
     Circle A=1.23;

     Circle B =1244;
       //这个算隐式调用了拷贝构造函数 
     Circle C=A;
     system("pause");
     return 0;
 }


 //加上explicited进行解释说明
 class Circle1  
{  
 public:  
     explicit Circle1(double r) : R(r) {}  
     explicit Circle1(int x, int y = 0) : X(x), Y(y) {}  
     explicit Circle1(const Circle1& c) : R(c.R), X(c.X), Y(c.Y) {}  
 private:  
     double R;  
     int    X;  
     int    Y;  
};  
   
int main(int argc, char* argv[])  
{  
//一下3句，都会报错  
//Circle A = 1.23;   
//Circle B = 123;  
//Circle C = A;  
       
//只能用显示的方式调用了  
//未给拷贝构造函数加explicit之前可以这样  
      Circle1 A = Circle1(1.23);  
      Circle1 B = Circle1(123);  
      Circle1 C = A;  
 
//给拷贝构造函数加了explicit后只能这样了  
      Circle1 A(1.23);  
      Circle1 B(123);  
      Circle1 C(A);  
      return 0;  
 }
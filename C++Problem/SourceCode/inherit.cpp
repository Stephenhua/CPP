#include <iostream>
#include <vector>

using namespace std;

class B {
    public:
        int ib ;
    public:
        B(int i):ib(i){}
        virtual void f(){ cout << " B::f()" << endl; }
        virtual void Bf() { cout <<" B:Bf()"  << endl; }
};

class B1 : virtual public B{
    public:
        int ib1;
    public:
        B1(int i = 100):B(10),ib1(i){ }
        virtual void f() {   cout <<" B1::f()" << endl;    }
        virtual void f1() {  cout <<" B1:f1" << endl;      }
        virtual void Bf1() {  cout << " B1::Bf1()" << endl; }
};

class B2 : virtual public B {
    public:
        int ib2 ;
    
    public:
        B2(int i = 10000 ):B(10),ib2(i) { }
        virtual void f() { cout <<" B2::f()" << endl;}
        virtual void f2() { cout <<" B2::f2()"  << endl; }
        virtual void Bf2() { cout <<" B2::Bf2()" << endl; }
};

class D : virtual public B1, virtual public B2{
    public:
        int id ;
    public:
        D(int i = 1000 ):B1(10),B2(10),B(10000),id(i){}
        virtual void f1() { cout <<" D::f1()" << endl; }
        virtual void f2() { cout << "D::f2()" << endl; }
        virtual void Df() { cout <<" D::Df()" << endl; }
};
int main ( int argc ,char* argv[]){
    D d;
    system("pause");
    return 0 ;
}
#include <iostream>
#include <vector>

using namespace std;

class A {
    public:
    void  x(){
        cout <<" x Address" << &(A::x) <<endl;
    }
    void  y(){
        cout <<" y Address" <<&(A::y) <<endl;
    }
    virtual float z(){
        cout <<" virtual Address" << &(A::z) <<endl;
    }
    virtual void m(){
        cout <<" virual Address m :" <<&(A::m) <<endl;
    }
    /*
    private:
     float x; 
     float y ;
     float z;
     */
};

int main(){
    A a;
    a.x();
    a.y();
    a.z();
    a.m();
    
    system("pause");
    return 0;
}
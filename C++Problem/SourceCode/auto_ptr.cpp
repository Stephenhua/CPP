#include <iostream>
#include <memory>
#include <vector>

using namespace std ;

class Test{
    public:
        int m_a;
    public:
        Test( int a = 0 ):m_a(a){}
        ~Test(){
            cout <<"Calling destructor " << endl;
        }
};


void Fun( auto_ptr<Test> p1 ){
    cout << p1->m_a <<endl;
}

int main ( int argc ,char* argv[]){
    std::auto_ptr<Test> p( new Test(5));
    Fun(p);
    cout << p->m_a <<endl;//出现异常：原因： 指针p将内存所有权交给了p1，此时p指向任意位置，所以成为了野指针；
    system("pause");
    return 0 ;
}
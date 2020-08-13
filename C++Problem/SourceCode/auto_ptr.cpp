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
    cout << p->m_a <<endl;
    system("pause");
    return 0 ;
}
#include <string.h>
#include <iostream>

using namespace std;

void test1( int a[10]){


}

void test2(int a[]){
    cout<<"sizeof a[]"<< sizeof(a) <<endl;
}

void test3(int * a){
    cout <<"sizeof *a" <<sizeof(a)<<endl;
}
int main(){
    int a[10] = {1,2,4,32};

    cout <<"sizeof a[10]" <<endl;
    cout << "1"<<a+1<<endl;
    cout << "2"<<a[1]<<endl;
    cout <<"3"<<&a[0] <<endl;
    cout << "4"<<a<<endl;
    cout << "5" << &a <<endl;

    cout << "6"<< (&a[0]+1)<<endl;

    cout <<"7"<< (a+1) <<endl;

    cout << "8" << (&a+1)<<endl;

    system("pause");
    return 0 ;
}
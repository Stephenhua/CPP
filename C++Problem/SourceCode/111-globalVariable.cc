#include <stdio.h>
#include <iostream>

using namespace std;

int a = 5 ;
int  b = 5;
int back(){
    return b ;
}

int c= 10;

int main( int argc ,char* argv[]){
    //方法一：使用指针的形式进行求解；
    int *p = &a ;
    int a = 6;
    cout << (*p) <<endl;

    //函数返回的形式；
    cout << back() <<endl;


    //采用external的关键字
    int c = 4;
    {
        extern int c;
        cout << c<< endl;
    }


    system("pause");
    return 0 ;

}
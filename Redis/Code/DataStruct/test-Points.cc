#include <iostream>
#include <stdio.h>

using namespace std;

int main( int argc ,char* argv[]){
    char * a ;
    void * b;
    int c =20;
    char * d= "32";

    b =(char* )d;

    a= (char*) b+c;

    printf("%p\n",&a);
    printf("%p\n",a);
    
    cout <<" b Address" << &b <<endl;

    cout <<" a Address" << &a <<endl;
    cout <<" a VALUE" << (*a) <<endl;


   // cout <<" b value" << (b) <<endl;

    cout <<" c" <<&c <<endl;
    cout << "c Addres" << c<<endl;

    system("pause");
    return 0 ;
 }
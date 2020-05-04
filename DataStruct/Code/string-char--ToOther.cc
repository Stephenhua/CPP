#include <string.h>
#include <iostream>

using namespace std;

int main( int argc, char* argv[]){

    char arr[] = "Hello world";

    // char[] to string ;

    string S ;

    S= arr;

    cout <<" char[] to string" <<endl;
    cout << S.c_str() <<endl;

    //char[] to char*

    char * s1= nullptr;

    s1= arr ;

    cout <<" char[] to char*"<< endl;

    cout << s1 <<endl;


    //char[] to const char* 

    const char* s2= nullptr ;

    s2 = arr;

    cout <<"char[] to const char*"<<endl;

    cout <<s2 <<endl;
    
    system("pause");
    return 0 ;
}
#include <string.h>
#include <iostream>

using namespace std;

int main( int argc, char* argv[]){

    char* c= "Hello World" ;

    //char* to string;

    string s;

    s = c;
    cout <<"char* to string "<<endl;
    cout << s<<endl;

    //char* to const char*;

    const char * s1 = nullptr ;
    s1= c;

    cout <<"char* to const char" <<endl;

    cout << s1 <<endl;


    //char* to char[]

    char arr[20] = {0};

    strncpy_s( arr, c, 20);

    cout <<" char* to char[]"<<endl;

    cout << c <<endl;

    
    system("pause");
    return 0 ;
}
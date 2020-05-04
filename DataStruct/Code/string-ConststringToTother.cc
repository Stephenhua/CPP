#include <string.h>
#include <iostream>

using namespace std;

int main( int argc, char* argv[]){
    
    const char *conststr= "Hello world ";
    /*
    const char* 转为string；
    */
    string str;

    str = conststr ;

    cout <<" const char To string" <<endl;

    cout << str <<endl;

    /*
    const char* 转为char* 
    */
   char* c= nullptr;
    c = const_cast<char*> (conststr);

    cout <<"const char* To char*"<<endl;

    cout <<c <<endl ;


    /*
    const char* 转为 char[]
    */

   char arr[20] ={0};

    strncpy_s( arr,conststr,20);

    cout <<" const char* To char[]"<<endl;

    cout <<arr <<endl;

    
    system("pause");
    return 0 ;

}
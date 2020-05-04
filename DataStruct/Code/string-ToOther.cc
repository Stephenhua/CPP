#include <string.h>
#include <iostream>

using namespace std;

int main( int argc, char* argv[]){

    //string转 const char* ；
    string str = "HelloWorld";

    const char* conststr = nullptr ;

    conststr = str.c_str();

    cout <<str.c_str() <<endl;

    cout <<conststr <<endl;


    //string 转char*;

    const char* char_str = str.c_str();

    char* arr = const_cast<char*>(char_str);


    cout<<"string To char* L" <<endl;

    cout << arr <<endl;


    //3|string转为char[];

    char arrac[20] = {0};
    for(int i=0 ;i<str.size() ;i++){
        arrac[i] = str[i];
    }

    cout<<" string To char[] "<<endl;
    cout << arrac <<endl;
 
    system("pause");
    
    return 0;

}
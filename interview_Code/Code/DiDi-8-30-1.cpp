/*
题目：在字符串中找出4位整数；
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Find4Int( string str) {

    int maxLen = -1;
    int start = 0 ;
    int tempIndex = 0 ;

    for(int i = 0 ; i< str.length() ;i ++){
        if( str[i] >'0' && str[i] <= '9'){
            int tempLen = 0 ;
            tempIndex = i ;
            while( str[i] >='0' && str[i] <= '9'){
                i++;
                tempLen++;
            }
            if( tempLen == 4 ){
                start= tempIndex ;
                return start;
            }
        }   
    }
    return -1 ;
}

int main( int argc, char* argv[]){
    string s = "abcd0123d12345fs";
    int res = Find4Int(s);
    cout << res << endl;
    system("pause");
    return 0 ;
}
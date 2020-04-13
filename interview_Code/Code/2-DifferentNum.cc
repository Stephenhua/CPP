#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
#include <assert.h>
using namespace std;

/*
编写一个函数求给定两个正整数的二进制表示中不同位数的个数。
例如给定数字 8 和 9，8 的二进制表示是 1000，9 的二进制表示是 1001，
则不同位数的个数为 1

*/
int CountNum( int num1, int num2){
    int temp = num1^ num2;

    int count = 0 ;

    while(temp){
        count++;
        temp = temp &(temp-1);
    }
    return count ;
}

int main( int argc,char* argv[]){
    int num1= 9 ;
    int num2 = 8 ;

    int result = CountNum( num1 , num2);
    
    cout <<" num count is:"<<result <<endl;

    system("pause");

    return 0;
}
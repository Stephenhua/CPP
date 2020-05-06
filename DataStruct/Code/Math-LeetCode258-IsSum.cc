#include <vector>
#include <iostream>
#include <string>

using namespace std;


//方法一：暴力解法；
int addDigits( int num){

    if(num <10 ){
        return num ;
    }
    int  sum = 0 ;
    while (num>=10)
    {
        int sum  = 0 ;

        while( num){
            sum += num%10;
            num /= 10;
        }
        num = sum ;
    }

    return num ;   

}
/*
找规律:假设一个三位数整数n=100*a+10*b+c,变化后addn=a+b+c；
两者的差值n-addn=99a+9b，差值可以被9整除，说明每次缩小9的倍数
那么我们可以对res=num%9，若不为0则返回res，为0则返回9
*/
int addDigits1( int num){
    if(num > 9){
        num = num%9;
        if( num == 0){
            return 9 ;
        }
    }
    return num ;
}

int main( int argc ,char* argv[]){

    int num ;
    cin >>num ;
    int result = addDigits1(num);
    cout <<" result  "<<result <<endl;

    system("pause");
    return 0 ;
}
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
题目：两个大数相加
链接：https://blog.csdn.net/fesdgasdgasdg/article/details/80953829?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1

步骤：
1）两个字符串进行反转；
2）对于两个数进行相加；
3）注意进位；
*/
string BigAdd( string str1, string str2){

    int lenght_s1 = str1.length();
    int length_s2 = str2.length();

    if( str1.empty()){
        return str2;
    }

    if(  str2.empty()){
        return str1;
    }

    int maxLength = max( lenght_s1 ,length_s2);

    int minLength = min( length_s2 , lenght_s1);

    string result;

    reverse(str1.begin() ,str1.end());
    reverse( str2.begin() ,str2.end() );

    //进位；
    int carry = 0;
    //当前位上面的数值；
    int currentNum = 0 ;

    int i= 0;

    for(;i<minLength ;i++){

        currentNum = str1[i]+str2[i] - 2*'0' +carry ;

        //获取进位；
        carry = currentNum/10;

        //最终值；
        currentNum = currentNum%10;

        //将int转换为string类型；
        result +=to_string(currentNum);
        
        cout <<result <<endl;
    }

    if( str1.length() < str2.length()){

        str1 = str2;
    }

    for(; i<str1.length() ; i++){

        //分别获取两个字符对应的字面数值，然后相加，在进位；

        currentNum = str1[i] - '0'+ carry;

        carry =currentNum/10;

        currentNum = currentNum%10;

        result += to_string(currentNum) ;
    }

    if( carry > 0){
        result[maxLength]=carry;
    }

    reverse( result.begin() ,result.end());

    return result;
}

int main( int argc ,char* argv[]){
    string str1 = "1234566";
    string str2 = "342452";

    string result = BigAdd(str1, str2);

    cout <<" result "<< result <<endl;

    system("pause");

    return 0 ;
}
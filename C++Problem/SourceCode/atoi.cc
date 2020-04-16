#include<iostream>
#include <cstdio>
#include<vector>
#include <cmath>
#include "memory.h"
#include "assert.h"
using namespace std;
#define SIZE 100

int _atio_1(char *str){
    if(str==NULL){
        cout<<"NULL input"<<endl;
        exit(0);
    }
    int sign=0;//设置标志位；判断收个非空字符判断符号;
    int IntNumber=0;//设置最大值得
    while(*str){
        if(sign==0){
            if(*str=='-'){
                sign=-1;
                str++;
            }else if(*str=='+'){
                sign=1;
                str++;
            }else if(*str>='0' && *str<='9'){
                sign=1;
            }else{
                cout<<"Invalid input"<<endl;
                exit(0);
            }          

        }else if (*str>='0' && *str<='9')
            {
                IntNumber=IntNumber*10+*str-'0';
                ++str;
                /* code */
            }else{
                cout<<"INvalid input"<<endl;
                exit(0);
            }
    }
}

//加上溢出处理，并且对10进制、16进制以及8进制进行转换；

bool IsNotFull=true;
bool IsDigit=true;
bool IsNotOverFlow =true;

int IsOverflow(unsigned long int IntNumber,int sign){
    
    unsigned long int MaxPosition=(long int) pow((float)2,(int)(8*sizeof(long int)-1))-1;

    if((sign==1) && !(IntNumber>0 && IntNumber<=MaxPosition)){
        IsNotOverFlow=true;
        return 1;
    }
    if((sign==-1) && !(IntNumber>0&& IntNumber<=(MaxPosition+1))){
        IsNotOverFlow=true;
        return -1;
    }
    return 0;
}

long int _atoi_2(char* str){
    if(str==NULL){
        IsNotFull=false;
        return 0;
    }

    int sign=0;
    unsigned long int MaxPositive= (long int) pow((float)2,(int)(8*sizeof(long int)-1))-1;
    unsigned long int IntNumber=0;//要表示最小负数，须用unsigned long int，若用long int，其范围为-2^31到2^31 -1,不能表示2^31
    unsigned int base =0;

    while(*str){
        while(' '==*str ||*str=='\t'){
            ++str;
        }
        if(sign==0){
            if(*str=='+'){
                sign=1;
                ++str;
            }else if(*str=='-'){
                sign=-1;
                ++str;
            }else if(isdigit(*str)){//主要用于检查其参数是否为十进制数字字符。
                sign=1;
            }
        }else{
            if(isdigit(*str)){
                if(base==0){
                    if(*str=='0'&& ('x'==*(str+1) || 'X'==*(str+1))){
                        base=16;
                        str=str+1;
                    }
                    else if(*str=='0'&& !('x'==*(str+1) || 'X'==*(str+1))){
                        base =8;
                        str=str+1;
                    }else{
                        base=10;//不进行更新；
                    }
                }else{
                    IntNumber=IntNumber*10+*str-'0';
                    if(IsOverflow(IntNumber,sign)==1){
                        return MaxPositive;
                    }
                    
                    if(IsOverflow(IntNumber,sign)==-1){
                        return -(MaxPositive+1);
                    }

                    ++str;
                }
            }
            else{
                IsDigit=false;
                return 0;
            }
        }

    }
        return (sign*IntNumber);

}

//方法三:

//对不同的进制，判断的范围不同
//对16进制0123456789ABCDEF
//对8进制01234567
//对10进制0123456789
long int _atoi_3(char *str)
{
    bool IsNotFull=true;
    if (NULL == str)    //输入合法性检查
    {
        IsNotFull = false;
        return 0;
    }

    int sign = 0;
    unsigned long int IntNumber = 0;   //要表示最小负数，须用unsigned long int，若用long int，其范围为-2^31到2^31 -1,不能表示2^31
    unsigned long int MaxPositive = (long int) pow( (float)2,(int)( 8*sizeof(long int) - 1 ) ) - 1; 
    unsigned int base = 0;

    while ( *str )
    {
        while ( ' ' == *str || '\t' == *str)     //忽略前导的空格或TAB
            ++str;

        if (0 == sign)  //判断数值的符号
        {
            if ('+' == *str)
            {
                sign = 1;
                ++str;
            }
            else if('-' == *str)
            {
                sign = -1;
                ++str;
            }
            else if ( isdigit(*str) )
            {
                sign = 1;
            }
            else
            {
                IsDigit = false;
                return 0;
            }
        }
        else
        {    
            if (0 == base)    //判断数值的进制
            {
                if ( '0' == *str && ( 'x' == *(str + 1) || 'X' == *(str + 1) ) )
                {
                    base = 16;
                    str = str + 2;
                }
                else if ( '0' == *str && !( 'x' == *(str + 1) || 'X' == *(str + 1) ) )
                {
                    base = 8;
                    str = str + 1;
                }
                else
                {
                    base = 10;   //不更新str
                }
            }
            else
            {
                if (10 == base)//直接进行10进制的相称与相减
                {
                    if ( isdigit(*str) )
                    {
                        IntNumber = IntNumber * base + *str - '0';
                        if (IsOverflow (IntNumber,sign) == 1)
                        {
                            return MaxPositive;
                        }

                        if (IsOverflow (IntNumber,sign) == -1)
                        {
                            return -( ( MaxPositive + 1) );
                        }
                        ++str;
                    }
                    else
                    {
                        IsDigit = false;
                        return 0;
                    }
                }
                else if (16 == base)//16进制
                {
                    if ( isdigit(*str) || (*str >= 'a'&& *str <= 'f') || (*str >= 'A'&& *str <= 'F'))
                    {
                        if ( isdigit(*str))
                        {
                            IntNumber = IntNumber * base + *str - '0';
                        }
                        else if (*str >= 'a'&& *str <= 'f') 
                        {
                            IntNumber = IntNumber * base + *str - 'a' + 10;
                        }
                        else if (*str >= 'A'&& *str <= 'F')
                        {
                            IntNumber = IntNumber * base + *str - 'A' + 10;
                        }

                        if (IsOverflow (IntNumber,sign) == 1)//判断是否溢出
                        {
                            return MaxPositive;
                        }

                        if (IsOverflow (IntNumber,sign) == -1)
                        {
                            return -( ( MaxPositive + 1) );
                        }
                        ++str;
                    }
                    else
                    {
                        IsDigit = false;
                        return 0;
                    }
                }
                else
                {
                    if ( *str>= '0' && *str <= '7')//只有0~7之间
                    {
                        IntNumber = IntNumber * base + *str - '0';
                        if (IsOverflow (IntNumber,sign) == 1)
                        {
                            return MaxPositive;
                        }

                        if (IsOverflow (IntNumber,sign) == -1)
                        {
                            return -( ( MaxPositive + 1) );
                        }
                        ++str;
                    }
                    else
                    {
                        IsDigit = false;
                        return 0;
                    }
                }
            }    
        }
    }

    return (sign * IntNumber);   //如果为空串，也即第一个字符即为\0，返回值为0
}


//测试程序
int main()
{
    char str[SIZE];

    cout<<"size of type int is : "<<sizeof(int)<<endl;   //4
    cout<<"size of type long int is : "<<sizeof(long int)<<endl;    //4
    cout<<"size of type float is : "<<sizeof(float)<<endl;    //4
    cout<<"size of type long double is : "<<sizeof(long double)<<endl;    //8
    cout<<"test _atoi_1..."<<endl;
    cout<<"please enter the string :"<<endl;
    while(cin>>str)
    {
        cout<<"the string is :"<<str<<endl;
        cout<<"the int number is : "<<_atio_1(str)<<endl;
        cout<<"please enter the string :"<<endl;
    }

    cin.clear();
    cin.sync();
    cout<<endl;

    //test _atoi_2...
    cout<<"test _atoi_2..."<<endl;
    cout<<"please enter the string :"<<endl;
    while(cin>>str)
    {
        cout<<"the string is :"<<str<<endl;
        cout<<"the int number is : "<<_atoi_2(str)<<endl;
        cout<<"please enter the string :"<<endl;
    }

    cin.clear();
    cin.sync();
    cout<<endl;

    //test _atoi_3...
    cout<<"test _atoi_3..."<<endl;
    cout<<"please enter the string :"<<endl;
    while(cin>>str)
    {
        cout<<"the string is :"<<str<<endl;
        cout<<"the int number is : "<<_atoi_3(str)<<endl;
        cout<<"please enter the string :"<<endl;
    }
    system("pause");
    return 0;
}
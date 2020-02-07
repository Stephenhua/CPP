#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <stdafx.h>
#include <string.h>

using namespace std;
void ReplaceBlank(char string[], int length){
    if(string ==nullptr || length<0)
        return ;

    int originalLength =0;
    int numberOfBank =0;
    int i = 0;
    while (string[i]!='\0'){
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBank;
        ++i;
    }

    int newLength=originalLength+ 2* numberOfBank;
    if(newLength>length){
        return ;
    }

    int indexOfOrignal =originalLength;
    int indexOfNew = newLength;
    while(indexOfOrignal >=0 && indexOfNew>indexOfOrignal){

        if(string[indexOfOrignal]==' '){
            string[indexOfNew--]='0';
            string[indexOfNew--]='2';
            string[indexOfNew--]='&';
            
        }else{
            string[indexOfNew]=string[indexOfOrignal];
        }

        --indexOfOrignal;
    }


}


//====================================测试代码=======================================
void Test(char * testName ,char str[], int length , char expected[]){
    if(testName!= nullptr){
        printf("%s  begins:", testName);
    }
    ReplaceBlank(str,length);

    if(expected == nullptr &&str ==nullptr){
        printf("passed.\n");
    }
    else if (expected == nullptr && str!= nullptr)
    {
        /* code */
        printf("failed.\n");
    }
    else if(strcmp(str, expected)==0){
        printf("passed.\n");
    }
    else{
        printf("failed. \n");
    }
    
}
//空格在中间
void Test1(){
    const int length= 100;
    char str[length]="hello world";
    Test("Test1", str,length,"hello%20world");
}

//空格在最前
void Test2(){
    const int length= 100;
    char str[length]=" helloworld";
    Test("Test2", str,length,"%20helloworld");
}


//连续两个空格
void Test3(){
    const int length= 100;
    char str[length]="hello  world";
    Test("Test3", str,length,"hello%20%20world");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}
// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    Test7();
    Test8();
    Test9();

    return 0;
}
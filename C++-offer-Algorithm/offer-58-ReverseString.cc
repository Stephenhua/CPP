
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include <cstdio>
#include <stdexcept>
#include "Lsit.h"
#include "BinaryTreeNode.h"
//#include <exception>
using namespace std;

/*
题目：
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

思路：
方法一：
可以看出，如果需要将str左移n位，其实就是将str的前n个字符挪到str的尾部，
所以考虑substr获取str的前n个字符str1和剩余的字符str2，返回的字符串res则为两个子串的拼接res = s2 + s1。
方法二：
1)翻转字符串，做三次翻转字符串既可以实现；
*/

//方法一：
string LeftRoateString_1(string str,int n){
    if(n==0 || str.size()==0){
        return str;
    }
    
    if(n>=str.size()){//进行取余运算；
        n%=str.size();
    }

    string str1=str.substr(0,n);
    string str2=str.substr(n);
    string res=str1+str2;
    return res;
}

//方法二：
void Reverse(char *pBegin,char *pEnd){
    if(pBegin==nullptr || pEnd==nullptr){
        return ;
    }
    while(pBegin<pEnd){
        char temp=*pBegin;
        *pBegin=*pEnd;
        *pEnd=temp;

        pBegin++;
        pEnd--;
    }
}


char * LeftRoateString(char *pStr,int n){
    if(pStr!=nullptr){
        int nLength=static_cast<int>(strlen(pStr));//将字符串长度变为int类型；
        if(nLength>0&& n>0 && n<nLength){
            char* pFirstLength=pStr;
            char* pFirstEnd=pStr+n-1;
            char* pSecondStart=pStr+n;
            char* pSecondEnd=pStr+nLength-1;

            //翻转字符前n个字符；
            Reverse(pFirstLength,pFirstEnd);
            //翻转字后面的字符；
            Reverse(pSecondStart,pSecondEnd);
            //翻转整个字符串；
            Reverse(pFirstLength,pSecondEnd);
        }
    }
    return pStr;
}

//测试代码：

// ====================测试代码====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRoateString(input, num);

    if((input == nullptr && expectedResult == nullptr) || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    system("pause");
    return 0;
}
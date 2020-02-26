#include <iostream>
#include <vector>
#include <string>
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
题目：数组中唯一只出现一次的数字；
除一个数字只出现一次以外，其他数字都出现三次；
解决方法：将所有出现三次的数字的二进制表示的每一位都加起来。如果某一位的和能够被3整除，那么那个只出现一次的数字二进制表示中对应的
那一位是0，否则就是1；
时间的复杂度为：O(nlongn);空间复杂度为：O(n);

*/
int FindNumberAppearOnce(int numbers[],int length){
    if(numbers == nullptr || length<=0){
        throw new std::logic_error("Invalid Input");
    }


    int bitSum[32]={0};
    for(int i=0;i<length;++i){
        int bitMask=1;
        for(int j=31;j>=0;--j){
            int bit=numbers[i]&bitMask;
            if(bit!=0){
                bitSum[j]+=1;             
            }
            bitMask=bitMask<<1;
        }
    }

    int result=0;
    for(int i=0;i<32;++i){
        result=result<<1;
        result+=bitSum[i]%3;
    
    }
    return result;
}

void Test(const char *testName ,int numbers[],int length,int expected){
    int result =FindNumberAppearOnce(numbers,length);
    if(result ==  expected){
        cout<<"Passed"<<endl;

    }else{
        cout<<"Failed"<<endl;
    }
}

// 所有数字都是正数，唯一的数字是最小的
void Test1()
{
    int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int expected = 4;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字是最大的
void Test3()
{
    int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
    int expected = 7;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是负数
void Test4()
{
    int numbers[] = { -10, 214, 214, 214 };
    int expected = -10;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是负数
void Test5()
{
    int numbers[] = { -209, 3467, -209, -209 };
    int expected = 3467;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 重复的数字有正数也有负数
void Test6()
{
    int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
    int expected = 1023;
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是负数
void Test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int expected = -1023;
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是0
void Test8()
{
    int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
    int expected = 0;
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是0
void Test9()
{
    int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
    int expected = 3467;
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    system("pause");
    return 0;
}
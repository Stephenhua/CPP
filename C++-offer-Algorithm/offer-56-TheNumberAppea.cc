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
#include "Lsit.h"
#include "BinaryTreeNode.h"
using namespace std;

/*
题目：数组中出现一次的两个数字

时间复杂度：O(n)
空间复杂度：O(1)

解题思路：采用异或的方法进行求解
步骤：
1）从头到尾一次异或数组中的每个数字；
2）将以第n位是不是1为标准吧原数组中的数字分成两个子数组；
第一个自述中每个数字的第n为都是1,而第二个子数组的每个数字的第为都是0；
所以两个相同的数字的任意一位都是相同的，我们不能把两个相同的数字分配到两个数组中，从而就可以更快的实现；

*/

unsigned int FindFistBits(int num){
    int indexBit=0;
    while(((num&1)==0)&& (indexBit <8*sizeof(int)))
    {
        num=num>>1;//向右移一位；
        ++indexBit;
    }

    return indexBit;
}

bool IsBit(int num,unsigned int indexBit){
    num=num>>indexBit;
    return (num&1);
}

void  FindNumAppearenceOnce(int data[],int length,int *num1,int *num2){

    if(data == nullptr || length<2){
        return ;
    }

    int reslut=0;
    for(int i=0;i<length;i++){
        reslut^=data[i];
    }
    unsigned int indexOfIt=FindFistBits(reslut);
    *num1=0;
    *num2=0;

    for(int j=0;j<length;j++){
        if(IsBit(data[j],indexOfIt)){
            *num1^=data[j];
        }else{
            *num2^=data[j];//用于存储单次出现的值；
        }
    }

}


// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumAppearenceOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = { 4, 6 };
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = { 4, 6, 1, 1, 1, 1 };
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    system("pause");
    return 0;
}

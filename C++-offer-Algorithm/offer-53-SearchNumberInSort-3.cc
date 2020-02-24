#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include "Lsit.h"

using namespace std;

/*
题目：数组中数值和下标相等的元素
方法：采用二分法查找算法进行优化，
讲解：如果第i个数字的值大于i,则其右边的数字都大于对应的下标，则直接从其左侧进行查找。如果小的话，则从右侧进行查找
*/

int GetNumberSameAsIndex(const int *numbers ,int length){
    if(numbers == nullptr || length<=0){
        return -1;
    }
    int left=0;
    int right=length-1;
    while(left<=right){
        int midddle=(left+right)>>1;
        if(numbers[midddle]==midddle){
            return midddle;
        }
        if(numbers[midddle]>midddle){
            right=midddle-1;
        }else{
            left=midddle+1;
        }
    }

    return -1;
}

// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
    if(GetNumberSameAsIndex(numbers, length) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

void Test1()
{
    int numbers[] = { -3, -1, 1, 3, 5 };
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test2()
{
    int numbers[] = { 0, 1, 3, 5, 6 };
    int expected = 0;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test3()
{
    int numbers[] = { -1, 0, 1, 2, 4 };
    int expected = 4;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test4()
{
    int numbers[] = { -1, 0, 1, 2, 5 };
    int expected = -1;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test5()
{
    int numbers[] = { 0 };
    int expected = 0;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test6()
{
    int numbers[] = { 10 };
    int expected = -1;
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test7()
{
    Test("Test7", nullptr, 0, -1);
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
    system("pause");
    return 0;
}
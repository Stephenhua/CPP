#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include <cstdio>
#include <stdexcept>
#include <list>
#include "Lsit.h"
#include "BinaryTreeNode.h"
using namespace std;
/*
题目：股票的最大利润；
例如，一只股票在某些时间节点的价格为{9,11,8,5,7,12,16,14}。
如果我们能在价格为5的时候买入并在价格为16时卖出，则能获得最大的利润为11.

解决方法：
1）采用遍历的形式进行求解，时间复杂度为O(n)；
2）保存最小的值，保存最大的差值；

//代码测试时考虑的因素；
价格递增，价格递减
价格不变、数组的个数为2、4、6、8
*/

int MaxDifferent(const int* numbers, int  length){
    if(numbers == nullptr && length<2){
        return 0;
    }

    int min =numbers[0];
    int maxValue=numbers[1]-min;

    for(int i=2;i<length;++i){
        if(numbers[i-1]<min){
            min=numbers[i-1];
        }
        int currentDiff=numbers[i]-min;
        if(currentDiff>maxValue){
            maxValue=currentDiff;
        }
    }
    return maxValue;
}

//代码测试

void Test(const char * testName ,const int * numbers ,unsigned int length, int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }

    if(MaxDifferent(numbers,length)==expected){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

// 价格递增
void Test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

// 价格递减
void Test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

// 价格全部相同
void Test4()
{
	int numbers[] = { 16, 16, 16, 16, 16 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), 0);
}

void Test5()
{
    int numbers[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), 11);
}

void Test6()
{
    int numbers[] = { 2, 4 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), 2);
}

void Test7()
{
    int numbers[] = { 4, 2 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), -2);
}

void Test8()
{
	Test("Test8", nullptr, 0, 0);
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


    system("pause");
    return 0;
}
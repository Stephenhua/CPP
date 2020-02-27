
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
题目：扑克牌的顺子；
思路：
1）将数组进行排序；
2）统计数组中0的个数；
3）统计排序后额数组相邻数字之间的空缺总数；

*/
int Compare(const void * arg1,const void * arg2){
    return *(int*)arg1 -*(int*)arg2;
}

bool IsContinuous(int *numbers,int length){
    if(numbers==nullptr || length<1){
        return false;
    }
    qsort(numbers,length,sizeof(int),Compare);

    int numebrOfZero=0;
    int numberOfGap=0;

    //统计数组中0的个数

    for(int i=0;i<length&&numbers[i]==0;++i){
        ++numebrOfZero;
    }

    //统计数组中的间隔数目

    int small = numebrOfZero;
    int big=small+1;

    while(big<length){
        //两个数字相等，则不可能是顺子；
        if(numbers[small]==numbers[big]){
            return false;
        }

        numberOfGap+=numbers[big]-numbers[small]-1;
        small=big;
        ++big;
    }
    return (numberOfGap>numebrOfZero)?false:true;
}

//测试代码
void Test(char* testName, int* numbers, int length ,bool expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }

    if(IsContinuous(numbers,length)){
        cout<<"passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}


void Test1(){
    int numbers[] ={1,3,2,5,4 };
    Test("Test1",numbers,sizeof(numbers)/sizeof(int),true);
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", nullptr, 0, false);
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
    Test10();
    Test11();
    Test12();
    system("pause");
    return 0;
}



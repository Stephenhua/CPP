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
题目二：0~n-1中缺失的数字
采用和方法一种的方法一样，采用二分法的形式进行查找，如果中间数字和标号相同的话，那么直接查找后半部分，如果中间数字和标号不同的话，则需要查找前半部分的数字

*/

int GetMissingNumbre(const int *numbers, int length){
    if(numbers==nullptr || length<=0){
        return -1;
    }

    int left=0;
    int right=length-1;
    while(left<=right){
        int middle= (right+left)/2;
        if(numbers[middle]!=middle){
            if(middle==0||numbers[middle-1]==middle-1){
                return middle;
            }

            right=middle-1;
        }else
        {
            left=middle+1;
        }
        
    }

    if(left==length){
        return length;
    }

    return -1;
}

void Test(const char* testName,int numbers[],int length,int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }

    int result=GetMissingNumbre(numbers,length);
    if(result==expected){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

//缺失第一个数字0
void Test1(){
    int numbers[]={1,2,3,4,5};
    int expected=0;
    Test("Test1",numbers,sizeof(numbers)/sizeof(int),expected);
}



// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int expected = 5;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
    int expected = 3;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    int numbers[] = { 1 };
    int expected = 0;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    int numbers[] = { 0 };
    int expected = 1;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
    int expected = -1;
    Test("Test6", nullptr, 0, expected);
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
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
/*
解决方法：采用前后指针，从开始和末端进行求和，这样速度快；
*/

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
#include "list.h"
#include "BinaryTreeNode.h"
//#include <exception>
using namespace std;

bool FindNumWithSum(int data[],int length,int sum,int *num1,int *num2){
    bool found=false;
    if(length<1||num1 ==nullptr || num2 ==nullptr ){
        return found;
    }
    int ahead =length-1;
    int behind=0;

    while(ahead>behind){
        long long curSum=data[ahead]+data[behind];

        if(curSum==sum){
            *num1=data[behind];
            *num2=data[ahead];
            found=true;
            break;
        }
        else if(curSum>sum){
            ahead--;
        }else{
            behind++;
        }
    }
    return found;

}

void Test(const char * testName ,int data[],int length,int sum,int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }
    int num1,num2;
    int result=FindNumWithSum(data,length,sum,&num1,&num2);
    if(result==expected){
        if(result){
            if(num1+num2==sum){
                cout<<"Passed"<<endl;
            }else{
                cout<<"Failed"<<endl;
            }
        }else{
            cout<<"Passend"<<endl;
        }
    }else{
        cout<<"Failed"<<endl;
    }
}


// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    system("pause");

    return 0;
}

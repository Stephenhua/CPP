// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。
/*

解题方法：对于求解连续序列的和应用一个小技巧，通常可以使用循环求解一个连续的序列的和；
由于每次操作和前面的大部分都相同，所以每次操作只是增加或者减少一个数字，从而求得序列的和；
这样可以减少不必要的运算，提高代码的效率
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

void PrintContinousSequence(int small ,int big){
    for(int i=small;i<=big;i++){
        cout<<"value"<<i;
    }
    cout<<endl;
}

void FindContinousSequence(int sum){
    if(sum<3){
        return ;
    }
    int small=1;
    int big=2;
    int mid=(1+sum)/2;


    while(small < mid){

        int cur = (big-small+1)*(big+small)/2;//等差数列求和

        if(cur==sum){
            PrintContinousSequence(small, big );
            small++;
        }
        else if(cur>sum){
            small++;
        }else if(cur < sum){
            big++;
        }
    }
}

//测试代码
void Test(const char * testName,int sum){
    if(testName != nullptr){
        cout<<testName<<","<<sum<<endl;
    }
    FindContinousSequence(sum);
}



int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    system("pause");
    return 0;
}

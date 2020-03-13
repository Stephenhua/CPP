/*

题目：数组中重复的数字

*/
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
#include <cstdio>
#include "Lsit.h"
#include "BinaryTreeNode.h"
using namespace std;
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

/*
//方法一：先进性排序，然后进行遍历，从而得到数组中是否存在相同的数；

//时间复杂度：O(nlogn)；空间复杂度为：O(n)；

bool duplicate1 (int numbers[],int length ,int *duplicate)
{
    if(numbers==nullptr || length<=0){
        return false;
    }
    for(int i=0;i<length;i++){
        if(numbers[i]<0 ||numbers[i]>length-1){
            return false;
        }
    }

    numbers.sort();//排序算法的比较；
    if(numbers[length-1]>=length){
        return false;
    }else{
        int temp=numbers[0];
        int i;
        for(i=1;i<length;i++){
            if(temp==numbers[i]){
                *duplicate=numbers[i];
                return true;
            }else{
                temp=numbers[i];
            }
            
        }

    }
    return false;

}
//方法二：先排序，然后利用hashMap进行查找；

//时间复杂度为：O(n)，空间复杂度为：O(n);

bool duplicate2 (int numbers[],int length ,int *duplicate)
{
    if(numbers==nullptr || length<=0){
        return false;
    }
    for(int i=0;i<length;i++){
        if(numbers[i]<0 ||numbers[i]>length-1){
            return false;
        }
    }
    unordered_map<int,int> temp_result;
    int i=0;
    for(;i<length;i++){
        if(array[i]>=length){
            return -1;
        }
        else{
            if(temp_result.find(array[i])){//查找出现了问题
                *duplicate=array[i];
                return true;
            }else{
                temp_result[array[i]]++;
            }
        }
    }
    return false;
}

*/
//方法三：直接进行替换查找；
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for(int i=0;i<length;i++){
        while(numbers[i]!=i){
            if(numbers[i]==numbers[numbers[i]]){
                *duplication=numbers[i];
                return true;
            }

            //交换元素的值；
            int temp=numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }
    }
    return false;
}

//测试代码:
bool contains( int array[],int length ,int number){
    for(int i=0;i<length;i++){
        if(array[i]==number){
            return true;
        }
    }
    return false;
}

void test(char *testName ,int number[],int lenghtNumbers, int expected[],int expectedExpected,bool VaildArgument){
    cout<<testName<<endl;

    int duplication1;
    bool vaildInput=duplicate(number,lenghtNumbers,&duplication1);

    if(vaildInput==VaildArgument){
        if(VaildArgument){
            if(contains(expected,expectedExpected,duplication1))
            {
                cout<<"passed"<<endl;
            }else{
                cout<<"Failed"<<endl;
            }
        }else{
            cout<<"Passed"<<endl;
        }
    }else{
        cout<<"Failed"<<endl;
    }
}

void test1(){
    int numbers[]={2,1,3,1,4};
    int duplications[]={1};
    test("Test1",numbers,sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
}

//重复的数字是最大的数字；
void test2(){
    int numbers[]={2,4,3,1,4};
    int dulplications[]={4};
    test("Test2",numbers,sizeof(numbers)/sizeof(int),dulplications,sizeof(dulplications)/sizeof(int),true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main(int argc, char* argv[])
{
  
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    system("pause");
    return 0;
}
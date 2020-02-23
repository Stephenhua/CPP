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

//题目一：数字在排序中出现的次数
/*
题目中规定，给出的数组已经进行了排序，所以在此基础之上进行查找某一个特定数的个数
时间复杂度：O(log n)
如果采用遍历的形式进行求解的话，那么时间复杂度W为O(n);
明显采用二分法的时间复杂度要更小；

*/
//查找k值得第一个位于哪一个位置
int GetFirstK (int *data,int k,int length ,int start ,int end ){
    if(start>end){
        return -1;
    }
    int midIndex=(start+end)/2;

    int midData=data[midIndex];

    if(midData==k){//当值相等的时候，应该判断前一个值是不是相等，如果前一个值同样是k，则需要进行递归，否则进行返回下标值
        if((midIndex>0&& data[midIndex-1]!=k)||midIndex==0){

            return midIndex;
        }else
        {
            end=midIndex-1;
        }
        
    }else if(midData>k){
        end=midIndex-1;
    }else if(midData<k){
        start=midIndex+1;
    }
    return GetFirstK(data,k,length,start,end);
}

//查找k值得最后一个数位于哪一个位置

// 找到数组中最后一个k的下标。如果数组中不存在k，返回-1
int GetLastK(const int* data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if(middleData == k)
    {
        if((middleIndex < length - 1 && data[middleIndex + 1] != k) 
            || middleIndex == length - 1)
            return middleIndex;
        else
            start  = middleIndex + 1;
    }
    else if(middleData < k)
        start = middleIndex + 1;
    else
        end = middleIndex - 1;

    return GetLastK(data, length, k, start, end);
}

//函数集合

int GetNumberOfok(int *data ,int length,int k){
    int number=0;/*
    if(k<data[0]||k>data[length-1]){
        return -1;
    }
*/
    if(data!=nullptr && length>0){
        int first=GetFirstK(data,length,k,0,length-1);
        int last=GetLastK(data,k,length,0,length-1);
        if(first>-1 && last>-1){
            number=last-first+1;
        }
    }
    return number ;
}

void Test(char *testName,int data[],int length,int k ,int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }

    int result=GetNumberOfok(data,length,k);
    if(result ==expected){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }

}

//查找数字出现在数组的中间
void Test1(){
    int data[]={1,2,3,3,3,3,4,5};
    Test("Test1",data,sizeof(data)/sizeof(int),3,4);
}

//查找数字出现在数组的开头

void Test2(){
    int data[]={3,3,3,3,4,5};
    Test("Test2",data,sizeof(data)/sizeof(int),3,4);
}

//查找数字出现在数组的结尾
void Test3(){
    int data[]={1,2,3,3,3,3};
    Test("Test3",data,sizeof(data)/sizeof(int),3,4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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

    system("pause");
    return 0;
}
#include <cstdio>
//#include "Array.h"
#include <set>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;


//方法三:采用红黑树的形式，时间复杂度为O(n long k),适合处理复杂大量的数据，
/*
具体实施步骤
1）在k个数中找到最大数
2）有可能在这个容器中删除最大数
3有可能要插入一个新的数字
*/

typedef multiset<int, greater<int>>  intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastsNumbers(const vector<int>&data, intSet& LeastNumber,int k){

    LeastNumber.clear();
    if(k<1|| data.size()<k){
        return;
    }

    vector<int>::const_iterator iter=data.begin();
    for(;iter!=data.end();++iter){
        if((LeastNumber.size()<k)){
            LeastNumber.insert(*iter);
        }else{
            setIterator iterGreatest=LeastNumber.begin();
            if(*iter<*(LeastNumber.begin()))
            {
                LeastNumber.erase(iterGreatest);
                LeastNumber.insert(*iter);  
            }
        }
    }
}



//===========================================================
//测试代码
//==============================================================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetLeastsNumbers(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}


// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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


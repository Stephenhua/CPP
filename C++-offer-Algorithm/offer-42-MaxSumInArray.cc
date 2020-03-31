#include <cstdio>
#include <iostream>

using namespace std;
//时间复杂为O(n)
/*
bool G_InvalidInput=false;

int FirstGratestSumSubArray(int *pData,int nLength){
    if((pData == nullptr) || (nLength<=0)){
        G_InvalidInput=true;
        return 0;//如果输入的数组不符合要求，则执行下面的范围
    }

    G_InvalidInput=true;

    int nCurSum=0;
    int nGreatestSum=0x80000000;
    //由于输入的数组有正有负，所以和一定是大于0的，如果出现值小于0的，则重新进行开始，如果出现比原有的值更大的话，则需要进行重新进行求解
    for(int i=0;i<nLength;++i){

    
        if(nCurSum<=0){
            nCurSum=pData[i];
        }
        else{
            nCurSum+=pData[i];
        }

        if(nCurSum>nGreatestSum){
            nGreatestSum=nCurSum;
        }
    }
    return nGreatestSum;
}
*/

#include <cstdio>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i = 0; i < nLength; ++i)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
} 

// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
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
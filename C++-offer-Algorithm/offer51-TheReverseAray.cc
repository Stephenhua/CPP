#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;




class Solution{
public:
    int count=0;
    int InversePairs(vector<int>& data)
    {
        // 检查边界条件
        if(data.size() != 0)
        {
            MergeSort(data,0,data.size()-1);
        }
        return count;
    }

private:
    void MergeSort(vector<int>& a, int l, int r)
    {
        /* 将长度为n的输入序列分成两个长度为n/2的子序列 */
        if (l < r)
        {
            /* 中间元素*/
            int m = (l + r) >>1;

            // 递归拆分
            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);

            // 递归合并
            Merge(a, l, m, r);
        }
    }
    void Merge(vector<int>& a, int l, int m, int r)
    {
        vector<int> t;
        //int p = 0;    /* p指向辅助数组 */
        int i = l;    /* i指向第一个子表 */
        int j = m + 1;/* j指向第二个子表 */

        /* 两个子表都不为空时 */
        while(i <= m && j <= r)
        {
            /* 取关键字小的元素转移至临时数组 */
            if (a[i] > a[j])
            {
                t.push_back(a[j++]);
                count=(count+m-i+1)%1000000007;
            }
            else
                t.push_back(a[i++]);
        }

        while(i <= m) t.push_back(a[i++]);/* 将非空的输入区间转移至输出区间 */
        while(j <= r) t.push_back(a[j++]);

        for (i = 0; i < t.size(); i++) a[l + i] = t[i];/* 归并完成后将结果复制到原输入数组 */
    }
};

//测试代码
void Test(char * testName ,int *data,int length ,int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }
    vector<int > value1(length);
    for(int i=0;i<length;i++){
        value1[i] = data[i];
    }
    
    Solution temp;
   
    if( temp.InversePairs(value1)==expected){
        cout<<"passed"<<endl;
    }
    else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    int data[] ={ 1,2,3,4,7,6,5 };
    int expected=3;
    Test("Test1",data,sizeof(data)/sizeof(int),expected);
}

 //递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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
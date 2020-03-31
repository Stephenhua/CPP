//链接地址：https://blog.csdn.net/Koala_Tree/article/details/79537127
/*
方法：
1）先将整形数组转换成string数组
2）将String数组排序
3）最后将排好序的字符串数组拼接出来，指定排序规则
4）制定的排序规则要求两个字符串拼接出来进行比较
    若ab > ba 则 a > b，
    若ab < ba 则 a < b，
    若 ab = ba 则 a = b；   
    如 2 21 因为 212 < 221 所以 排序后为 21 2
时间复杂度：O(nLongn)
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


    //用来产生降序
        static bool Compare(const string &str1, const string &str2){
            string s1= str1+str2;
            string s2=str2+str1;
            return s1<s2;

        }

    //
    string PrintMinNumber(vector<int>& numbers){
        string result;

        if(numbers.size()<0){
            return result;
        }

        vector<string> strNum;

        for(int i=0;i<numbers.size();i++){
            stringstream ss;
            ss<<numbers[i];
            string s= ss.str();

            strNum.push_back(s);
        } 

        sort(strNum.begin(),strNum.end(),Compare);

        for(int i=0;i<strNum.size();i++){
            result.append(strNum[i]);//表示添加文本字符串
        }
        return result;
    }

// ====================测试代码====================
void Test(const char* testName, vector<int>& numbers, int length, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    if(expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    string result=PrintMinNumber(numbers);
     cout<<result<<endl;

    const char* p=result.c_str();
    if(strcmp(p,expectedResult)==0){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
    printf("\n");
}

void Test1()
{
    vector<int> numbers= {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
}

void Test2()
{
    vector<int> numbers = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}

void Test3()
{
    vector<int> numbers = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
}

void Test4()
{
    vector<int> numbers = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    vector<int> numbers = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
}

void Test6()
{
        vector<int> numbers = {};
    Test("Test6", numbers, 0, "Don't print anything.");
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
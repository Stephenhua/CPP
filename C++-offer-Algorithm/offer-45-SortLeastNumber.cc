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
#include <string>
#include <vector>
#include <algrithm>

using namespace std;

class Solution{
    public:

    //用来产生降序
        static bool Compare(const string &str1, const string &str2){
            string s1= str1+str2;
            string s2=str2+str1;
            return s1<s2;

        }

    //
    string PrintMinNumber(vector<int> numbers){
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
};
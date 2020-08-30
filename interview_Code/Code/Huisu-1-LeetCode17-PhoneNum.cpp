#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

/*
题目：电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
            vector<string> res;

            DFS( res, "" ,digits , 0);
            return res;
    }

    void DFS(vector<string>& res, string str,string& digits,int i){
        //结束条件
        if( i == digits.size() ){
            if( str.size()){
                res.push_back(str);
            }
                return;            
        }
        string s = table[digits[i]-'2'];
        for(int i =0 ;i < s.size() ;i++ ){
            str.push_back(s[i]);
            DFS(res,str,digits,i+1);
            str.pop_back();
        }
    }
};
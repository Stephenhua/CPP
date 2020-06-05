#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include <set>
#include <unordered_set>
using namespace std;

/*
139. 单词拆分
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/
//方法一：采用动态规划；

    bool wordBreak(string s, vector<string>& wordDict) {

        if( s.empty() || wordDict.empty()){

            return false;

        }

        int n = s.size();

        vector<bool> dp(n+1 , false);

        dp[0] = true;

        for(int end =1 ;end<= n ;end++){
            for( int i = 0 ;i < end; i++){
                if( dp[i] && find( wordDict.begin() ,wordDict.end(),s.substr( i, end-i))!= wordDict.end()){
                    dp [end] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

int main( int argc, char* argv[]){

    string s= "LeetCode";

    vector<string> wordDict = {"Leet", "Code"};

    bool res = wordBreak( s, wordDict);

    cout <<res <<endl;

    system("pause");

}

//方法二：在递归方面进行了优化；

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size()+1, false);
    
        unordered_set<string> m(wordDict.begin(), wordDict.end());

        dp[0] = true;

        //获取最长字符串长度

        int maxWordLength = 0;
        //获取长度；
        for (int i = 0; i < wordDict.size(); ++i){

            maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());

        }
    for (int i = 1; i <= s.size(); ++i){
        //进行剪枝，当前值小于最大长度时，则直接从0开始，如果i大于maxWordLength的话，那么直接比较最长的距离就可以了，可以减少不必要的循环；
        for (int j = std::max(i-maxWordLength, 0); j < i; ++j){

            if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){

                dp[i] = true;

                break;
                
            }
        }
    }
    return dp[s.size()];
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>

#include <numeric>

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


/*
解题思路：标准的
1)dp[i]表示0.。i可不可以用wordDict表示；
2）初始化dp0.。。size+1，false；
3）dp[0]表示如果string s为空的话，表示空字符可以被表示；
4） 遍历字符串中的所有子串，便利开始索引i，遍历区间为[0,n）；
    遍历索引j ，遍历区间为 [i+1,n+1];
        若 dp[i]=True dp[i]=True 且 s[i,\cdots,j)s[i,⋯,j) 在 wordlistwordlist 中：dp[j]=Truedp[j]=True。解释：dp[i]=Truedp[i]=True 说明 ss 的前 ii 位可以用 wordDictwordDict 表示，则 s[i,\cdots,j)s[i,⋯,j) 出现在 wordDictwordDict 中，说明 ss 的前 jj 位可以表示。
5) 返回dp[n];
如果前面的dp[i]不能够被被字符串匹配，那么后面的话肯定不可能匹配；
时间复杂度为 ： o(n2);空间复杂度为：O(n);
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        for(int i =0 ; i < s.size() ; i++){
            if( !dp[i]){
                continue;
            }
            //遍历词典找出合适的值；
            for( auto& dict : wordDict){
                if( dict.size()+i <= s.size() && s.substr(i,i+dict.size()) == dict  ){
                    dp[i+dict.size()] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
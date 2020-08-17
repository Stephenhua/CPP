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
1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
 

提示:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
输入的字符串只含有小写英文字符。

*/

/*
动态规划：
1） 状态分析： dp[i][j]表示word1从0~i中，word2冲0~j中，包含的最长公共子序列；
2） 状态转移方程：
    主要分为两种情况： 在 挥着不在；
    用两个指针 i 和 j 从后往前遍历 s1 和 s2，如果 s1[i]==s2[j]，那么这个字符一定在 lcs 中；否则的话，s1[i] 和 s2[j] 这两个字符至少有一个不在 lcs 中，需要丢弃一个。
    if( s[i]== s[j]) 则找到公共子序列；
    如果不相等，则只能根据谁能让dp[i][j]更大就听谁的；
3） 初始化，dp[i][0]=  0 ;dp[0][i] = 0 ;一个为-0 ，那么公共只能为0 ；

4）输出结果：dp[m][n]；

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp( m+1,vector<int>(n+1,0));

        for( int i = 1 ;i <=m ;i++){
            for(int j =1 ;j <=n ;j++){
                if( text1[i-1] == text2[j-1]){//如果相等，则直接进行求和；
                    dp[i][j] =1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for( int i = 1 ; i <=m ;i++){
            for( int j =1 ; j <= n ;j++){
                if( text1[i-1] == text2[i-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};
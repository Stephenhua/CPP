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
516. 最长回文子序列
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母

*/


/*
子序列和字串的区别:
    子串是连续进行的；
    子序列是不连续有跳跃的；

题目：
1） 最长递增子序列；

2） 二维dp数组；

    1）2.1 涉及两个字符串/数组时（比如最长公共子序列），dp 数组的含义如下：

        在子数组 arr1[0..i] 和子数组 arr2[0..j] 中，我们要求的子序列（最长公共子序列）长度为 dp[i][j]
        相关题目：（1）编辑距离 （2）公共子序列；

    2）2.2 只涉及一个字符串/数组时（比如本文要讲的最长回文子序列），dp 数组的含义如下：

        在子数组 array[i..j] 中，我们要求的子序列（最长回文子序列）的长度为 dp[i][j]。

        相关题目：1）最长回文子序列；


动态规划：
1） 状态分析：
    dp数组定义是，在字串s[i..j]中，最长回文子序列的长度为dp[i][j]，

2）状态转移方程：
    dp[i][j] 可以由 dp[i+1][j-1]的结果得到；dp[i+1][j] 和dp[i][j-1]之间的关系；
3）结果输出：dp[0][n-1]表明长度从 0 到 n-1；

4) base case dp[i][j] 当i== j 时，则dp[i][i] == 1;

5)遍历的时候从底向上，从做到右遍历；

*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp( n, vector<int>( n,0));//进行初始化；

        //base case ;
        for( int i = 0 ;i < n ;i++){
            dp[i][i] =  1;
        }

        //反着遍历；

        for( int i = n-1 ;i >=0 ;i--){
            for(int j = i+1 ; j< n ;j++){
                //状态转移方程；
                if( s[i]== s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max( dp[i+1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];//整个s的回文子串；
    }
};
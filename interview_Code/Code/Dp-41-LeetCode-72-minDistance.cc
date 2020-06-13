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
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

*/

/*
动态规划：
1） 状态分析， dp[i][j]表示 word1从0到i转换为word2中0到j的最少步数；0..i-1.不包括i；
2）状态方程：
    当word[i-1] ==word[j-1] ,那么 dp[i][j] = dp[i-1][j-1];
    当word[i] != word[j] 时，那么dp[i][j]  = min( 增加 dp[i][j-1]、删除dp[i-1][j]、替换dp[i-1][j-1])+1三种形式的最小值；

3） 初始状态 dp[i][0] = i ，表示全部删除; dp[0][i] = i，表示全部插入；
4） 最后的结果：dp[m][n];
*/


class Solution {
public:
int min( int a, int b, int c){
    return std::min( a, std::min(b,c));
}
int minDistance(string word1, string word2) {
    
    int m = word1.length();
    int n = word2.length();

    //base case；
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for( int i=1;i<=m;i++){
        dp[i][0] = i;
    }

    for( int i =1 ;i <=n ;i++){
        dp[0][i] = i;
    }

    //自顶向上求解；

    for( int i = 1 ; i <= m ;i++){
        for( int j = 1 ; j <= n; j++){
            if( word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{

                dp[i][j] = min( dp[i-1][j]+1 ,dp[i-1][j-1]+1, dp[i][j-1]+1);
            }
        }
    }
    return dp[m][n];
}
};
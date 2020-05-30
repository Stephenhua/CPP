#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
/*
题目：72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 思路：解决两个字符串的动态规划问题，一般都是用两个指针 i,j 分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模。
 * 
 * if s1[i] == s2[j]:
    啥都别做（skip）
    i, j 同时向前移动
else:
    三选一：
        插入（insert）
        删除（delete）
        替换（replace）
dp(i, j - 1) + 1,    # 插入
# 解释：
# 我直接在 s1[i] 插入一个和 s2[j] 一样的字符
# 那么 s2[j] 就被匹配了，前移 j，继续跟 i 对比
# 别忘了操作数加一

dp(i - 1, j) + 1,    # 删除
# 解释：
# 我直接把 s[i] 这个字符删掉
# 前移 i，继续跟 j 对比
# 操作数加一

dp(i - 1, j - 1) + 1 # 替换
# 解释：
# 我直接把 s1[i] 替换成 s2[j]，这样它俩就匹配了
# 同时前移 i，j 继续对比
# 操作数加一

这样会产生重叠问题，如何解决？
备忘录和Dp table
Dp table介绍：
 1）base case ： i,j 都为-1 ，那么数组索引至少是0 ，所以Dp数组会偏移一位。
 * 
 * 
 */

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

    for( int i = 1 ; i<=m ;i++){
        for( int j = 1 ; j <= n; j++){
            if( word1[i] == word2[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{

                dp[i][j] = min( dp[i-1][j] ,dp[i-1][j-1], dp[i][j-1])+1;
            }
        }
    }
    return dp[m][n];
}
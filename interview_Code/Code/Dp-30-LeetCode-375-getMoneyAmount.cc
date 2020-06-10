#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;


/*
375. 猜数字大小 II
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

示例:

n = 10, 我选择了8.

第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

游戏结束。8 就是我选的数字。

你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

*/
/*
动态规划：
1）状态分析：
    dp[i][j] 表示依次以 i到 j 的数字作为分割点（猜的数字），值表示必赢游戏所需最少的钱；

2）转移方程：
    i i+1 i+2 ... ... j-2 j-1 j
    以i+1为分割点对应的：dp1=max(dp[i][i],dp[i+2][j])+i+1

    以j-1为分割点对应的: dp2=max(dp[i][j-2],dp[j][j])+j-1

    特别地,以i为分割点：dp0=i+dp[i+1][j];以j为分割点: dp3=j+dp[i][j-1]

    dp[i][j]=min(dp0,dp1,dp2,dp3)

3） 初始状态，dp[n+1][n+1] 中对角线为0，其余初始化为INT_MAX;
4）结果 dp[1][n];
https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/dong-tai-gui-hua-c-you-tu-jie-by-zhang-xiao-tong-2/
*/
class Solution {
public:
    int getMoneyAmount(int n) {

        if( n  == 1){
            return 0;
        }
        int dp[n+1][n+1];

        //初始化；
        for( int i = 0 ;i < n+1 ;i++){
            for(int j = 0 ; j <n+1 ;j++){
                if( i==j){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = INT_MAX;
                }
            }
        }

        //先遍历列，然后行；

        for( int j =2 ; j <=n ;j++){
            for( int i = j-1 ; i>=1 ;i--){
                //算除了两端的每一个分割点
                for( int k = i+1 ; k<= j-1 ;k++){
                    dp[i][j] = min( k+max(dp[i][k-1],dp[k+1][j]),dp[i][j]);
                }
                dp[i][j] = min( dp[i][j],i+dp[i+1][j]);
                dp[i][j] = min( dp[i][j] ,j+dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};


//方法二:
class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 1][n + 1];
        memset(dp,0,sizeof(dp));
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start+len-1 <= n ; start++) {
                int minres = 1000000000;
                for (int piv =start + (len - 1) / 2; piv <start + len - 1; piv++) {
                    int res = piv + max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = min(res, minres);
                }
                dp[start][start + len - 1] = min(minres,dp[start][start+len-2]+start + len - 1);
            }
        }
        return dp[1][n];

    }
};

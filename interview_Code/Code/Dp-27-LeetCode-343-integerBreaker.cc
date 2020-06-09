#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
343. 整数拆分
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。

*/
/*;
方法：动态规划:自底向上；
dp[i]的组成可以又四种情况组成 i = i-j +j ;分为下面的四种情况；
1) 拆为两个，dp[j] *(i-j);
2) dp[i-j] *(j);
3) dp[i-j]*dp[j];
4) (i-j)*j;

对于每一个数都选择一个最大的乘积作为最大值；
1） 状态变量： dp[i] 表示在i的时候，最大乘积值；
2） 状态转移方程： dp[i] = min( dp[i-j]*j ,dp[j]*(i-j),i*(i-j),dp[i]*dp[i-j]);
3) 初始状态，dp[0]\dp[1]\dp[1];
4)  结果 ： dp(n);

*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        if( n==2 ){
            return 1;
        }

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for( int i=3 ;i<= n ;i++){
            for(int j=2 ;j <i ;j++){
                dp[i] =max( dp[i-j]*j ,max(dp[j]*(i-j),max(dp[i-j]*dp[j] ,(i-j)*i)));
                 dp[i] = max(dp[i], max(max(dp[i - j] * dp[j], dp[j] * (i - j)), max(dp[i - j] * j, (i - j) * j)));

            }
        }
        return dp[n];
    }
};
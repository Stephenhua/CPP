#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
题目：123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
采用穷举的方法进行
动态方程转移：
dp[i][k][0] = max( dp[i-1][k][0] , dp[i-1][k][1]+prices[i])//当手中没有股票；
dp[i][k][1] = max( dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
面对穷举的框架，则可以设计位下面所示：
int max_k = 2;
int[][][] dp = new int[n][max_k + 1][2];
for (int i = 0; i < n; i++) {
    for (int k = max_k; k >= 1; k--) {
        if (i - 1 == -1) { 
            处理 base case 
            dp[i][k][0] = 0;
            dp[i][k][1] = -prices[i];
            continue;
        }
        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
    }
}
// 穷举了 n × max_k × 2 个状态，正确。
return dp[n - 1][max_k][0];

base case：
dp[-1][k][0] = dp[i][0][0] = 0
dp[-1][k][1] = dp[i][0][1] = -infinity
因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0 
因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0 
dp[-1][k][1] = -infinity
解释：还没开始的时候，是不可能持有股票的，用负无穷表示这种不可能。
dp[i][0][1] = -infinity
解释：不允许交易的情况下，是不可能持有股票的，用负无穷表示这种不可能。
作者：labuladong
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


int maxProfit(vector<int>& prices) {
    
    if(prices.empty()) return 0;

    int k =2 ;

    int size = prices.size();
    
    int dp[size][k+1][2];
    
    ::memset(dp, 0, sizeof(dp));

    for(int i =0 ;i <size;i++){

        for( int j =1 ;j <=k ;j++){

            if( i == 0){
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[0];
                continue;
            }

            dp[i][j][0] = std::max( dp[i-1][j][0] , dp[i-1][j][1]+prices[i]);
            dp[i][j][1] = std::max( dp[i-1][j][1] , dp[i-1][j-1][0]-prices[i]);
        }
    }
    return dp[size-1][k][0];
}

//方法二：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/er-wei-bei-bao-zui-you-jie-fa-by-coldme-2/
/*
思路：
1）两个状态属性，交易最大次数k,天数n;
2) 选择：「不做处理」和「卖出股票」，
定义dp[k + 1][n]，元素dp[i][j]表示最多交易i次时在第j天能获得的最大利润。dp[i][j] = max(不做处理， 卖出股票)
如果不做处理，第j天的最大利润就和第j-1天相等。
如果卖出股票，设是在第m天买入，那么第j天的最大利润就是两天的价格差+最多交易i-1次时第m天的获利。当然，这里的m需要从0遍历到j-1。
表示最多交易i次时，在第J天的最大利润：dp[i][j]= max(dp[i][j−1]，prices[j]−prices[m]+dp[i−1][m],where m=0,1...j−1)
如果我们在遍历dp数组中实时更新一个变量maxDiff，就能节省这部分的时间开销。maxDiff表示：最多交易i-1次时，从第0天到第j-1天最大利润-当天价格的最大值。
 maxDiff=max(maxDiff,dp[i−1][j−1]−prices[j−1])
作者：coldme-2
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/er-wei-bei-bao-zui-you-jie-fa-by-coldme-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
作者：coldme-2
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/er-wei-bei-bao-zui-you-jie-fa-by-coldme-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int maxProfit(int k ,vector<int>& prices) {

    int n = prices.size();

    if( n==0 || k==0){
        return 0;
    }

    if( k >= n/2){
        int res = 0;
        for( int i =1 ;i<n ;i++){
            res += max(0,prices[i]-prices[i-1]);
        }
        return res;
    }
    
    vector<vector<int>> dp(k+1 ,vector<int>(n));

    for( int i = 1; i< dp.size();i++){

        int maxDiff = -prices[0];
        for( int j =1 ;j< dp[0].size() ;j++){
            maxDiff = max(maxDiff ,dp[i-1][j-1] -prices[j]);
            dp[i][j] = max( dp[i][j-1] , prices[j]+maxDiff);
        }
    }
    return dp[k][n-1];

}
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;


/*
188. 买卖股票的最佳时机 IV
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
dp[i][k][0] = max(dp[i-1][k][0] ,dp[i-1][k][1]+prices[i]);
dp[i][k][1] = max( dp[i-1][k][1] ,dp[i-1][k-1][0]-prices[i]) = max( dp[i-1][k][1] , dp[i-1][k][0]-prices[i]);


有k 和k-1具有相等性，所以可以转换为下面的方式；

dp[i][0]= max( dp[i-1][0] ,dp[i-1][1]+prices[i]);
dp[i][1] = max( dp[i-1][1] , dp[i-1][0] -prices[i]);

*/

int maxProfit_k_inf( vector<int>& prices){

    int n = prices.size();

    int res = 0 ;

    for( int i= 1 ;i <n ;i++){
        res += max( 0, prices[i] - prices[i-1]);
    }

    return res;

}
int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();
    if( k >= n/2){
        return maxProfit_k_inf(prices);
    }

    vector<vector<int>> dp(k+1 ,vector<int>(n)) ;

    for( int i = 1 ; i < dp.size() ; i++){

        int maaxDiff = -prices[0];

        for( int j = 1 ; j < dp[0].size() ;j++){

            maaxDiff = max( maaxDiff, dp[i-1][j-1] - prices[j]);

            dp[i][j] = max( dp[i][j-1] , maaxDiff+ prices[j]);

        }
    }
    return dp[k][n-1];//最终返回的必须是手中没有股票的状态；
}

//方法二：使用vector《int》的空间进行执行操作；

    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        if(k>=n/2){
            int res = 0;
            for(int i=1;i<n;i++){
                if(prices[i]>prices[i-1])
                    res += prices[i]-prices[i-1];
            }
            return res;
        }

        vector<int> dp( n,0);
        while( k-- > 0){
            for( int i=1 ;i< n; i++){
                dp[i] = max(dp[i-1]+ prices[i]- prices[i-1] , dp[i]);//前一个状态和当前状态的值进行比较，
            }

            for( int i = 1 ; i<n ;i++){
                dp[i] = max( dp[i],dp[i-1]);//选择一个最大值；
            }
        }
        return dp[n-1];

    }
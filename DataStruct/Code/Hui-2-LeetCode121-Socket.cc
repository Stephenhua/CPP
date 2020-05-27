#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

/**
 * 121. 买卖股票的最佳时机
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。
示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



 dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
              max(   选择 rest  ,           选择 sell      )

解释：今天我没有持有股票，有两种可能：
要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
              max(   选择 rest  ,           选择 buy         )

解释：今天我持有着股票，有两种可能：
要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。

作者：labuladong
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 * 
*/


int maxProfit(vector<int>& prices) {

    int size = prices.size();

    int ans = 0;

    vector<vector<int>> dp;

    for( int i =0 ;i<size ;i++){

        if( i-1 == -1){

            //dp[i][0]= max(dp[-1][0],dp[-1][1]+preces[i])=max( 0,  -infinity+ prices[i]);
            dp[i][0] = 0 ;
            //dp[i][1] = max(dp[-1][1] , dp[-1][0]-prices[i])= max(- infinity, 0-prices[i])= -prices[i];
            dp[i][1] = -prices[i];
            continue ;
        }

        dp[i][0] = max( dp[i-1][0] ,dp[i-1][1]+prices[i]);
        dp[i][1] = max( dp[i-1][1], -prices[i]);

    }
    return dp[size-1][0];
}

//由于状态转移方程只是和前一个相关，所以可以降低空间复杂度；

int maxProfit2(vector<int>& prices) {

    int size = prices.size();

    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;

    for( int i =0 ;i<size ;i++){    



        //dp[i][0] = max( dp[i-1][0] ,dp[i-1][1]+prices[i]);

        dp_i_0 = max( dp_i_0, dp_i_1+prices[i]);
        //dp[i][1] = max( dp[i-1][1], -prices[i]);

        dp_i_1 = max( dp_i_1 ,dp_i_0-prices[i]);

    }
    return dp_i_0;
}



int maxProfit3(vector<int>& prices) {

    int size = prices.size();

    if( size <2){
        return 0 ;
    }

    vector<int> mins( size,INT_MAX);

    int ans =-1 ;

    mins[0] = prices[0];

    for( int i =1 ;i< size ;i++){

        mins[i] = min( prices[i] , mins[i-1]);//找到当前的最小值，
        ans = max( ans , prices[i]- mins[i]);//找到结果的最大值；
    }

    return ans;

}

//方法四：直接将用一个元素进行村存储，实现每个元素的最大值
int maxProfit3(vector<int>& prices) {

    if(prices.size() <= 1){
        return 0;
    }

    int min_val = prices[0];

    int max_val = 0;

    for( int i=1 ;i < prices.size() ;i++){

        int cal = prices[i]-min_val;

        if(cal > max_val){
            max_val = cal;
        }
        if( cal <0 ){
            min_val = prices[i];
        }
    }

    return max_val;
}
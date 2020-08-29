#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。


示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1

*/

/*
方法一：动态规划：
dp[i] 表示凑成金额i时，最少需要的硬币数；
状态转移方程： dp[i] = min( dp[i-coin[0]], dp[i-coin[1]],dp[i-coin[2]]...); 当i-coins[i] >= 0 ;

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 1 ;
        for(int i = 0 ;i <= amount ; i++ ){
            for(int coin : coins){
                if( i -coin < 0){
                    continue ;
                }
                dp[i] = min( dp[i],dp[i-coin]+1);
            }
        }
        return (dp[amount]== amount+1)?-1:amount;
      }

};


//减枝+DFS求解；

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if( coins.size() == 0 ){
            return -1;
        }

        int res =INT_MAX;
        //从小到大进行排序；
        sort( coins.rbegin() ,coins.rend());

        int n = coins.size();

        Core( coins, amount,0,0,res);
        return res == INT_MAX ? -1 :res;
    }

    void Core( vector<int>& coins, int amout , int index , int count , int &ans){
        if( amout <0 ){
            return;
        }

        if( amout == 0 ){
            ans = min( cout , ans );
            return;
        }
        //结束；最底层；
        if( index == coins.size()){
            return;
        }
        //通过排序之后，可以每次选择最大的硬币，如果不行，返回到上一层中；
        for(int i = amout/coins[index] ; i>=0&& i+count < ans ; i-- ){
            Core(coins , amout -  i* coins[index],index+1, count+i , ans);
        }
    }
};
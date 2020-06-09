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
动态规划，从底向上；

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;

        for(int i = 0 ; i < dp.size() ;i++){
                //考虑每一种情况下的个数；需要不停的进行更新；
            for( int coin:coins){
                if( i-coin < 0){
                    continue;
                }

                dp[i]  = min( dp[i] ,1+dp[i-coin]);
            }
        }

        return (dp[amount] == amount+1) ? -1: dp[amount];
    }
};

//方法二：采用递归加贪心算法；
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

    void Core( vector<int>& coins, int amount, int index , int count ,int &ans){
        //进行剪枝，然后进行运算；
        
        if( amount < 0){
            return;
        }

        if( amount == 0){
            ans = min( count ,ans);
            return;
        }   
        //表明该部分不存在；
        if( index == coins.size()){
            return;
        }
        //对于最大的值的个数从max到 0的位置；
        for(int i = amount/coins[index] ;i >= 0 && i+count < ans ;i--){
            Core( coins,amount-i*coins[index],index+1,count+i, ans);
        }
    }

};
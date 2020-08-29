/*
518. 零钱兑换 II
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10] 
输出: 1
 

注意:

你可以假设：

0 <= amount (总金额) <= 5000
1 <= coin (硬币面额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数

*/
#include <iostream>
#include <vector>

using namespace std;

/*
思路：完全背包问题
目的：选择种类：不需要考虑顺序；


动态规划：
1）dp[i][j]：硬币列表的前缀[0..i]能够凑成总金额为j的组合数；
2）状态转移方程：
对于组合问题而言：动态转移方程为：dp[i] +=dp[i-num];
    dp[i][j] = dp[i-1][j-0*coins[i]] +dp[i-1][j-1*nums[i]] +dp[i-1][j-2*nums[i]]
                +dp[i-1][j-2*nums[i]]+...+
3)初始化问题：
    dp[0][0] = 1 ;
    dp[0][i] = 1 能够组合出的容量只有 coins[0] 的整数倍数。
    dp[i][0] =0
4)输出值：
    dp[len-1][amount]；

时间复杂度：O(NM2)，M为金额，N为硬币；
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        if( size == 0 ){
            if( amount == 0){
                return 1;
            }else{
                return 0;
            }
        }

        vector<vector<int>> dp(size+1,vector<int>(amount+1,0));
        dp[0][0] =1 ;
        for(int i = coins[0];i <= amount ;i += coins[0]){
            dp[0][i] = 1;
        }

        for(int i =1 ;i < size ; i++){
            for(int j = 0 ; j <=amount ; j++){
                for(int k =0 ; j-k*coins[i] >= 0 ; k++){
                    dp[i][j] += dp[i-1][j-k*coins[i]];
                }
            }
        }
        return dp[size-1][amount];
    }
};

//进行时间优化
/*
时间复杂度：O(NM)O(NM)，这里金额为 MM，硬币数为 NN。与参考代码 1 相比缩减了最内层的循环，时间复杂度降低了一级；
空间复杂度：O(NM)O(NM)，表格有 NN 行，MM 列。
dp[i][j] = dp[i-1][j-0*coins[i]] + dp[i-1][j-1*coins[i]] +dp[i-1][j-2*coins[i]] + dp[i-1][j-3*coins[i]]++...
dp[i][j-coins[i]] = dp[i-1][j-coins[i] - 0*coins[i]] + dp[i-1][j-coins[i]-1*coins[i]] + dp[i-1][j-coins[i]-2*coins[i]]++...
dp[i][j] - dp[i][j-coins[i]] = dp[i-1][j];
前提条件是： j-k*coins[i] > =0 ;
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        if( size == 0 ){
            if( amount == 0){
                return 1;
            }else{
                return 0;
            }
        }

        vector<vector<int>> dp(size+1,vector<int>(amount+1,0));
        dp[0][0] =1 ;
        for(int i = coins[0];i <= amount ;i += coins[0]){
            dp[0][i] = 1;
        }

        for(int i =1 ;i < size ; i++){
            for(int j = 0 ; j <=amount ; j++){
                dp[i][j] = dp[i-1][j];
                if( j-coins[i] >= 0 ){
                    dp[i][j] +=dp[i][j-coins[i]];
                }
            }
        }
        return dp[size-1][amount];
    }
};

//进行空间优化；

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        if( size == 0 ){
            if( amount == 0){
                return 1;
            }else{
                return 0;
            }
        }

        vector<int> dp(amount+1,0);
        dp[0]=1 ;
        for(int i = coins[0];i <= amount ;i += coins[0]){
            dp[i] = 1;
        }

        for(int i =1 ;i < size ; i++){
            for(int j = coins[i]; j <= amount ; j++){
                    dp[j] +=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

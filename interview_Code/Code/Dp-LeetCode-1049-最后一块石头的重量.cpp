#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1049. 最后一块石头的重量 II
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000



*/

/*
思路：转化为0-1背包问题；
转化为：：有一堆石头，分成两堆，如何分才能使两堆石头之间的重量差距最小

dp[i][j] 表示 第 i 件物品，且背包容量为j时所能获得的最大价值；
dp[i][j] = max( dp[i-1][j] , dp[i][j-w[i]] +v[i])
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int size = stones.size();
        int sum = 0 ;
        int bagsize = 0;

        for( auto& stone : stones){
            sum += stone;
        }

        bagsize = sum / 2;
        
        vector<vector<int>> dp(bagsize+1,vector<int>(bagsize+1,0));


        for(int i = 1 ; i < size+1 ;i ++){
            for( int j = 1 ; j < bagsize+1 ; j++ ){
                if(stones[i-1] > j ){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
                }
            }
        }

        return sum - 2*dp[size][bagsize];
    }

};

//dp[i]表示背包容量限制为i时能够装载的最大石块总重量；

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int size = stones.size();
        int sum = 0 ;
        int bagsize = 0;

        for( auto& stone : stones){
            sum += stone;
        }

        bagsize = sum / 2;

        vector<int> dp(bagsize+1);

        for(int i = 0 ;i < size ;i++){
            int curStone = stones[i];
            for(int  j = bagsize; j >= 0 ; j--){
                if( j > curStone){
                    dp[j] = max( dp[j] ,dp[j-curStone]+curStone);
                }
            }
        }

        return sum -2*dp[bagsize];

    }

};
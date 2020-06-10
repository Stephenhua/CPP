#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
0-1背包的问题
问题描述：
今天就来说一下背包问题吧，就讨论最常说的 0-1 背包问题。描述：

给你一个可装载重量为 W 的背包和 N 个物品，每个物品有重量和价值两个属性。
其中第 i 个物品的重量为 wt[i]，价值为 val[i]，
现在让你用这个背包装物品，最多能装的价值是多少？

动态规划步骤：
1） dp[i][w] :对于前i个物品，当前背包容量为w，这种情况下可以装的最大价值为dp[i][w]；
    如果 dp[3][5] = 6，其含义为：对于给定的一系列物品中，若只对前 3 个物品进行选择，当背包容量为 5 时，最多可以装下的价值为 6。

2）状态转移逻辑：
    dp[i][w] 表示：对于前 i 个物品，当前背包的容量为 w 时，这种情况下可以装下的最大价值是 dp[i][w]。

    （1）- 如果你没有把这第 i 个物品装入背包，那么很显然，最大价值 dp[i][w] 应该等于 dp[i-1][w]，继承之前的结果。

    （2）- 如果你把这第 i 个物品装入了背包，那么 dp[i][w] 应该等于 dp[i-1][w - wt[i-1]] + val[i-1]。

            首先，由于 i 是从 1 开始的，所以 val 和 wt 的索引是 i-1 时表示第 i 个物品的价值和重量。

            而 dp[i-1][w - wt[i-1]] 也很好理解：你如果装了第 i 个物品，就要寻求剩余重量 w - wt[i-1] 限制下的最大价值，加上第 i 个物品的价值 val[i-1]。

        dp[i][w] = max( dp[i-1][w-wt[i-1]]+ val[i-1] ,dp[i-1][w]);
3) 边界条件按
    base case 就是 dp[0][..] = dp[..][0] = 0
4） 结果：
    dp[N][N];
*/

int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {

    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for( int i = 1 ; i <=N ;i++){
        for( int j =1 ;j <= W;j++){
            
            //超出重量时，则需要保持不变，否则直接进行比较；
            if( j-wt[i-1] <0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max( dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
            }
        }
    }

    return dp[N][W];
}
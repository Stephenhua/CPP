#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>

#include <numeric>

using namespace std;

/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

*/

/*
解题思路：动态规划求解；

*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if( n==0 || m==0){
            return 0 ;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i =1 ; i < n ;i++){
            dp[i][0] = dp[i-1][0] +grid[i][0];
        }

        for( int j =1 ; j< m ;j++){
            dp[0][j] = dp[0][j-1]+ grid[0][j];
        }


        for( int i =1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){

                dp[i][j] = min( dp[i-1][j],dp[i][j]) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};
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
63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if( obstacleGrid.size() == 0 ){
            return 0 ;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(m,0));

        for( int i = 0 ;i < m && obstacleGrid[i][0] ==0 ;i++){
            dp[i][0] = 1;
        }

        for(int i= 0 ; i <n && obstacleGrid[0][i];i++){
            dp[0][i] = 1;
        }

        //根据状态进行状态转移
        for( int i = 1 ; i < m ;i++){
            for( int j = 1 ; j < n ;j++){
                if( obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

//采用深度优先搜索进行求解；
/*


从起点开始搜索，碰到障碍物就回溯，碰到下边界只能往右，碰到右边界只能往下，其他正常情况，
可以往下或者往右两条路，逐步搜索得到结果。思路比较简单，也通过了一些用例。
但是！由于不同的路线会经过相同的点，造成多次计算，导致超时了。
理论上，时间复杂度为O((M*N)^2）.

作者：rodmax
链接：https://leetcode-cn.com/problems/unique-paths-ii/solution/dfs-dp-by-rodmax/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
int Core(vector<vctor<int>>& grid ,int i ,int j ){
    if( i == grid.size()-1 && j == grid[0].size()-1 ){
        return grid[i][j] == 1 ? 0:1;
    }else if( i == grid.szie()-1 && j != grid[0].size()-1){
        if( grid[i][j] == 1 ){
            return 0 ;
        }else {
            return Core( grid , i,j+1);
        }
    }else if( i != grid.size()-1 && j == grid[0].size()){
        if( grid[i][j] == 1){
            return 0 ;
        }else {
            return Core( grid ,i+1,j);
        }
    }else{
        if( grid[i][j] == 1 ){
            return 0 ;
        }else{
            return Core(grid,i+1,j) +Core(grid,i,j+1);
        }
    }
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        return obstacleGrid[0][0] == 1 ? 0 : Core(obstacleGrid,0,0);
    }

};
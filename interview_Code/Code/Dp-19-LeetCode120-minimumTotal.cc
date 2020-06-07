#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

*/

//从底向上进行考虑；
/*
1)状态定义： dp[i][j]表示包含第i行第j列元素的最小路径和；
2） 状态分析；
    triangle[i][j]  的最后一行表示triangle；
    2）常规：
      triangle[i][j]一定可以到达 triangle[i+1][j] 和triangle[i+1][j+1];
      dp[i][j] = min( triangle[i+1][j] ,triangle[i+1][j+1])+ triagle[i][j];
3)转换方程：
    dp[i][j] = min( dp[i+1][j]mdp[i+1][j+1]) +triangle[i][j];

*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        if( triangle.size() == 0){
            return 0 ;
        }

        vector<vector<int>> dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
        
        for(int i = triangle.size()-1 ;i >=0 ;i--){
            vector<int> row = triangle[i];
            for(int j= 0 ; j < row.size() ;j++){
                dp[i][j] = min(dp[i+1][j] ,dp[i+1][j+1]) + triangle[i][j];
            }
        }

        return dp[0][0];

    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        if( triangle.size() == 0){
            return 0 ;
        }

       vector<int> dp(triangle.size()+1,0);
        
        for(int i = triangle.size()-1 ;i >=0 ;i--){
            vector<int> row = triangle[i];
            for(int j= 0 ; j < row.size() ;j++){
                dp[j] = min(dp[j] ,dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];

    }
};
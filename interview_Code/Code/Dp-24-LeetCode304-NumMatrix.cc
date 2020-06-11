#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
304. 二维区域和检索 - 矩阵不可变
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。

Range Sum Query 2D
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。

*/

/*
动态规划
1）状态分析：
    dp[i][j]表示左上角的和；

2） 状态转移方程：
    sumRegin(row1,col1,row2,col2)  = dp[row2][col2] - dp[row2][col1-1]-dp[row1-1][col2] +dp[row1-1][col1-1];

3) 初始状态
    直接进行求和相加

4） 结果，直接返回sumRegin即可；

*/

class NumMatrix {

private:
        vector<vector<int>> dp ;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  = matrix[0].size();

        if( n==0 || m==0){
            return ;
        }

        dp = vector<vector<int>> (n,vector<int>(m));
        //进行dp相加；
        for( int i =0 ;i < n ;i++){
            for( int j = 0 ;j < m ; j++){
                int s = 0 ;
                if( i > 0) s  += dp[i-1][j];
                if( j > 0) s  += dp[i][j-1];

                if( i > 0 && j > 0 ){
                    s -= dp[i-1][j-1];
                }

                dp[i][j] = s + matrix[i][j];

            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (dp.size() == 0 || dp[0].size() == 0) return 0;
        int res = 0 ;
        if( row1 >0 ) res+=dp[row1-1][col2];
        if( col1 > 0) res+= dp[row2][col1-1];

        if( row1 > 0 && col1 >0){
            res -= dp[row1-1][col1-1];
        }

        return dp[row2][col2] - res;
    }
};


//方法二：这样可以不用判断边界条件；

class NumMatrix {
public:
vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return ;
        }
        int m=matrix.size(),n=matrix[0].size();
        dp.resize(m+1 , vector(n+1,0));
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp.empty()){
            return 0;
        }
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};
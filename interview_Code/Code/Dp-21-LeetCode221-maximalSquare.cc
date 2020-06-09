#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
221. 最大正方形
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

*/

/*
https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
方法：动态规划：

1）状态分析：
    dp[i+1][j+1] 表示以第i行和第j列为右下角的正方形的最大边长；

2）转移方程：
    dp[i][j] = min( dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) +1;
3）初始状态：
    dp[i][0] = 0 ;
    d[0][j] =0;
4） 结果：
    res*res;
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int height = matrix.size();
        int width = matrix[0].size();

        int res = 0;

        vector<vector<int>> dp( height+1,vector<int>(width+1, 0));

        for( int i = 0 ;i < height ;i++){
            for( int j =0 ; j< width ; j++){
                if (matrix[i][j] == '0') continue;
                if( matrix[i][j] == '1'){
                    dp[i+1][j+1] = min( dp[i+1][j] ,min(dp[i][j+1],dp[i][j]) )+1;
                    res= max( dp[i+1][j+1] ,res);
                }
            }
        }

        return res*res;
    }
};

//方法二：直接利用matrix的size进行求解；

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int height = matrix.size();
        int width = matrix[0].size();

        vector<vector<int>> dp(height,vector<int>( width,0));
        
        int res  = 0 ;

        for(int i = 0  ;i < height; i++){
            for( int j = 0 ;j <width ;j++){

                if( i==0 || j== 0){
                    dp[i][j] = matrix[i][j]-'0';
                }else if( matrix[i][j] == '1'){
                    dp[i][j] = min( dp[i-1][j-1] ,min( dp[i-1][j],dp[i][j-1]))+1;
                }

                res = max( res, dp[i][j]);
            }
        }
        return res*res;

    }
};
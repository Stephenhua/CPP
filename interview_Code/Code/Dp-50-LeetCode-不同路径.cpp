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
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



例如，上图是一个7 x 3 的网格。有多少可能的路径？

 

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28
 

提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10 ^ 9
*/


/*
方法一：动态规划

1）状态定义：dp[i][j]表示在（i,j）的位置，其有多少条路径；

2）状态转移方程：dp[i][j] = dp[i-1][j] +dp[i][j-1];

3）base case：当i =0 时，只有一个位置；当j= 0 时，只有一种方法;
时间复杂度：O(NM);
空间复杂度：O(nm)；
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0 ;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 0 ;i < m;  i++ ){
            for( int j = 0 ; j< n ;j++){
                if( i==0 ||j == 0 ){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j] +dp[i][j-1] ; 
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//方法二：直接使用一维的空间；
/*
为啥可以直接使用正序遍历：因为与dp[j]有关的数组都在其后方，所以覆盖之后并不会有影响；

*/
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n,1);

        for( int i =1 ; i  < m; i++){
            for(int j =1 ; j < n ;j++){
                dp[j] +=dp[j-1];
            }
        }

        return dp[n-1];
    }
};

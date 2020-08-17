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
718. 最长重复子数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

 

示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。
 

提示：

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

/*
思路：求解最长公共子串，必须连续的才可以；
思路一：采用动态规划的方法进行求解；
状态：dp[i][j]表示在A为i位置、B为j位置的时候，其具有多少连续数字的个数；
状态转移方程：
    当是A[i-1] == B[i-1]时，那么dp[i][j] = dp[i-1][j-1] +1;
    当 A[i-1] != B[i-1] 时，那么连续就会中断，dp[i]p[j] = 0 ;
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0 ;
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));

        for(int i  = 1 ; i <= A.size() ; i++){
            for(int j =1 ; j <= B.size() ; j++){
                if( A[i-1] == B[j-1]){

                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = 0 ;
                }
                res = max( res, dp[i][j]);
            }
        }
        return res;
    }
};

//通过一维数组进行优化，需要将里面的遍历改为倒叙遍历，才能实现；

class Solution2 {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        int res = 0 ;

        vector<int> dp(B.size()+1,0);

        for(int i = 1 ; i < A.size() ; i++){

            for( int j = B.size() ; j>=1 ;j--){
                if( A[i-1] == B[j-1]){
                    dp[j] = dp[j-1] + 1;
                }else{
                    dp[j] = 0 ;
                }
                res = max( res , dp[j]);
            }
        }

        return res;
    }

};
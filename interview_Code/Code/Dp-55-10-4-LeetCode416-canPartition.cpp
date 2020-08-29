#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
416. 分割等和子集
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

*/

/*

解题思路：动态规划
1）状态分析： dp[i][j]表示前i个数字进行选择，集合存在的和正好是j;
2) 转移方程：
    a) 对dp[i][j]转移方程
        如果不加当前的值 dp[i][j] = dp[i-1][j];继承前面的状态；
        如果选择的话，dp[i][j] = dp[i-1][j-nums[i]] ;
3) 初始状态；dp[0][0] = true;
        dp[i][0] =true ;
        dp[0][i] = false;
4) 输出结果： dp[size][target];

*/
class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i =0 ; i < nums.size() ; i++){
             sum +=nums[i];
        }

        if( sum %2 != 0 ){
            return false;
        }
        sum = sum/2;
        int size = nums.size();
        vector<vector<bool>> dp( size + 1 ,vector<bool>(sum+1, false) );

        for(int i =0 ; i<= size ;i++){
            dp[i][0] = true;
        }

        for(int i = 1 ; i <= size ; i++ ){
            for(int j = 1; j <= sum ; j++){
                if( j -nums[i] < 0 ){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[size][sum];
    }

};


//压缩空间；

class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i =0 ; i < nums.size() ; i++){
             sum +=nums[i];
        }

        if( sum %2 != 0 ){
            return false;
        }
        sum = sum/2;
        int size = nums.size();

        vector<bool> dp(sum+1 , false) ;

        dp[0] = true;

        for(int i = 0 ; i < size ; i++ ){
            for(int j = sum ; j>=0 ; j--){
                if( j-nums[i] >=0 ){
                    dp[j ] = dp[j] || dp[j-nums[i]];
                }
            }
        }
        return dp[sum];
    }

};

//方法三：采用递归形式进行求解；

class Solution {
public:
    int target;
    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for( int num :nums){
            sum += num;
        }

        if( sum %2 != 0){
            return false;
        }

        int size = nums.size();
        target = sum/2;//相当于约束条件；

        sort( nums.rbegin() ,nums.rend());
        return Core( nums,0,0,0);
    }

    bool Core( vector<int>& nums, int i ,int sum1 ,int sum2){
        if( sum1 == target || sum2 == target){
            return true;
        }

        if( sum1 > target || sum2 >target){
            return false;
        }

        return Core( nums, i+1, sum1+nums[i],sum2)||Core( nums,i+1, sum1,sum2+nums[i]);
    }


};
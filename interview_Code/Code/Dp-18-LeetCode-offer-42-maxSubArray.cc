#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
面试题42. 连续子数组的最大和
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100

*/


//动态规划；

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if( size == 0){
            return 0;
        }

        if( size == 1){
            return nums[0];
        }

        int res =nums[0];
        int temp = 0 ;
        for(int i =0 ;i <size ; i++){

            if(temp >= 0){

                temp += nums[i];

            }else{
                temp = nums[i];
            }
            
            res = max( res,temp);
        }
        return res;
     }
};

/*
动态规划的步骤：
1） 状态： dp[i]表示元素 nums[i]结尾的连续子数组的和；
2）状态转移策略：
    dp[i-1] < 0 ,对dp[i]没有贡献；
    dpi-1]  >= 0  ,对dp[i]的和有贡献；
    
3）状态转移方程：
    当dp[i-1] <0 ； dp[i] = nums[i];
    当dp[i-1] > 0，则dp[i] = dp[i-1] +nums[i];

4) 设计dp数组，保存子问题，避免重复计算；
5）进行压缩空间；
    
    */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if( size == 0){
            return 0;
        }

        if( size == 1){
            return nums[0];
        }

        int dp[size];
        int res =nums[0];

        dp[0] = nums[0];

        for(int i =1 ;i<size ;i++){
            
            dp[i] = max( dp[i-1]+nums[i] , nums[i]);
            res = max( dp[i] ,res);
        }
        return res;
     }
};
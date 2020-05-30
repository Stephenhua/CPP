#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//采用贪心的算法进行求解；
int maxSubArray(vector<int>& nums) {

    int curSum = 0 ;

    int maxSum = INT_MIN;

    int i;

    for( i= 0 ;i< nums.size() ;i++){

        curSum += nums[i];
        if( curSum > maxSum){
            maxSum = curSum;
        }
        //重新寻找字串；
        if(curSum < 0){
            curSum = 0 ;
        }
    }

    return maxSum;
}

//采用动态规划的而方式进行

int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;

    int numSize = int( nums.size());

    vector<int> dp(numSize);
    dp[0] = nums[0];
    res =dp[0];

    for(int i = 1 ;i <nums.size() ;i++){
        dp[i] =  max( dp[i-1]+ nums[i] , nums[i]);
        res = max( res ,dp[i]);
    }
    return res;
}
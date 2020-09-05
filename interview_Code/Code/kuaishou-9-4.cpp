#include <iostream>
#include <vector>

using namespace std;

/*
剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
*/

//方法一：动态规划
/*
dp[i]表示以i结尾的连续子数组的最大和；最大和 dp[i]dp[i] 中必须包含元素 nums[i]nums[i] ：保证 dp[i]dp[i] 递推到 dp[i+1]dp[i+1] 的正确性；如果不包含 nums[i]nums[i] ，递推时则不满足题目的 连续子数组 要求。

如果dp[i-1]< 0 ,说明dp[i-1]对dp[i]产生负贡献；
如果dp[i-1] > 0 ，说明dp[i-1]对dp[i]产生正的贡献，那么就应该相加；

*/

int maxSumValue( vector<int>& nums){

    vector<int> dp(nums.size() ,0 );
    dp[0] = nums[0];
    int res =nums[0];
    for(int i = 1 ;i < nums.size() ; i++){
        if(dp[i-1] > 0 ){
            dp[i] = dp[i-1] +1;
        }else{
            dp[i] = nums[i];
        }
        res = max(res,dp[i]);
    }
    return res;

}

//进行降为优化
int maxSubArray(vector<int>& nums){
    int res = nums[0];
    int pre = nums[0];
    for(int i = 1 ;i < nums.size() ;i++){
        if(pre >0){
            pre +=nums[i];
        }else{
            pre = nums[i];
        }
        res = max(res, pre);
    }
    return res;
}

//直接在原数组上面进行修改；

int maxSubArray(vector<int>& nums ){
    int res = nums[0];

    for(int i = 1 ; i < nums.size() ;i++){
        if( nums[i-1] > 0 ){
            nums[i] = nums[i-1] +nums[i];
        }
        res = max(res,nums[i]);
    }

    return res;
}
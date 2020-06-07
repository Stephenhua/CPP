#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
面试题 16.17. 连续数列
给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶：

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

*/

//动态规划；遇到大于0 ，直接加上，和最大值进行比较；，如果是小于-0，则直接跳过；

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int sum = temp ;
        for( int i=1 ;i <nums.size() ;i++){

            if( temp < 0){
                temp = nums[i];
            }else{
                temp +=nums[i];
            }

            if( sum < temp){
                
                sum = temp;
            }
        }
        return sum ;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return INT_MIN;

        int ans=nums[0],sum=0;

        for(int i=0;i<nums.size();i++){
            //求序列的和；
            sum += nums[i];
            ans = max(ans,sum);
            sum = max(sum,0);
        }
        return ans;
    }
};
//从前向后直接进行相加；和值在数组中；

class Solution {
public:
    int maxSubArray(vector<int>& nums)
{
    int numsSize = nums.size();
    if(numsSize == 0)
        return 0;
    int res = nums[0];
    for(int i = 1;i < numsSize;i++)
    {
        if(nums[i-1]>=0)
            nums[i] += nums[i-1];
        res = max(res,nums[i]);
    }
    return res;
}

};
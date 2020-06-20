#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;


/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int n = nums.size();
        if( n == 0){
            return 0;
        }

        int left = 0 ;
        int right = 0 ;
        int sum = 0 ;
        int minValue = INT_MAX;

        while( right < n){
            sum += nums[right];
            right++;

            while( sum >= s){//边界条件
                minValue = min( minValue ,right-left);//此时right正好是数组的后一个值；所以不用加1；
                sum -= nums[left];
                left++;
            }
        }

        return minValue ==INT_MAX ? 0: minValue;
    }
};
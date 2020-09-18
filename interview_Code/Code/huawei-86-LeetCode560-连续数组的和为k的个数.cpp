#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。


*/

/*
构建前缀和数组，以快速计算区间和；
注意在计算区间和的时候，下标有偏移。
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int size = nums.size();

        vector<int> dp( size+1, 0);

        dp[0] = 0;

        for(int i = 0 ; i< size ;i++){
            dp[i+1] = nums[i] + dp[i];
        }

        int count = 0 ;

        for(int left = 0 ; left < size ; left++ ){
            for(int right = left ; right < size ; right++){

                if( dp[right] - dp[left] == k  ){
                    count++;
                }

            }
        }

        return count;

    }
};
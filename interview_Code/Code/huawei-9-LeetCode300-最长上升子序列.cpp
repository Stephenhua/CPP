#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*
https://leetcode-cn.com/problems/longest-increasing-subsequence/
300. 最长上升子序列
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

*/

/*
思路一：动态规划：
1）列出状态：dp[i]表示以nums[i]结尾的上升子序列的长度，
2）状态转移方程，
    判断从0.。。i之间中作为开始元素，比较得到以i结尾的最长的上升子序列的长度；

语言描述：在下标 i 之前严格小于 nums[i] 的所有状态值中的最大者 + 1+1。

符号描述：
    dp[i] = max(dp[j]) + 1；// 0<=j << i ; num[j] < num[i];
3)考虑初始化
    dp[i] = 1 表示只有当前元素是长度为1的上升子序列；

4）考虑输出：
    res = max( dp[i]);

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);

        for(int i = 0 ;i < size ;i++){
            for(int j = 0 ;j < i ; j++ ){
                if(nums[j]<nums[i]){
                    dp[i] = max( dp[j]+1 , dp[i] );

                }
            }
        }
        
        int res = 0 ;
        for(int i = 0 ; i < dp.size() ; i++){
            res = max(res , dp[i]);
        }

        return res;
    }

};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
1458. 两个子序列的最大点积
给你两个数组 nums1 和 nums2 。

请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。

数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是 [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。

 

示例 1：

输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
输出：18
解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
它们的点积为 (2*3 + (-2)*(-6)) = 18 。
示例 2：

输入：nums1 = [3,-2], nums2 = [2,-6,7]
输出：21
解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
它们的点积为 (3*7) = 21 。
示例 3：

输入：nums1 = [-1,-1], nums2 = [1,1]
输出：-1
解释：从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
它们的点积为 -1 。
 

提示：

1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 100
 

点积：

定义 a = [a1, a2,…, an] 和 b = [b1, b2,…, bn] 的点积为：

\mathbf{a}\cdot \mathbf{b} = \sum_{i=1}^n a_ib_i = a_1b_1 + a_2b_2 + \cdots + a_nb_n

这里的 Σ 指示总和符号。

*/

/*
思路：动态规划：
1）状态转移方程：
   想法1：dp[i][j]表示以num1[i]和num2[j]结尾的子序列的最大点积；
        第一种想法一定要包含nums1[i]和nums2[j]，因为以它们结尾。

   想法2：dp[i][j]表示以num1[i]和num2[j]为止的子序列最大点积；
        第二种想法就没有这个限制，以谁结尾无所谓，最主要是大。


2）状态转移方程：
    想法1：时间复杂度过高，不适合；
    想法2：通过选择num1[i]和num2[j]进行选择状态转移方程；
    （1）选择num1[i]和num2[j];
         不包括前面的 dp[i][j] = num1[i]*num2[j];
         包括前面的： dp[i][j] = max( dp[i][j],num1[i]*num2[j]+dp[i-1][j-1]);
    （2）只选择nums1[i] ,不选择nums[j];
        dp[i][j] = max( dp[i][j], dp[i][j-1]);
    （3）只选择nums2[j],不选择nums1[i];
        dp[i][j] = max( dp[i][j], dp[i-1][j]);
     (4) 两个都不选择
        dp[i][j] = max( dp[i][j] ,dp[i-1][j-1]);

 3)结果 dp[n][m];

*/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1e8));

        for(int i = 1 ;i <= n ;i++){
            for(int j = 1 ;j <= m ; j++){
                dp[i][j] = nums1[i-1]*nums2[j-1];
                dp[i][j] = max( dp[i][j] ,dp[i-1][j-1]+nums1[i-1]*nums2[j-1] );//元素的值是从0的下标开始的
                dp[i][j] = max( dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                dp[i][j] = max( dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};
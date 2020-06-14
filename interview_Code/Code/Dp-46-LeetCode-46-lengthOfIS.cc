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
300. 最长上升子序列
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。


*/
/*
动态规划：
1）状态定义： dp[i] 表示以nums[i]结尾的上升子序列的长度，包括nums[i]；
2）状态转移方程：
    遍历到 nums[i] 时，需要把下标 i 之前的所有的数都看一遍；
    只要 nums[i] 严格大于在它位置之前的某个数，那么 nums[i] 就可以接在这个数后面形成一个更长的上升子序列；
    因此，dp[i] 就等于下标 i 之前严格小于 nums[i] 的状态值的最大者 +1。
    语言描述：在下标 i 之前严格小于 nums[i] 的所有状态值中的最大者 +1。
    所以：dp[i] = max(dp[j]) +1;0<=j<i;nums[j]<nums[i];

3)初始化 ： dp[i] = 1; 1 个字符只能时长度为1的上升子序列；
4）输出 ： max[dp[i]]; 0<i<=n;
5) 状态压缩：由于最后都要用，所以可以不能进行呀u哦
时间复杂度：O(N^2)O(N 2)，这里 NN 是数组的长度，我们写了两个 for 循环，每个 for 循环的时间复杂度都是线性的。
空间复杂度：O(N)O(N)，要使用和输入数组长度相等的状态数组，因此空间复杂度是 O(N)O(N)。

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int size = nums.size();

        if( size < 2){
            return size;
        }

        vector<int> dp(size ,1);

        for( int i = 1 ;i < size ;i++){
            for( int j = 0 ; j < i ;j++){
                if( nums[j]< nums[i]){//如果前面的值小于当前的值，那么直接进行变化；

                    dp[i] = max( dp[i] ,dp[j]+1);

                }

            }
        }

        int res = 0 ;
        for( int i = 0 ; i < size ;i++){
            res  = max( res, dp[i]);
        }

        return res;
        
    }
};
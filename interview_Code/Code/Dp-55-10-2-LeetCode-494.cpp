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
494. 目标和
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

 

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
 

提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。

*/


/*
方法一：转换为0-1背包问题；
通过添加符号进行分裂，将正数集合P和负数集合相减 Sum(P) - Sum(N) = target；找出有多少种组合方式可以实现；

Sum(P) -Sum(N) +Sum{p} +Sum{N} = target+ Sum{p} +Sum{N} ;
=> 2Sum(P) = target +Sum(num);
=> Sum(p) = (target+Sum(num))/2;
转为为 在 num数组中找出和为P的方式有多少种；
由此可以转为0-1背包问题，要么添加，要不不进行添加；
dp[i][j]表示前 i个数，和为j的组合数有多少个；
或者直接转为LeetCode377的问题
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        int sum = 0 ;
        for(int i = 0 ;i < size ;i++){
            sum += nums[i];
        }
        if ((S + sum) % 2 == 1 || S > sum) return 0;

        int target = (sum +S )/2;

        vector<int> dp(target+1,0);

        dp[0] =1 ;

        for(int i = 0 ;i < size ;i++){
            for(int j = target ; j>= 0 ; j--){
                if( j >= nums[i]){
                    dp[j] += dp[j-nums[i]];
                }
            }
        }

        return dp[target];

    }
};

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
377. 组合总和 Ⅳ
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
进阶：
如果给定的数组中含有负数会怎么样？
问题会产生什么变化？
我们需要在题目中添加什么限制来允许负数的出现？
*/


/*
方法：动态规划；

1、状态：dp[i] ：对于给定的由正整数组成且不存在重复数字的数组，和为 i 的组合的个数。
2） 状态转移方程：dp[i]= dp[i - nums[0]] + dp[i - nums[1]] + dp[i - nums[2]] 。。。。
3）
4） 结果
举个例子比如nums=[1,3,4],target=7;
        //dp[7]=dp[6]+dp[4]+dp[3]
        //其实就是说7的组合数可以由三部分组成，1和dp[6]，3和dp[4],4和dp[3];
*/


class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0 ){
            return 0;
        }
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 0  ;i <= target ; i++){
            for( auto num : nums){
                dp[i] += dp[i-num];
            }
        }
        return dp[target];

    }
};
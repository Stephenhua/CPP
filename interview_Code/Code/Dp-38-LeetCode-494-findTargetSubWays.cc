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
动态规划：
1）状态分析：dp[i][j] 表示nums中0—~i的下标元素进行加减可以得到j的方法数量；
2）状态转移方程； dp[i][j] = dp[i-1][j-nums[i]] +dp[i-1][j+nums[i]]; 对nums[i] 进行+- 来判断数量；
3）dp数组的定义： 整个表格区域应该是分为三部分：-/0/+。那么对应的表格的每一行的长度t就可以表示为：t=(sum*2)+1，其中一个sum表示nums中执行全部执行加/减能达到的数，而加的1显然是中间的0.
4）初始状态：
        状态： 目标和；
        选择：+和-数组中的元素；
    length = 2*sum +1;
结果 dp[len-1]p[sum+s];

*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

            if( nums.size() == 0){
                return 0 ;
            }

            int sum = 0 ;
            for(int i =0 ; i< nums.size() ;i++){
                sum += nums[i];
            }
            
            if( abs(S) > abs( sum)){
                return 0;
            }

            vector <vector <int>> dp(nums.size(),vector<int>(2*sum+1,0));

            if( nums[0] == 0){
                dp[0][sum] = 2;
            }else{
                dp[0][sum+nums[0]] = 1;
                dp[0][sum - nums[0]] = 1;
            }

            for( int i= 1; i<nums.size() ;i++){
                for( int j =0 ; j < (2*sum+1);j++){
                    int left = ( j - nums[i]) >= 0 ? j-nums[i] : 0 ;
                    int right = ( j+ nums[i]) < (sum *2 +1) ? j+nums[i] :0;
                    dp[i][j] = dp[i-1][left] +dp[i-1][right];
                }
            }

            return dp[nums.size()-1][sum+S];//num+S 表示正数；

    }
};

//方法二：通过0-1背包的问题解决；
/*
分两步走：
1.把该问题转换成0-1背包问题，可惜我一上来就卡死在这里了，其实是很简单的数学关系，当时就是想不出，把评论区大佬的讲解贴在这吧：
    原问题：找到nums一个正子集和一个父子集，使得总和等于target；

2） p表示正子集；N表示父子集；例如 nums = {1,2,3,4,5}，target= 3 ；一个能解决的方案是： +1-2+3—4+5 = 3 ；这是正子集P={1，3，5}，负子集 N={2，4}；

3） sum{p} -sum{N} = target;
    sum{p}+sum{N} +sum{p} -sums{N} = target +sum{p}+sum{N};
    2sum{p} = target+ sum(nums);

4)问题进行转换： 找到一个nums的一个子集P,使得sum(p) = (target + sum(nums)) /2;

所以物品就相当于nums元素,P就是背包。选物品，就是把对应的数放进正子集P里，不选则不放，最终要求P的元素和，即背包容量，刚好等于(target + sum(nums)) / 2

dp[i][j]表示从前0——i中选出若干件放入到容量为j的背包中，只能从i-1中进行选择，所以需要继承dp[i-1][j]; 0 <= j <w[j];

dp[i][j] 分为两种情况陶昆讨论，当不将 第i件物品放入背包中，则只能从j-1中进行选择； dp[i-1][j];
        当讨将i放入到背包中，dp[i-1][j-W[j]] ; 不放j时， dp[i-1][j];

1----如何更新dp数组？
遍历nums，遍历的数记作num
再逆序遍历从P到num，遍历的数记作j
更新dp[j] = dp[j - num] + dp[j]
这样遍历的含义是，对每一个在nums数组中的数num而言，dp在从num到P的这些区间里，都可以加上一个num，来到达想要达成的P。
举例来说，对于数组[1,2,3,4,5]，想要康康几种方法能组合成4,那么设置dp[0]到dp[4]的数组
假如选择了数字2,那么dp[2:5]（也就是2到4）都可以通过加上数字2有所改变，而dp[0:2]（也就是0到1）加上这个2很明显就超了，就不管它。
以前没有考虑过数字2,考虑了会怎么样呢？就要更新dp[2:5]，比如说当我们在更新dp[3]的时候，就相当于dp[3] = dp[3] + dp[1],即本来有多少种方法，加上去掉了2以后有多少种方法。因为以前没有考虑过2,现在知道，只要整到了1,就一定可以整到3。

2----为什么以这个顺序来遍历呢？
假如给定nums = [num1,num2,num3]，我们现在可以理解dp[j] = dp[j-num1] + dp[j-num2] + dp[j-num3]。

但是如何避免不会重复计算或者少算？要知道，我们的nums并不是排序的，我们的遍历也不是从小到大的。

我们不妨跟着流程走一遍

第一次num1，仅仅更新了dp[num1] = 1，其他都是0+0都是0啊都是0
第二次num2，更新了dp[num2] = 1和dp[num1+num2] = dp[num1+num2] + dp[num1] = 1,先更新后者。
第三次num3，更新了dp[num3] = 1和dp[num1+num3] += 1和dp[num2+num3] += 1和dp[num1+num2+num3] += 1。按下标从大到小顺序来更新。
......

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        for (const int &it : nums) sum += it;
        if ((S + sum) % 2 == 1 || S > sum) return 0;
        S = (S + sum) / 2;
        int *dp = new int[S + 1];
        memset(dp, 0, (S + 1) * sizeof(int));
        dp[0] = 1;
        for (const int &it : nums) {
            for (int j = S; j >= it; j--)
                dp[j] += dp[j - it];
        }
        int ans = dp[S];
        delete[] dp;
        return ans;
    }
};

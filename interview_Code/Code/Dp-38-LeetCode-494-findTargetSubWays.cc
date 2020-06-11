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

//方法二：

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

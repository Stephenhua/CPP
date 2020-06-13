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
673. 最长递增子序列的个数
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。


*/


/*
题目分解：

1）记录最长子序列的长度  2）最长子序列长度一定的情况下，序列的个数；

动态规划：
1）状态定义： dp[i]表示以i为位置结尾的，最长连续递增序列的长度；count[i] 表示以nums[i]结尾的最长递增子序列的组合数量，；

2）状态转移方程：
    遍历到 nums[i] 时，需要把下标 i 之前的所有的数都看一遍；
    只要 nums[i] 严格大于在它位置之前的某个数，那么 nums[i] 就可以接在这个数后面形成一个更长的上升子序列；
    因此，dp[i] 就等于下标 i 之前严格小于 nums[i] 的状态值的最大者 +1。
    语言描述：在下标 i 之前严格小于 nums[i] 的所有状态值中的最大者 +1。
    所以：dp[i] = max(dp[j]) +1;0<=j<i;nums[j]<nums[i];

    对于nums[i]而言：
    1） 当dp[j]+1＞dp[i],说明第一次找到以nums[i]nums[i]为结尾的最长递增子序列，长度为dp[j]+1，进而可以推出counter[i]=counter[j], 以nums[i]结尾的最长递增子序列的组合数=以nums[j]nums[j]结尾的最长递增子序列的组合数,这个可以这么理解：当[...j][...j]形成的组合数是值的话，其每一种组合结尾补上[i][i],即[...j,i][...j,i],对于组合数本身是没有增加的，还是AA值，唯独只是递增子序列的长度+1+1了
    2）当dp[j]+1=dp[i],说明这个长度已经找到过一次了，counter[i]+=counter[j]，现在的组合方式+counter[j]的组合方式

3）初始状态：
    1）dp[i] = 1 ;
    2)count[i] = 1;
4） 更具dp[i]选出最长子序列，然后秋娥出个数；

*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int num = nums.size();

        if( num ==1 ){
            return 1;
        }else if( num == 0){
            return 0 ;
        }

        vector<int> dp( num ,1);
        vector<int> counter( num ,1);

        int res = 0 ;
        for( int i = 0 ; i <num ;i++){
            for( int j = 0 ; j < i ;j++){
                if( nums[j] < nums[i]){
                    if( dp[j]+1 > dp[i] ){//代表第一次遇到最长子序列
                        dp[i]= max( dp[i] ,dp[j]+1);
                        counter[i] = counter[j];
                    }else if( dp[j]+1== dp[i]){ //# 代表已经遇到过最长子序列
                        counter[i] +=counter[j];
                    }
                }
            }

            res = max( res, dp[i]);
        }

        int max = 0 ;
        for(int  i = 0 ; i < num ;i++){
            if( dp[i] == res){//由于最长子序列存在相同的部分，所以需要进行相加；
                max += counter[i];
            }
        }

        return max;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
152. 乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 
示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

/*

由于设计到乘法运算，那么在一次运算给的过程中，出现下面的情况；
1） 如果nums[i] 《0 ， max 变为min ,min 变为max;
2） 如果nums[i] > 0 , max 依旧为max, min 依旧为min;
3) nums[i] == 0 , 直接和前面的最大值比较；


*/


/*

方法一:
1) 状态分析；
    dp[i][j]表示以nums[i] 结尾的连续 子数组的最值， j表示最大值和最小值；
    j =0 ,表示最小值；
    j =1 , 表示最大值；

3） 状态定义；
2） 转换方程；
    由于状态的设计 nums[i] 必须被选取（请大家体会这一点，这一点恰恰好也是使得子数组、子序列问题更加简单的原因：当情况复杂、分类讨论比较多的时候，需要固定一些量，以简化计算）；

    nums[i] 的正负和之前的状态值（正负）就产生了联系，由此关系写出状态转移方程：

    当 nums[i] > 0 时，由于是乘积关系：
        最大值乘以正数依然是最大值；
        最小值乘以同一个正数依然是最小值；
    当 nums[i] < 0 时，依然是由于乘积关系：
        最大值乘以负数变成了最小值；
        最小值乘以同一个负数变成最大值；
    当 nums[i] = 0 的时候，由于 nums[i] 必须被选取，最大值和最小值都变成 00 ，合并到上面任意一种情况均成立。

        dp[i][0] = min(nums[i], nums[i] * dp[i - 1][0]) if nums[i] >= 0
        dp[i][1] = max(nums[i], nums[i] * dp[i - 1][1]) if nums[i] >= 0

        dp[i][0] = min(nums[i], nums[i] * dp[i - 1][1]) if nums[i] < 0
        dp[i][1] = max(nums[i], nums[i] * dp[i - 1][0]) if nums[i] < 0

3） 初始化：
    dp[i][0] = nums[0];
    dp[i][1] = nums[1];

4） 最终结果：
    dp[i][1];

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        if( size == 0 ){
            return 0 ;
        }

        if( size == 1 ){
            return nums[0];
        }

        vector<vector<int>> dp( size ,vector<int>( 2,0));

        dp[0][0] = nums[0] ;
        dp[0][1] = nums[0];

        for( int i = 1 ;i < size ;i++){
            if( nums[i] >= 0 ){

                dp[i][0] = min( nums[i] , nums[i]* dp[i-1][0]);
                dp[i][1] = max( nums[i] , nums[i]* dp[i-1][1]);
            }else{
                dp[i][0] = min( nums[i] , nums[i]*dp[i-1][1]);
                dp[i][1] = max( nums[i] , nums[i]* dp[i-1][0]);
            }
        }

        int res = dp[0][1];

        for( int i =0 ;i < size ;i++){
            res= max( res, dp[i][1]);
        }
        return res;

    }
};

//考虑表格复用；
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        if( size == 0 ){
            return 0 ;
        }

        if( size == 1 ){
            return nums[0];
        }

        int preMax = nums[0] ;
        int preMin = nums[0] ;

        int curMax ,curMin;

        int res = nums[0];

        for( int i =0 ;i < nums.size() ;i++){

            if( nums[i] >= 0){
                curMax =max( nums[i] ,nums[i]*preMax);
                curMin = min( nums[i] ,nums[i]*preMin);
            }else{
                curMax = max( nums[i] ,nums[i]* curMin);
                curMin = min( nums[i] ,preMin* nums[i]);
            }

            res = max( res, curMax);

            preMin = curMin;
            preMax = curMax;
        }        
        return res;
    }

};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if( nums.size() ==  1 ){
            return nums[0];
        }

        int res = INT_MIN;

        int imax =1 ,imin =1 ;

        int  size = nums.size() ;

        for( int i = 0 ;i <size ;i++){

            if( nums[i]  < 0){
               int temt= imax;
               imax = imin;
               imin = temt;
            }

            //最大值和前面的状态进行相比较；
            imax = max( nums[i]* imax, nums[i]);
            imin = min( nums[i]*imin , nums[i]);

            res = max( res, imax);//和最终的结果进行相比较

        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>

using namespace std;

/*
面试题14- I. 剪绳子
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58
注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

*/

/*
利用动态规划进行求解；
dp[i]存储族弟啊的乘积；

*/
class Solution {
public:
    int cuttingRope(int n) {
        if( n <2 ){
            return 0 ;
        }

        if( n == 2 ){
            return 1;
        }else if( n==3 ){
            return 2;
        }

        vector<int> dp(n+1,0) ;//n存储在n-1位；

        dp[0] = 0 ;
        dp[1] = 1 ;
        dp[2] = 2;
        dp[3] = 3;
  

        for( int i =    4 ; i <= n;i++){
             int res = 0 ;
            for( int j = 0 ;j <= i/2;j++){
                int tempValue =  dp[j]*dp[i-j];
                if( res < tempValue){
                    res = tempValue;
                }
                 dp[i] = res;
            }
            

        }
        return  dp[n];
    }
};


//方法二：采用贪心策略进行求解：时间复杂度为o（logN);


 class Solution {
   int cutRope(int length) {
        if(length < 2)
            return 0;
        if(length == 2)
            return 1;
        if(length == 3)
            return 2;

        // 尽可能多地减去长度为3的绳子段
        int timesOf3 = length / 3;

        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
        // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
        if(length - timesOf3 * 3 == 1)
            timesOf3 -= 1;

        int timesOf2 = (length - timesOf3 * 3) / 2;

        return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));

    }
};
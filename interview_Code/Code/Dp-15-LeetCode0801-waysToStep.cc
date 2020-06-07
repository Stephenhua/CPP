#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
面试题 08.01. 三步问题
三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

示例1:

 输入：n = 3 
 输出：4
 说明: 有四种走法
示例2:

 输入：n = 5
 输出：13
提示:

n范围在[1, 1000000]之间

*/

//动态规划-dp[n] = dp[n-1]+dp[n-2]+dp[n-3];

class Solution {
public:
    int waysToStep(int n) {
        if( n <= 2){
            return n;
        }
        if( n== 3 ){
            return 4;
        }
        int sum0,sum1,sum2,temp;
        sum0 =1 ;
        sum1= 2;
        sum2= 4;
        for( int i =4 ;i <=n; i++){
            temp = ((sum0+sum1) %100000000007 +sum2)% 1000000007;
            sum0 = sum1;
            sum1 = sum2 ;
            sum2 = temp;
        }
        return sum2;
    }
};
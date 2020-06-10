#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
413. 等差数列划分
如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
以下数列不是等差数列。

1, 1, 2, 5, 7
 

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。

如果满足以下条件，则称子数组(P, Q)为等差数组：

元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。

函数要返回数组 A 中所有为等差数组的子数组个数。

 

示例:

A = [1, 2, 3, 4]

返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。

*/

/*
动态规划
1—判断条件，dp[i]表示以A[i]为结尾的等差子数组的个数，其中有可能有很多个子数组；

2-状态转移方程： dp[i] =dp[i-1]+ 1 ; A[i]-A[i-1] = A[i-1]-A[i-2];
3-初始条件dp[0] =0 ;dp[1] = 0 ;dp[2] = A[2]-A[1] == A[1]-A[0] ?1:0;
4-输出dp[A.size()];


*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        vector<int> dp(size ,0);
        if( size < 3){
            return 0;
        }
        int res = 0 ;

        dp[0] = 0 ;
        dp[1] = 0 ;
        dp[2] = A[2]-A[1] == A[1] -A[0] ? 1:0;
        //先进行每个数字结尾进行计算；
        for(int i =3 ;i <size ;i++){
            dp[i] = ((A[i]-A[i-1])==(A[i-1]-A[i-2]))? dp[i-1]+1 :0;
        }
        //直接计算最终的值；
        for(int i =0 ;i < size ;i++){
            res +=dp[i];
        }
        return res;
    }
};
//方法二：动态规划，先进行判断，然后直接进行相加；

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if( A.size() < 3){
            return 0;
        }

        vector<int> dp(A.size() ,0);//先进行初始化；

        for( int i=2 ;i < A.size() ;i++){
            if( A[i]-A[i-1]== A[i-1]-A[i-2]){
                dp[i] = dp[i-1]+1;
            }
        }
        int sum = 0 ;
        for( int i = 0 ;i <A.size() ;i++){
            sum += dp[i];
        }
        return sum ;
    }
};
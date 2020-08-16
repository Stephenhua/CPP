#include <iostream>
#include <vector>
using namespace std;


/*
https://leetcode-cn.com/problems/three-steps-problem-lcci/
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
class Solution {
public:
    int waysToStep(int n) {
        vector<int> res(n+1,0);

        if( n <= 2 ){
            return n ;
        }

        res[0] = 1;
        res[1] = 1;
        res[2] = 2;
        res[3] = 4 ;

        for( int i = 4 ;i <= n ; i++){

            res[i] = res[i-1]+res[i-2]+res[i-3];

        }
        return res[n];
    }
};

//方法二：采用临时变量的方式进行求解；

class Solution {
public:
    int waysToStep(int n) {

        if( n <=2 ){
            return 2;
        }

        if( n == 3){
            return 4 ;
        }

        int sum0 ,sum1,sum2,temp;

        sum0=1;
        sum1 =2 ;
        sum2 =4;

        for( int i = 4 ;i <= n ;i++){
            temp = sum0+sum1+sum2;
            sum0 = sum1;
            sum1 = sum2;
            sum2 = temp;
        }

        return sum2; 
    }
};
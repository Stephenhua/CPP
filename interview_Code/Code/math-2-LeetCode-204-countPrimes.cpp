#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <stack>

using namespace std;

/*
204. 计数质数
统计所有小于非负整数 n 的质数的数量。

示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*/

/*
质数：只能被1和本身整除的数


*/
//方法一：暴力法

class Solution {
public:
    int countPrimes(int n) {

        int count =  0 ;

        for( int i = 2 ; i< n ;i++){
            bool sign = true;

            for( int j =2; j< i; j++){
                if( i % j == 0){
                    sign = false;
                    break;
                }
            }

            if( sign){
                count++;
            }
        }
        return count ;
    }
};

/*

方法二：优化暴力法
里面的循环可以直接到第二轮即可；
对于偶数而言，除了2以外，其他的偶数一定不是质数；

*/

class Solution {
public:
    int countPrimes(int n) {
        if( n < 3){
            return 0;
        }

        //从3开始验算，所以初值为1；

        int count =  1;

        for( int i = 3 ; i< n ; i++){

            if( i &1 == 0){
                continue;
            }

            bool sign = true;

            for( int  j = 3 ; j*j <= i ;j+=2){

                if( i % j == 0 ){
                    sign = false;
                    break;
                }
            }

            if( sign){
                count++;
            }
        }

        return count;
    }
};

/*
方法三：厄拉多塞筛法；
通过排序2的倍数、3的倍数、5的倍数、7的倍数、以及11的倍数，然后继续进行循环；
*/

class Solution {
public:
    int countPrimes(int n) {
        int count = 0 ;
        vector<bool> signs(n, true);

        for( int i = 2 ; i< n ;i++){
            
            if( signs[i]){
                count++;
                for( int j = i + i ; j< n ;j += i){
                    signs[j] = false;
                }
            }
        }
        return count ;
    }

};


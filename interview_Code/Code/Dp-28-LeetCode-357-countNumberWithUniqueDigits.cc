#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
357. 计算各个位数不同的数字个数
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。

示例:

输入: 2
输出: 91 
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

*/

/*
动态规划，可以得到一定的
从个位，十位、百位、千位，其余前面的位数有关系；

*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n == 0 ){
            return 1;
        }

        int res = 10 ,num =9*9;

        for( int i =2 ;i <= min(n,10);i++){
            res += num ;
            num = num*(10-i);
        }
        return res;
    }
};
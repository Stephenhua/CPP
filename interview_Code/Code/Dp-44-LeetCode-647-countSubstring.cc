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
647. 回文子串
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

*/

/*
动态规划：
1） 状态分析：
    字符串的位置i到j之间是否为回文子串， dp[i][j] = true or false;
2) 状态转移方程：
    如果 s[i] == s[j] 那么 dp[i][j] = dp[i+1][j-1] 只需要判断dp[i+1][j-1]是不是回文字符；
    否则 ； dp[i][j] = false;

3) 初始化： dp[i][i] = true ; 其余小于0 ；
4） 输出结果，统计二维表中的为true的个数；
5）
*/

class Solution {
public:
    int countSubstrings(string s) {
        if( s.empty()){
            return 0 ;
        }

        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int res = 0;

        for(int i = 0 ; i< n ;i++){
            dp[i][i] = true;
        }

        for( int i = n-1 ;i >=0 ;i--){
            for(int j=i; j <n; j++){
                if( s[i] == s[j] ){
                    if( j-i <= 1){

                        dp[i][j] = true;

                    }else{

                        dp[i][j] = dp[i+1][j-1];

                    }
                }else{
                    dp[i][j] = false;
                }
                if( dp[i][j]){
                 res++;
                }

            }
        }

        return res;
    }
};

//采用中心法进行求解；速度更快；
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        if(!len)  return 0;
        /* expansion */
        int left, right, res = 0;
        for(int mid = 0; mid < 2*len-1; ++mid) {//遍历中心点；
            /* amazing discovery ! */

            //左边的点和右边的点；

            left = mid / 2;
            right = left + mid % 2;

            while(left >= 0 && right < len && s[left] == s[right]) {
                ++res;
                --left;
                ++right;
            }
        }
        return res;
    }
};
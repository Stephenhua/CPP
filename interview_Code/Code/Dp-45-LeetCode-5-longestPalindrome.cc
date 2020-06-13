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
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

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
    string longestPalindrome(string s) {

        if( s.empty()){
            return s ;
        }

        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int maxLength = 1; 
        int begin = 0 ;

        for(int i = 0 ; i< n ;i++){
            dp[i][i] = true;
        }

        for( int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i;  j++){

                if( s[i] == s[j] ){
                    if( i-j < 3 ){

                        dp[j][i] = true;

                    }else{

                        dp[j][i] = dp[j+1][i-1];

                    }
                }
                if( dp[j][i]){
                    if(maxLength < i-j+1){
                        maxLength = i-j+1 ;
                        begin = j ;
                    }
                } 
            }

        }
        return s.substr(begin,maxLength);
      
    }
};

//中心法；
/*
我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 1 个这样的中心。

你可能会问，为什么会是 2n - 1 个，而不是 n 个中心？

因为回文的中心要区分单双。

假如回文的中心为 双数，例如 abba，那么可以划分为 ab bb ba，对于n长度的字符串，这样的划分有 n-1 种。

假为回文的中心为 单数，例如 abcd, 那么可以划分为 a b c d， 对于n长度的字符串，这样的划分有 n 种。

对于 n 长度的字符串，我们其实不知道它的回文串中心倒底是单数还是双数，所以我们要对这两种情况都做遍历，也就是 n+(n-1) = 2n - 1，所以时间复杂度为 O(n)。

当中心确定后，我们要围绕这个中心来扩展回文，那么最长的回文可能是整个字符串，所以时间复杂度为 O(n)。

所以总时间复杂度为 O(n^2)

*/
class Solution {
public:

    string longestPalindrome(string s) {

        if( s.length() <= 1 ){
            return  s;
        }

        int start = 0  ,end = 0 ;
        int  mlen = 0 ;//记录最大回文子串的长度

        for( int i = 0 ; i< s.length() ;i++){
            int len1 = Core( s,i,i);//一个元素为中心；
            int len2 = Core( s,i,i+1) ;//两个元素为中心；
            mlen = max(max( len1 ,len2),mlen);

            if( mlen > end -start+1){
                start = i-(mlen-1)/2;
                end = i+ mlen/2;
            }
        }

        return s.substr( start , mlen);
    }
private:

    int Core( string s, int left ,int right){
        int L = left ;
        int R  = right ;
        while( L >= 0  && R < s.length() && s[L] == s[R]){
            //计算以left和right为中心的回文串长度；
            L--;
            R++;
        }

        return R-L-1;
    }
};
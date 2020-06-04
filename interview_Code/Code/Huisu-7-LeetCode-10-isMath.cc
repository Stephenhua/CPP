#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/
/*

dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zui-xiang-xi-jie-da-you-jian-zhi-/
*/
bool isMatch(string s, string p) {

// 这里dp矩阵是要大一圈的，用来处理s或者p为空串的情况，矩阵的行标i对应s的i-1，矩阵的列标j对应p的j-1
    bool dp[s.length()+1][p.length()+1] ;

// s和p都是空串的时候自然true

    dp[0][0] = true;

    //初始化第一行
    for( int i = 0 ; i< p.length() ;i++){

        if( p[i]=='*' && dp[0][i-1]){

            dp[0][i+1] = true;

        }else{

            dp[0][i+1] = false;

        }
    }

    if( s.length()  >=1 ){

        for( int i =1 ;i< s.length()+1 ;i++){

            dp[i][0] = false;
        }
    } 

    for( int i =0 ;i < s.length( ) ; i++){

        for( int j =0 ; j <p.length() ; j++){

            if( s[i] == p[j] || p[j] == '.'){

                dp[i+1][j+1] = dp[i][j];

            }else if( p[j] == '*'){

                if( p[j-1] != s[i] && p[j-1] !='.' ){

                    dp[i+1][j+1] = dp[i+1][j-1];

                }else{
                    if( dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]){
                        dp[i+1][j+1] = true;
                    }else{
                        dp[i+1][j+1] = false;
                    }
                }
            }else{
                dp[i+1][j+1] = false;
            }
        }
    }
    return dp[s.length()][p.length()];
    
}
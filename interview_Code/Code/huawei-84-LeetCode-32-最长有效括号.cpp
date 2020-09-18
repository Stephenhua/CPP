#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;


/*
https://leetcode-cn.com/problems/longest-valid-parentheses/
32. 最长有效括号
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;

        int max_num = 0 ;
        int start = -1 ;

        if( s.size() < 2 ){
            return 0 ;
        }

        for(int i = 0 ; i < s.size() ; i++ ){
            if( s[i] == '('){
                stk.push(i);
            }else{

                if( stk.size() == 0 ){
                    start = i ;//当栈为空的时候，确定的当前状态；
                }else{
                    stk.pop();//弹出栈顶元素，表明已经与最近的进行了匹配；
                    if( stk.empty()){
                        max_num = max( max_num, i - start );
                    }else{
                        max_num = max( max_num , i -stk.top());
                    }
                }
            }
        }
        return max_num ;
        
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size,0);

        int maxVal = 0 ;
        for(int i = 1 ; i < size ; i++){
            if( s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = 2;
                    if( i -2  >= 0 ){

                        dp[i] = dp[i]+dp[i-2];

                    }
                }else if( dp[i-1] >0 ){
                    if( (i-dp[i-1]-1) > 0 && (s[i-dp[i-1]-1] == '(')){
                        dp[i] = dp[i-1] +2 ;
                        if( ( i -dp[i-1]-2) >= 0 ){
                            dp[i] = dp[i]+dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            maxVal = max( maxVal , dp[i]);
        }
        return maxVal;

    }

};
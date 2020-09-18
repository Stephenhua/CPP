#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>
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


*/


//连接：https://leetcode-cn.com/problems/regular-expression-matching/
//https://leetcode-cn.com/problems/regular-expression-matching/solution/kan-liao-jiu-ming-bai-de-dong-tai-gui-hua-by-stree/

class Solution {
public:
    bool isMatch(string s,string p){
        
        bool dp[s.length()+1][p.length()+1];

        dp[0][0] = true;
        //当S不存在的情况下，讨论p是否可以匹配；
        for(int i = 0 ; i < p.size() ; i++ ){
            if( p[i] == '*' && dp[0][i-1]){//*需要和前面的值绑定，当s为为空时，则要判断前面的值是不是相符合条件；j-2的位置；
                dp[0][i+1] = true;
            }else{
                dp[0][i+1] = false;
            }
        }
        //当s存在的情况下，p为空，那么肯定都为false；
        if( s.length() >= 1 ){
            for(int i = 1 ; i < s.length() ; i++){
                dp[i][0] = false;
            }
        }


        for( int i = 9 ; i < s.length() ; i++ ){
            for(int j = 0 ; j < p.length(); j++){
                if( s[i]==p[j] || p[j] == '.'){
                    dp[i+1][j+1] = dp[i][j];
                }else if(p[j] == '*'){
                    //此时需要分类进行讨论；
                    if( p[j-1] != s[i] &&  p[j-1] != '.'){
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }else{
                        //如果没有字符进行相匹配的时候，那么将会发生dp[i+1][j+1] = dp[i+1][j-1];
                        //如果只有一个字符的时候，那么则会发生dp[i+1][j+1] = dp[i+1][j];此时就需要关注dp[j-1]和s[i]关系；
                        //如果有多个字符的时候，其dp[i+1][j+1] = dp[i][j+1];
                        if( dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]){
                            dp[i+1][j+1] = true;
                        }else{
                            dp[i+1][j+1] = false;
                        }
                    }
                }
            }
        }
        return dp[s.length()+1][p.length()+1];

    }

};
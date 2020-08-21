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



*/

/*
思路：动态规划

1）状态：dp[i][j]表示S的 前j个字符有多少种表示T的前i个字符的方式；
2）状态转移方程：
    如果s[i] != s[j]，那么求解dp[i][j]的话只能，求解dp[i][j-1]就是前j-1个字符有多少种可以有表示前i个字符的方式；
    如果s[i] == s[j]，那么应该有两种方式的组合；
        a) 匹配时，包含S的第j个字符，这时dp[i][j]= dp[i-1][j-1]；
        b) 不包含S的第j个字符，这时dp[i][j] = dp[i][j-1];
3) base case：
    如果S为空，那么匹配的话，dp[i][0] = 0 ;
    如果T为空，那么匹配的话：dp[0][j] = 1 ;
    如果两个都为空，那么dp[0][0] = 1;也是匹配的；
*/

class Solution {
public:
    int numDistinct(string s, string t) {

        if( s.size() == 0 ){
            return 0 ;
        }

        vector<vector<long long int>> dp(t.size(),vector<long long int>(s.size(), 0));


        for( int j = 0 ; j < s.size() ; j++){
            dp[0][j] = 1;
        }

        //状态转移方程；

        for( int i = 1; i <= t.size() ;i++){
            for( int j = 1 ; j <= s.size() ; j++){
                if( s[j-1] == t[i-1] ){
                    dp[i][j] = dp[i][j-1] +dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[t.size()][s.size()];
    }

};
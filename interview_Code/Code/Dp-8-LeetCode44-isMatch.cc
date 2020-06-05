#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


/*
方法一：动态规划

四要素：
1） 状态：

    状态 dp[i][j] : 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配 (true 的话表示匹配)

2） 转移方程

    （1） 当 s[i] == p[j]，或者 p[j] == ? 那么 dp[i][j] = dp[i - 1][j - 1];
    （2） 当 p[j] == *，那么 dp[i][j] = dp[i][j - 1] || dp[i - 1][j]    其中
            dp[i][j - 1] 表示 * 代表的是空字符，例如 ab, ab*
            dp[i - 1][j] 表示 * 代表的是非空字符，例如 abcd, ab*
3） 初始化

    1. dp[0][0] 表示什么都没有，其值为 true
    2. 第一行 dp[0][j]，换句话说，s 为空，与 p 匹配，所以只要 p 开始为 * 才为 true
    3. 第一列 dp[i][0]，当然全部为 false

4） 结果


*/

bool isMatch(string s, string p) {
    int m = s.length() ;
    int n = p.length();

    vector<vector<bool>> dp( m+1,vector<bool>(n+1,false));

    //表示两个都为空，那么表示true;
    dp[0][0] = true;

    for( int i = 1 ; i<= n ;i++){
        if( dp[0][i-1] && p[i-1]=='*'){
            dp[0][i] = true;
        }
    }
    /*
    for(int i = 0 ;i <= m ;i++){
        dp[i][0] = false;
    }
*/
    for( int i= 1 ; i<= m ;i++){
        for( int j = 1 ;j <= n ;j++){
                //没有'*'的时候只要与先前匹配的状况一致即可
            if( s[i-1] == p[j-1]  || p[j-1] =='?'){

                dp[i][j] = dp[i-1][j-1];

            }else if( p[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
    }

    return dp[m][n];

}

//方法二：双指针贪心算法；
/*
本题难点在于处理星号的匹配，用iStar和jStar表示星号在s和p中匹配的位置，初始值为-1，i和j表示当前匹配的位置，匹配过程如下：

如果s和p中字符匹配，则分别自增i和j
否则如果p中当前字符为星号，则标记iStar和jStar，同时自增j
否则如果iStar >= 0，表示之前匹配过星号，因为星号可以匹配任意字符串，所以继续递增i，同时移动j为jStar下一个字符
否则返回false
当s中字符匹配完，p中字符不能有除星号以外字符

作者：guohaoding
链接：https://leetcode-cn.com/problems/wildcard-matching/solution/44-tong-pei-fu-pi-pei-shuang-zhi-zhen-by-guohaodin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

bool isMatch( string s ,string p ){

    int i =0 , j =0 ;
    int iStar = -1, jStar = -1 ;
    int m = s.size() ,n = p.size();

    while( i < m){
        if( j< n  && (s[i] == p[j] || p[j] == '?'){
            ++i;
            ++j;
        }else if ( j <n && p[j] == '*'){
            iStar = i ;
            jStar = j++;
        }else if( iStar >= 0 ){
            i = ++iStar ;
            j = jStar +1;
        }else{
            return false;
        }
    }

    while (  j < n && p[j] == '*')
    {
        ++j;
        /* code */
    }

    return j == n; 
    
}
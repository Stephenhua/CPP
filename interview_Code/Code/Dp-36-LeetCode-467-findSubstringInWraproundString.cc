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
467. 环绕字符串中唯一的子字符串
把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 

现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 

注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

 

示例 1:

输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。
 

示例 2:

输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
 

示例 3:

输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

*/
/*
动态规划：
1） 状态条件 dp[i]表示以每个字符结尾字串的最长长度；
2） 状态方程； dp[i] = max( dp[i] ,k);
3)  base case ;
3)  输出结果：

*/
class Solution {
public:
    bool isContinue( char prev ,char curr){
        if( prev == 'z'){
            return curr == 'a';
        }
        return prev+1 == curr;
    }
    int findSubstringInWraproundString(string p) {
        vector<int> dp( 26,0);
        int size = p.size();
        int k = 0 ;
        for( int i=0 ;i <size ;i++){

            if( i>0 && isContinue( p[i-1],p[i])){
                ++k;
            }else{
                k =1 ;
            }

            dp[p[i]-'a'] = max( dp[p[i]-'a']  , k);
        }
        return accumulate( dp.begin() ,dp.end() ,0);
    }
};

//方法二：
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if(n == 0)
            return 0;
        int cnt = 1;
        int len = 1;
        int flags[26] = {0};
        flags[p[0]-'a'] = 1;
        for(int i=1;i<n;++i)
        {
            int pi = p[i] - 'a';
            int pre = p[i-1] - 'a';
            //确定前一个值和当前值的数值；
            if(pi == (pre + 1) % 26)
                ++len;
            else
                len = 1;
            if(flags[pi] < len)
            {
                cnt += len - flags[pi];
                flags[pi] = len;
            }
        }
        return cnt;
    }
};
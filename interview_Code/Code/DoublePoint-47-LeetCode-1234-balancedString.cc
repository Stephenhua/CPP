#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
1234. 替换子串得到平衡字符串
有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。

假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。

 

给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。

你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。

请返回待替换子串的最小可能长度。

如果原字符串自身就是一个平衡字符串，则返回 0。

 

示例 1：

输入：s = "QWER"
输出：0
解释：s 已经是平衡的了。
示例 2：

输入：s = "QQWE"
输出：1
解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
示例 3：

输入：s = "QQQW"
输出：2
解释：我们可以把前面的 "QQ" 替换成 "ER"。 
示例 4：

输入：s = "QQQQ"
输出：3
解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 

提示：

1 <= s.length <= 10^5
s.length 是 4 的倍数
s 中只含有 'Q', 'W', 'E', 'R' 四种字符

*/

class Solution {
public:
    int balancedString(string s) {
        int size = s.length();

        unordered_map<char,int> dp;

        for( int i =0 ;i < size ;i++){
            if( s[i] == 'Q'){
                dp[s[i]]++;
            }else if( s[i] == 'W'){
                dp[s[i]]++;
            }else if( s[i] == 'E'){
                dp[s[i]]++;
            }else if(s[i] == 'R'){
                dp[s[i]]++;
            }
        }

        int avg = size/4;
        int res= size;
        if( check(size,dp)){
            return 0;
        }

        int j = 0 ;
        for(int i =0 ;i < size;i++){
            --dp[s[i]];
            while(check(size,dp)){
                res = min( res,i-j+1);
                ++dp[s[j]];
                ++j;
            }
        }

        return res;
    }
    bool check (int n,unordered_map<char,int> dp) {

        int limit = n / 4;
        for (char ch : "QWER") {
            if (dp[ch] > limit) return false;
        }
        return true;

    }

};


struct qwer {
    int q, w, e, r;
    qwer(): q(0), w(0), e(0), r(0) {}
};
class Solution {
public:
    int balancedString(string s) {
        int n = (s.size() >> 2), res(s.size() - 1), dict[26] {0}, cnt(0);
        for(int i = 0; i < s.size(); i++) {
            dict[s[i] - 'A']++;
        }
        dict['Q' - 'A'] = max(0, dict['Q' - 'A'] - n);
        dict['W' - 'A'] = max(0, dict['W' - 'A'] - n);
        dict['E' - 'A'] = max(0, dict['E' - 'A'] - n);
        dict['R' - 'A'] = max(0, dict['R' - 'A'] - n);
        cnt = (dict['Q' - 'A'] > 0) + (dict['W' - 'A'] > 0) + (dict['E' - 'A'] > 0) + (dict['R' - 'A'] > 0);
        if (cnt == 0)
            return 0;
        for(int r = 0, l(0); r < s.size(); ++r) {
            if(dict[s[r] - 'A']-- == 1)
                cnt--;
            while(!cnt) {
                res = min(res, r - l + 1);
                if(dict[s[l++] - 'A']++ == 0)
                    cnt++;
            }
        }
        return res;
    }
};
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
828. 统计子串中的唯一字符
我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。

例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。

本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。

由于答案可能非常大，请将结果 mod 10 ^ 9 + 7 后再返回。

 

示例 1：

输入: "ABC"
输出: 10
解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
     其中，每一个子串都由独特字符构成。
     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
示例 2：

输入: "ABA"
输出: 8
解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
示例 3：

输入：s = "LEETCODE"
输出：92
 

提示：

0 <= s.length <= 10^4
s 只包含大写英文字符

*/
/*
双指针法：前后扫描
方法：
1.对于每一个字符来说，在哪一段区间只出现了一次
2.在这一段区间内，这个字符可以为答案贡献多少（即在这段区间，这个字符可以存在于多少子串中）
1）如何通过一段区间来计算这个字符存在于多少子串中呢？
其实就是计算这个字符到最左端的距离再计算到最右端的距离，然后再乘起来。
2）为什么可以这样计算呢？
就是以这个字符左侧的任意字符开头，以这个字符右侧任意字符结束的子串数。


对于每一个字符，只需要记录区间左端点和右端点就可以找到这个区间了。
    用两个数组：left和right，分别记录左端点和右端点，都初始化为0
一共只有26个字符，我们用一个长度为26的数组记录每一种字符上一次出现的位置
    用数组prev，记录上一次出现的位置
https://leetcode-cn.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/c-you-li-zi-yi-dong-by-smilyt_/
*/
class Solution {
public:
    int uniqueLetterString(string s) {

        int len = s.length();

        vector<int> left( len,-1);
        vector<int> right( len ,-1);


        //求解左端点；

        vector<int> prev( 26,-1);
        for(int i = 0 ;i < len ;i++){
            left[i] = prev[s[i]-'A'];
            prev[s[i]-'A'] =  i;//记录当前存在的下标；
        }

        for( int i = 0 ;i < 26;i++){
            prev[i] = len;
        }

        for( int i = len -1 ;i >=0 ;i--){
            right[i] = prev[s[i]-'A'];
            prev[s[i]-'A'] = i;
        }

        long long int res = 0 ;

        for (int i = 0 ;i < len ;i++){
            res += (( i-left[i])*(right[i] -j))% 1000000007;
        }

        return res;

    }
};
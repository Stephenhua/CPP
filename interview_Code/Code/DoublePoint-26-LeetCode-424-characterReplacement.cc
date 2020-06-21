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
424. 替换后的最长重复字符
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意:
字符串长度 和 k 不会超过 104。

示例 1:

输入:
s = "ABAB", k = 2

输出:
4

解释:
用两个'A'替换为两个'B',反之亦然。
示例 2:

输入:
s = "AABABBA", k = 1

输出:
4

解释:
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

*/

/*
采用滑动窗口进行求解，如果连续的字符创越大，那么长重复字符也为最大；

*/
/*
方法一：滑动窗口进行求解；
1）建立一个26大写字母的映射，用于记录窗口中字符出现的次数，将A存到数组下标为0的位置；
2） 初始窗口指针为left，right，移动right增大窗口，在这个过程中检测最长重复字符的长度，知道窗口长度过长，即使替换k次以后，任然使窗口无法达到当前窗口的最大；
3）然后进行缩小窗口操作；
4）一直更新当前最长重复字符的长度，直到right指针遍历完整个字符串；

*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        if( s.empty()){
            return res;
        }
        int left = 0 ;
        int right = 0 ;
        int map[26] = {0};//表示当前窗口中存储的数值；

        int result= 0 ;

        while( right < s.size() ){

            int index = s[right] -'A';

            map[index]++;
    
            res = max( res, map[index]);

            if( right - left +1 > res+k) {

                map[s[left]-'A']--;//减小窗口左边的值；
                left++;//缩小窗口
            }

            result = max(result , right-left +1);
            right++;
        }

        return result;
    }
};
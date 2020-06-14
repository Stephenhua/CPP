#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>

using namespace std;

/*
76. 最小覆盖子串
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

*/

/*
主要思想：利用滑动窗口进行解决；


*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int > str ,windows;
        for( char c:t){
            str[c]++;
        }

        int left = 0 ;
        int right = 0;
        int vaild = 0 ;
        int start = 0;
        int len = INT_MAX;

        while( right < s.size()){
                //右移窗口；
                char c = s[right];
                right++;
                if( str.count(c)){
                    windows[c]++;
                    if( windows[c] == str[c]){
                        vaild++;
                    }
                }

                //判断左侧窗口是否需要进行收缩；
                while( vaild  == str.size()){

                    //更新最小的长度；
                    if( right - left < len){
                        start = left ;
                        len = right-left ;
                    }
                    //左边的缩小；
                    char le = s[left];
                    left++;
                    //判断左边的元素是否是str中，如果是，则需要进行下一步的判断；
                    if( str.count(le)){
                        //如果字符是相同的，那么直接将有效位减去，从而造成失效；
                        if( windows[le] == str[le]){
                            vaild--;
                        }
                        //窗口的大小减少；

                        windows[le]--;
                    }
                }

            }

        return len == INT_MAX ? "":s.substr(start,len);
    }
};

//方法二：
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (auto c : t) count[c] ++;
        int len = 0, n = s.size();
        int minlen = n;
        string ans = "";
        int l = 0, r = 0;
        //循环进行查找；
        for ( ; r < n; r ++) {
            //检查count中是否存在s[r];
            count[s[r]] --;

            //如果count[s[r]] >= 0 ，表明字符是s[r]中的；

            if (count[s[r]] >= 0) len ++;
            //当len == t.size（）,表明字符全部都覆盖；然后直接进行左指针的移动；

            while (len == t.size()) {
                //获取最小值；
                if (r - l + 1 <= minlen) {
                    minlen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
                //左指针所经过的元素的个数增加；
                count[s[l]] ++;
                //如果count[s[l]] >0 ,在t中，所以需要移除子串；
                if (count[s[l]] > 0) len --;
                //左指针进行向有移动；
                l ++;
            }
        }
        return ans;
    }
};
/*
作者：yizhe-shi
链接：https://leetcode-cn.com/problems/minimum-window-substring/solution/c-zuo-you-zhi-zhen-fa-xiang-jie-by-yizhe-shi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
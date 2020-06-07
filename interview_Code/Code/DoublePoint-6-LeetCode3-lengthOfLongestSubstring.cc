#include  <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/
//直接利用字符串的数字继续宁替换得到；

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res= 0 ;
        int length = 0; 
        int size = s.size();

        int m[256] = {0};
        int left = 0 ;
        int mlen = 0 ;

        for( int i = 0 ; i < size ;i++){
            if( m[s[i]] == 0 || m[s[i]] < left){
                res= max( res, i-left+1);
            }else{
                left = m[s[i]];
            }
            m[s[i]] = i+1;
        }
        return res;
    }
};
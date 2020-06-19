#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;

/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

*/


/*
双指针法：
1） 翻转序列进行求解，从后向前和从前向后；

*/
class Solution {
public:
    bool isPalindrome(string s) {

        string sback ;
        for( char c :s){
            if( isalnum(c)){
                sback  += tolower( c);
            }
        }

        int n = sback.size();

        int left = 0 ;
        int right = n -1 ;

        while( left < right){
            if( sback[left] != sback[right]){
                return false;
            }else{
                left ++;
                right--;
            }
        }
        return true;

    }
};
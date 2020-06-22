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
#include <queue>

using namespace std;

/*
345. 反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

*/

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        int left = 0 ;
        int right = len - 1;

        while( left < right){
            if( !check(s[left]) ){
                left++;
                continue;
            }
            if( !check(s[right])){
                right--;
                continue;
            }


                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                right--;
                left++;
        }
        return s;
    }
    bool check( char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        else return false;
    }
};
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
567. 字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False

*/

/*
双指针法：
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char ,int> str,window;
        for( char c: s1){
            str[c]++;
        }

        int left =0 ,right = 0 ;
        int vaild = 0 ;

       while( right < s2.size()){
            //右指针的字符；
            char c1 = s2[right];
            right++;

            if( str.count(c1) ){
                window[c1]++;
                if(window[c1] == str[c1] ){
                    vaild++;
                }
            }
            //判断左指针是否需要收缩；根据长度进行判断；

            while( right -left >= s1.size()){

                if( vaild == str.size()){
                    return true;
                }

                char le = s2[left];
                left++;
                //检查左指针指向的元素在str中是否存在；
                if( str.count(le)){
                    if( str[le]== window[le]){
                        vaild--;
                    }

                    window[le]--;
                }
            }

        }
        return false;
    }
};

//方法二：通过将字符进行添加，从而可以减少运行时间；


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto s1Len = s1.length();
        auto s2Len = s2.length();
        if( s2Len < s1Len){
            return false;
        }

        int s1Map[26]{};

        int windowMap[26]{};

        int vaild = 0 ;
        int left = 0 ;
        int right = 0 ;
        int s1MapSize = 0 ;
        
        for( char c: s1){
            if( s1Map[c-'a'] == 0){
                s1MapSize ++;//计算字符串中有多少个相同的值；
            }

            s1Map[c-'a']++;
        }

        while( right < s2Len){
            //左边指针的为位置；
            char rc = s2[right];
            right++;
            //将被匹配的字符实现map化；
            if( s1Map[rc-'a'] != 0 ){
                windowMap[rc -'a'] ++;
                if( windowMap[rc - 'a'] ==s1Map[rc-'a'] ){
                    vaild++;//已经匹配的元素个数；
                }
            }

            while( right - left >= s1Len){

                if( vaild == s1MapSize){//如果当前元素的个数与s1中个数相同，则表明找找到了
                    return true;
                }
                //窗口的左边元素进行收缩；

                char lc = s2[left];
                left++;
                //表明元素在s1中找到；
                if( s1Map[lc - 'a'] != 0){
                    if( windowMap[lc - 'a'] == s1Map[lc-'a']){
                        vaild--;
                    }
                    windowMap[lc-'a']--;
                }


            }
            return false;
        }
    }

};
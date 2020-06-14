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
438. 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char ,int> need ,window;
        for( char c : p){
            need[c]++;
        }

        int left =0 ,right = 0 ;
        int vaild = 0 ;
        vector<int> res;
        while( right < s.size()){

            char str = s[right];
            right++;

            if( need.count(str)){
                //单个元素的个数符合要求，也更新Vaild，vaild表示的是已经有几个元素已经相同了，
                if( need[str] == window[str]){
                    vaild++;
                }
                window[str];
            }
            //缩小窗口的大小；
            while( right-left >= p.size()){
                //表明集齐了元素；
                if(vaild == need.size()){
                    res.push_back(left);
                }

                char ls = s[left];
                left++;

                if( need.count(ls)){
                    if( window[ls] == need[ls]){
                        vaild--;
                    }
                    window[ls]--;
                }
            }
        }

        return res;
    }
};

//方法二：s中找P;

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        auto s1Len = s.length();
        auto s2Len = p.length();
        if( s1Len < s2Len){
            return res;
        }

        int pMap[26]{};

        int windowMap[26]{};

        int vaild = 0 ;
        int left = 0 ;
        int right = 0 ;
        int pSize = 0 ;
        
        for( char c: p){
            if( pMap[c-'a'] == 0){
                pSize++;//计算字符串中有多少个不相同元素的个数；
            }

            pMap[c-'a']++;
        }

        while( right < s1Len ){
            //左边指针的为位置；
            char rc = s[right];
            right++;
            //将被匹配的字符实现map化,在pMap中找到字符；
            if( pMap[rc-'a'] != 0 ){

                windowMap[rc -'a'] ++;

                if( windowMap[rc - 'a'] ==pMap[rc-'a'] ){
                    vaild++;//已经匹配的元素个数；
                }
            }

            while( right - left >= p.size()){

                if( vaild == pSize){//如果当前元素的个数与s1中个数相同，则表明找找到了
                    res.push_back(left);
                }
                //窗口的左边元素进行收缩；

                char lc = s[left];
                left++;
                //表明元素在s1中找到；
                if( pMap[lc - 'a'] != 0){
                    if( windowMap[lc - 'a'] == pMap[lc-'a']){
                        vaild--;
                    }
                    windowMap[lc-'a']--;
                }


            }

        }
        return res;
    }

};

//方法三：只用了一维数组就解决；

class Solution3 {
public:
    vector<int> findAnagrams(string s, string p) {
        //表示输出结果
        vector<int> res;
        //用于存储字符串；
        vector<int> vec(128, 0);
        //将p中的元素进行存储起来；
        for (auto c : p) ++vec[c];
        //左边
        int left = 0, cnt = p.size();

        for (int right = 0; right < s.size(); ++right) {
            //如果右边元素存在，那么一定>=0,所以
            if (--vec[s[right]] >= 0) --cnt;
            //cnt表示与p中相同元素的剩余值；
            while (!cnt) {
                //如果元素的个数相同，那么直接压入到res中；

                if (right - left + 1 == p.size()) res.push_back(left);
                //进行相加；
                if (++vec[s[left++]] > 0) ++cnt;
            }
        }
        return res;
    }
};

int main( int argc, char* argv[]){
    Solution3 s;
    string s1 = "cbaebabacd";
    string p1 = "abc";

    vector<int> res=s.findAnagrams(s1,p1);
    for(int i= 0 ;i < res.size() ;i++){
        cout << res[i] <<endl;
    }

    system("pause");
    return 0;

}
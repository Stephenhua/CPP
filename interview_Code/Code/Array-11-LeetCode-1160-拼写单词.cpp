#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1160. 拼写单词
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

*/


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0 ;

        //统计单词出现的个数；
        unordered_map<char,int> str;
        for(int i = 0 ; i<chars.length() ; i++){
            str[chars[i]]++;
        }

        int size = words.size();

        for( int i = 0 ; i < size ; i++ ){

            unordered_map<char, int > temp ;

            string s = words[i];

            for(auto& s1 :s ){

                temp[s1]++;

            }

            bool match = true;

            for( auto & s1 : s){

                if( temp[s1]  > str[s1] ){
                    match = false;
                    break;
                }

            }

            if( match ){
                
                res += s.length();

            }

        }

        return res;



    }
};


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int  cnt[26] = {0}, i, j, k, n = words.size(), m, ret = 0;
        
        for (i = 0; i < chars.size(); i++) cnt[chars[i] - 'a']++;

        for (i = 0; i < n; i++) {
            int  cnt2[26] = {0};
            for (j = 0; j < 26; j++) cnt2[j] = 0;
            m = words[i].length();
            for (j = 0; j < m; j++) {
                k = words[i][j] - 'a';
                if (!cnt[k] || (cnt2[k] == cnt[k])) break;
                cnt2[k]++;
            }
            if (j >= m) ret += m;
        }
        return ret;
    }
};
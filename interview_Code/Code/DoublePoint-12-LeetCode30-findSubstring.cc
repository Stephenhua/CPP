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
30. 串联所有单词的子串
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]

*/

//方法一：通过构建hashMap进行比较，每次比较的数是words[0].size()；
/*
1)将words中的单词进行存储，key存储单词、value存储单词的个数；
2）在进行判断的时候需要考虑该单词的value是否大于 words中的，
3）如果个数大了，说明不是我们所找的；

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;

        if( words.size() == 0){
            return res;
        }

        int word_size = words[0].size();
        int word_num = words.size();
        //用于存储words中的单词频率；
        unordered_map<string, int> word_map;

        for( int i = 0 ;i < word_num ;i++){

            word_map[words[i]]++;

        }

        //统计s中的单词频率；
        unordered_map<string, int> s_map;

        //遍历整个s;
        for( int i = 0 ;(i + word_size*word_num)<= s.size() ;i++){

            int j = 0 ;
            //限定范围，最大为word_size*word_num；
            for( j = i ; j < (i+ word_size*word_num);j=j+word_size){

                string temp_str = s.substr( j,word_size);

                if( word_map[temp_str] == 0){
                    break;
                }else{
                    s_map[temp_str]++;
                    if( word_map[temp_str] < s_map[temp_str]){
                        break;
                    }
                }
            }

            if( j == (i+word_size*word_num)){
                res.push_back( i);//将起始位置压入到里面；
            }

            s_map.clear();
        }
        return res;

    }
};


//方法二：
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;

        if( words.size() == 0){
            return res;
        }

        int word_size = words[0].size();
        int word_num = words.size();
        //用于存储words中的单词频率；
        unordered_map<string, int> word_map;

        for( int i = 0 ;i < word_num ;i++){

            word_map[words[i]]++;

        }

        for( int i = 0 ;i <word_size ;i++){
            int left = i;
            int right = i ;
            int count = 0;

            unordered_map<string,int> temp;
            //开始滑动窗口；
            while( right+word_size <= s.size()){

                //从s中提取一个单词拷贝到w；
                string w = s.substr(right,word_size);

                right += word_size;
                //如果在word_map中没有找到 ，则表明匹配不成功；
                if( word_map[w] == 0){
                    count = 0 ;//word中的size ，用于判断是否相等；
                    left = right;//直接向前移动；
                    temp.clear();
                }else{//该单词匹配成功，添加到m2中
                    temp[w]++;
                    count++;
                    ////为了防止一个单词匹配多次，需要缩小窗口，也就是left右移
                    while( word_map.at(w) < temp.at(w)){
                        string w_t = s.substr( left ,word_size);
                        count--;
                        temp[w_t]--;
                        left += word_size;
                    }

                    if( count == word_num){
                        res.push_back( left);
                    }
                }
            }

        }
        return res;
    }

};


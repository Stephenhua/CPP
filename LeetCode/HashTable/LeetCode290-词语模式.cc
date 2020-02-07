#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//解法一：
/*
我们一个模式字符串，又给我们一个单词字符串，让我们求单词字符串中单词出现的规律是否符合模式字符串中的规律。
那么首先想到就是用 HashMap 来做，建立模式字符串中每个字符和单词字符串每个单词之间的映射，
而且这种映射必须是一对一关系的，不能 'a' 和 'b' 同时对应 'dog'，也不能 'a' 同时对应到 'dog' 和 'cat'，
所以我们在碰到一个新字符时，首先检查其是否在 HashMap 中出现，若出现，其映射的单词若不是此时对应的单词，则返回 false。
如果没有在 HashMap 中出现，我们还要遍历一遍 HashMap，看新遇到的单词是否已经是其中的映射，
若已经有其他映射，直接返回 false，如果没有，再跟新遇到的字符建立映射。
最后循环退出后，要检查此时的 i 是否和 n 相同，这是检查一对一映射的最后一步，
因为当 str 中的单词处理完了之后，pattern 中就不能有多余的字符。

键值和后面的映射关系；
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char ,string > m;
        istringstream in(str);
        int i=0,n=pattern.size();
        for(string word;in>>word;++i){
            if(i>=n){
                return false;
            }

            if(m.count(pattern[i])){
                if(m[pattern[i]]!=word){
                    return false;
                }
            }else{
                for(auto a:m){
                    if(a.second==word){
                        return false;
                    }
                }
                m[pattern[i]]=word;//建立联系
            }
        }
        return i ==n;

    }
};
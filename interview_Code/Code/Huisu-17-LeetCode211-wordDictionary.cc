#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
211. 添加与搜索单词 - 数据结构设计
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {

        WordDictionary* root = this;

        for( const auto &w : word){
            if( root->next[w-'a'] == nullptr){
                root->next[w-'a'] = new WordDictionary();
            }

            root = root->next[w-'a'];
        }

        root->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

        if( word.length() == 0 ){
            return this->is_end;
        }

        WordDictionary* root = this;

        for( int i =0 ; i< word.length() ;++i){

            char w = word[i];

            if( w == '.'){
                for(WordDictionary* node: root->next){
                    if( node != nullptr && node->search( word.substr( i+1))){
                        return true;
                    }
                }
                return false;
            }
            if( root->next[w-'a'] == nullptr){
                return false;
            }

            root = root->next[w-'a'];
        }
        return root->is_end;

    }


private:
    bool is_end = false;
    WordDictionary *next[26] = {nullptr};
};

#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//方法一：采用这种方法进行求解，可以有效地到
//字母异位词是指由相同的字母按照不同的顺序组成的单词，根据此含义，那么这两个单词的长度也一定相等
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int temp_num[26]={0};
        for(int i=0;i<s.size();i++){
            temp_num[s[i]-'a']++;
            temp_num[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(temp_num[i]!=0){
                return false;
            }
        }
        return true;


    }
};


//方法二：一次遍历的形式
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        vector<int> countMap(26,0);
        for(auto a:s){
            countMap[a-'a']+=1;
        }
        for(auto b:t){
            if(countMap[b-'a']==0){
                return false;
            }
            countMap[b-'a']-=1;
        }

        return true;

    }
};
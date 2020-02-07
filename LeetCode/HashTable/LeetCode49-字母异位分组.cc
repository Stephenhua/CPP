#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

//采用map<string , vectot<string>> 的形式进行遍历；

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ma;
        vector<vector<string>> result;

        for(auto str:strs){
            string temp_str= str;
            sort(temp_str.begin(),temp_str.end());
            ma[temp_str].push_back(str);
        }

        for(const auto& ms:ma){
            result.push_back(ms.second;
        }
        return result;
        
    }
};


//方法二:采用unorded_map进行遍历

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        string word;
        for(size_t i=0; i<strs.size(); i++){
            word = strs[i];
            sort(word.begin(), word.end());
            groups[word].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for(pair<const string, vector<string>>& temp : groups){
            res.emplace_back(temp.second);
        }
        return res;
    }
};


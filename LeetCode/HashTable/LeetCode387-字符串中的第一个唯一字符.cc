#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
       //方法一：采用一次循环的形式进行；
    int firstUniqChar(string s) {
        map<int,int> tempmap;
        for(auto c:s){
            tempmap[c]+=1;
        }
        
        for(int i=0;i<s.size();++i){
            if(tempmap[s[i]]==1){
                return i;
            }
        }
        
        return -1;
    }
};


    //采用字母的形式进行计算
int firstUniqChar(string s) {
        array<int,26> check{0};
        for(auto i=0;i<s.size();++i){
            check[s[i]-'a']++;
        }
        for(auto i=0;i<s.size();++i){
            if(check[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
}

class Solution {
public:
    int firstUniqChar(string s) {
       vector <int> dic (26,0);   //char用-'a'转换为int, map换为vector
        for(int i=0; i<s.size(); i++)
            dic[s[i]-'a']+=1; 

        for(int i=0; i<s.size(); i++)
            if(dic[s[i]-'a']==1) 
                    return i;
    
        return -1;
    }
};
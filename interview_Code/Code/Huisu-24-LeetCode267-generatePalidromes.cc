#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
267. 回文排列 II
给定一个字符串 s ，返回其通过重新排列组合后所有可能的回文字符串，并去除重复的组合。

如不能形成任何回文排列时，则返回一个空列表。

示例 1：

输入: "aabb"
输出: ["abba", "baab"]
示例 2：

输入: "abc"
输出: []


*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if( s.size() < 2){
            return {s};
        }

        int N = s.size();
        //将字符串中的数字进行统计；
        map<char , int> counts;
        for( auto c:s){
            ++counts[c];
        }
        //求得奇数的字符串；
        string odds;
        for( auto & p :counts){
            if( p.second &1){
                odds += p.first;
            }
        }
        //取出特殊的部分；
        if( (odds.size() > 1&& N & 1 ) ||( odds.size() >0 && !(N &1))){
            return {};
        }

        //
        int K = 0;
        for( auto &p : counts){
            p.second >>=1 ;
            K +=p.second;
        }

        string t;
        vector<string> res;
        Core( counts, 0,K, odds, t, res);
        return res;


    }

    void Core( map<char,int>& counts, int i , int K ,string odds, string&s, vector<string>& res){
        //取中间的一半；
        if( i == K){
            string t =s;
            reverse( t.begin() ,t.end());
            t += odds+ s;
            res.push_back(t);
            return;
        }

        for( auto& p :counts){
            
            if( p.second == 0){
                continue;
            }

            --p.second;
            s += p.first;

            Core( counts , i+1,K ,odds, s,res);

            s.pop_back();
            ++p.second;
        }
    }
};
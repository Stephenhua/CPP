#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
131. 分割回文串
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

//回溯算法；

bool isVaild(string& s ,int start ,int end){

    while( start < end){

        if( s[start] != s[end] ){

            return false;

        }
        start++;
        end--;
    }

    return true;

}
void Core( string &s , vector<vector<string>>& res , vector<string>& str , int start ,int len){

    if( start == len){
        res.push_back( str);
        return;
    }

    for( int i =start ;i<len ;i++){

        if( !isVaild(s,start,i)){
            continue;
        }

        str.push_back( s.substr(start ,i-start+1));
        Core( s, res, str ,i+1, len);
        str.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    int n = s.size();

    vector<vector<string>> res;

    if( n == 0 ){
        return res;
    }

    vector<string> str;

    Core( s, res, str, 0,n);

    return res;
 }
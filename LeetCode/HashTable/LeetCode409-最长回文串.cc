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
    int longestPalindrome(string s) {
        unordered_map<char ,int > temp_value ;
        for(int i=0;i<s.size();i++){
            temp_value[s[i]]++;
        }
        int counter=0;
        for(auto c:s){
            counter+=(temp_value[c]%2==0)?temp_value[c]%2:temp_value[c]-1;
        }
        if(counter<s.size()){
            counter+=1;
        }
        return counter;        
    }
};


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char ,int > temp_value ;
        int ans=0;
        for(int i=0;i<s.size();i++){
            ++temp_value[s[i]];
        }
        int counter=0;
        for(auto c:s){
            if(c&1){
                counter++;
            }
        }

        return s.size()-counter+(counter>0);
     
    }
};


//方法三：采用字母表的形式进行求解
class Solution {
public:
    int longestPalindrome(string s) {

        int a[26]={0};
        int A[26]={0};

        for(char c:s){
            int &x= c>'Z'?a[c-'a']:A[c-'A'];
            ++x;
        }

        int signals=0;
        int pairs=0;
        for(int i=0;i<26;++i){
            pairs+=a[i]/2+A[i]/2;
            signals+=a[i]%2+A[i]%2;
        }
        
        return pairs*2+(signals>0?1:0);
    }
};
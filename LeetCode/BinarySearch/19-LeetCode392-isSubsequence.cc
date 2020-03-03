/*
题目：子序列；
*/
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <algorithm>
using namespace std;

//采用比较的方法，时间复杂度为O(n)；通过移动内存大的数组，来进行比较判断；
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0;
        for(int ti=0;ti<t.size()&&si<s.size();ti++){
            if(t[ti]==s[si]){
                si++;
            }
        }
        return si==s.size();

    }
};

//同样采取比较的方法进行，但是这次是将数字小的放倒最外侧，而大的放到最里面，从而进行比较判断；

class Solutions{
    public:
    bool isSubsequence(string s, string t) {
        long pos=0;
        for(char c:s){
            while(pos<t.size()&&c!=t[pos]){
                pos++;
            }
            if(pos>t.size()){
                return false;
            }
            pos++;
        }
        return true;
    }
};

//采用双指针法进行比较，这样减少额时间复杂度，而花费了较大的空间复杂度；该方法要快一些；

class Solut{
    public:
    bool isSubsequence(string s, string t) {
     if(s.empty())
     {
         return true;
     }

     for(auto itt=t.begin(),its=s.begin();itt!=t.end();itt++){
         if(*its==*itt){
             ++its;
         }
         if(its==s.end()){
             return true;//如果找到最后一个，则表明前面的都存在；
         }
     }

     return false;
    }

};


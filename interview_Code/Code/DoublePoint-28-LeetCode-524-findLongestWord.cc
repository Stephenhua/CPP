#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
524. 通过删除字母匹配到字典里最长单词
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出: 
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

*/

/*
双指针法：如果删除s中的部分元素，那么可以直接与d进行匹配，匹配符合就得到最大值；
int max;

if( curLeng > max){
    res = d[k];
    max = d[k].size();
}else if( curLength==max && d[k] < res){//得到最大值；
    res= d[k];
}

int caculateLength( string &s ,string &str){
    int i = 0, j= 0 ;
    for( ;i < s.size() && j< str.size(); i++){
        if( s[i] == str[j]){
            j++;
        }
    }

    return j == str.size()? str.size():0;
}
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {

        string res;

        for( int k=0 ,mmax = 0 ; k < d.size() ;k++){
            int tempValue = Caculate( s,d[k]);
            if( tempValue> mmax){
                res = d[k];
                mmax = d[k].size();
            }else if( tempValue == mmax &&  d[k] < res){
                res = d[k];
            }
        }
        return res;
    }

    int Caculate( string & s, string& str){

        int i =0 ,j = 0 ;

        for(; i <s.size() && j <str.size() ;i++){
            if( s[i] == str[j]){
                j++;
            }
        }

        return  j== str.size() ? str.size(): 0;
    }
};


//方法二：

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int size=d.size();
        int result=-1, len=0;
        for(int i=0; i<size; i++){
            int j=0, k=0, dSize=d[i].size();
            while(j<dSize&&k<s.size()){
                if(d[i][j]==s[k]){
                    j++;
                }
                k++;
            }

            //当规模相同的时候，然后继续进行判断dsize 和len的长度；

            if(j==dSize){
                if(dSize>len){
                    len=dSize;
                    result=i;
                }
                if(dSize==len){
                    result=compareDic(d[result], d[i])?result:i;
                }
            }
        }
        if(result==-1)
            return {};
        return d[result];
    }

    bool compareDic(string &s1, string &s2){//假设s1,s2的size相同
        int i=0;
        while(i<s1.size()&&s1[i]==s2[i]){
            i++;
        }
        if(i==s1.size())
            return true;
        return s1[i]>s2[i]?false:true;
    }
    
};
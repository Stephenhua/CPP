#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <stack>

using namespace std;

/*
151. 翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

*/

/*
思路一：先翻转真个字符串，然后对每个字符进行反转；
由于里面存在多个空格，所以每次更新，下标都将会更新；

*/
class Solution {
public:
    string reverseWords(string s) {

        reverse( s.begin() ,s.end());
        int size = s.size();

        int start = 0 ;//单词开始；
        int end = 0 ;//单词结束；
        int index= 0 ; //末尾；

        for( ; start <size ; start++){

            if( s[start] == ' '){
                continue;
            }

            if( index != 0){
                //第二个单词开始，开头需要空格；
                s[index++] = ' ';
            }

            end = start;
            //替换原来的字符，主要目的是用于去掉空格；
            while( end < size && s[end] != ' '){
                s[index++] = s[end++];
            }

            int len = end - start;
            //index-len就是单词开始的地方，局部进行翻转；
            reverse( s.begin() + index -len,s.begin()+ index);
            //更新下一个单词开始的位置；下一轮的start开始位置，有可能是空格，有可能是字符，所以在程序开始的地方进行了一个确认；
            start = end;
        }

        s.erase( s.begin()+index, s.end());
        return s ;
    }
};

//利用栈进行实现

class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> stk;
        string res,str;

        istringstream ss(s);

        while (ss >> str )
        {
            stk.push(str);
            stk.push(" ");
        }

        if( !stk.empty()){
            stk.pop();
        }
        while( !stk.empty()){
            res += stk.top();
            stk.pop();
        }

        return res;        
    }
};

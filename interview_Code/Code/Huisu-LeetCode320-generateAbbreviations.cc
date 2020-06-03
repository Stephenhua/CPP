#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
请你写出一个能够举单词全部缩写的函数。

注意：输出的顺序并不重要。

示例：

输入: "word"
输出:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generalized-abbreviation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

vector<string> res;
void Core( string& cur , string& word , int i ,int k ,int n){

    int len = cur.size();
    if( i == n){
        //k表示当前缩写的字母个数；
        if( k>0){
            cur.append(to_string(k));
        }
        res.push_back(cur);
        cur.resize(len);
        return;
    }

    //1、缩写
    Core( cur,word , i+1, k+1 , n);

    //2、不缩写；只是对字符进行替换；

    if( k>0){
        cur.append(to_string(k));
    }

    cur.push_back(word[i]);
    Core(cur,word,i+1,0,n);
    cur.resize(len);
}
vector<string> generateAbbreviations(string word) {

    int n = word.size();

    string str;

    Core( str, word, 0,0,n);
    return res;
}
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
763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

*/

/*
双指针法：
1） 确定每个字母的最后出现的位置；
2） 每次遍历找到最后的位置；
3）在这个区间内，确定其他元素的最后出现的位置，如果小于的话，那直接可以使用；
4）如果大雨的话，更新最后字母出现的位置；


*/
class Solution {
public:
    vector<int> partitionLabels(string S) {

        int n = S.size();
        vector<int> ends( 26,-1);//用于存储字母最后出现的序号；

        for(int i =0; i < n ;i++){
            ends[S[i]-'a'] = i;
        }

        vector<int> res;

        int i = 0 ;

        while( i < n ){//从左边开始；

            int r = ends[S[i]-'a'];//得到该字母的最后下标位置；

            for( int j = i+1 ; j<=r ; j++ ){//
                r = max( r, ends[S[j]-'a']);//在一个区间内，找其他字母的最后的下面，；如果找打的话；
            }

            res.push_back( r-i+1);
            i = r+1;
        }
        return res;

    }
};
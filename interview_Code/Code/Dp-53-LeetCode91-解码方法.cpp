#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>

#include <numeric>

using namespace std;


/*



*/


/*
思路：动态规划

首先要根据当前的字符是否为 0 进行判断
s 为字符串 s， f(i) 代表 到 s[i] 一共有多少种解码方式

if s[i] == '0'
if s[i-1] == '1' || s[i-1] =='2' --> f(i) == f(i-2)
也就是说最后两位只能合并解码为 10 或者 20， 例如 1212120 那么此时解的数量与 12121 相同（只是解中增加了一个 20 的对应字母， 解总数量未增加）
else --> return 0
字符串非法， 也就是 0 只能出现在 1 或者 2 的后面， 其它情况都是无解的如： 1212130， 30 无法对应任何字符， 直接 return 0
if s[i] != '0'
if s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6') --> f(i) == f(i - 1) + f(i - 2)
也就是最后两位在 10~26 之间如 1212121， 可以翻译成 12121 + 21， 或者 121212 + 1
else --> f(i) == f(i - 1)
也就是最后两位不在 10~26 之间如 1212132 那只能翻译成 121213 + 2

作者：mrsate
链接：https://leetcode-cn.com/problems/decode-ways/solution/dong-tai-gui-hua-by-mrsate/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/

class Solution {
public:

    int numDecodings(string s) {
         
         if( s[0] == '0'){

             return 0 ;

         }

         vector<int> dp(s.size()+1,1);

         for(int i= 1 ; i < s.size() ; i++){

             if( s[i]=='0'){

                 if( s[i-1]=='1' || s[i-1] == '2'){
                     dp[i+1] = dp[i-1];
                 }else {
                     return 0 ;
                 }
             }else{
                 if(s[i-1]== '1' || ( s[i-1] == '2')&&(s[i] >='1' && s[i]<='6')){
                     dp[i+1] =dp[i-1]+dp[i];
                 }else{
                     dp[i+1] =dp[i];
                 }
             }
         }

         return dp[s.size()];       

    }
};
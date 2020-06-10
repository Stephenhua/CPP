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
474. 一和零
在计算机界中，我们总是追求用有限的资源获取最大的收益。

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:

给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。
示例 1:

输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
输出: 4

解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
示例 2:

输入: Array = {"10", "0", "1"}, m = 1, n = 1
输出: 2

解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
*/
/*
动态规划
1） 状态分析： dp[k][i][j]表示长度为k时，最多需要i个0 和j个1 ；
2） 状态方程转移：
    dp[k][i][j] = dp[k-1][i][j]， 表示不考虑当前字符；
    dp[k][i][j] = dp[k][i-当前字符0的个数][j-当前字符1的个数]；
3） 初始条件：多设置一行，为0 ；
4） 输出结果 dp[len][m][n];


*/
class Solution {
public:
    vector<int> count1( string s){
         int dp[2];
         vector<int> res;
        for( int i = 0 ;i < s.size();i++){
            dp[s[i]-'0'] ++;
        }
         res.push_back( dp[0]);
         res.push_back( dp[1]);
        return res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp( size,vector<vector<int>>( m,vector<int>( n, 0)));


        for( int k =1 ;k <= size ;k++){
            
            vector<int> str = count1(strs[k-1]); 

            for( int i = 0;i  <= m;i++){
                for( int j= 0 ;j <= n  ;j++){
                    dp[k][i][j] = dp[k-1][i][j];


                    int zero = str[0];
                    int one = str[1];

                    if( i >= zero && j >= one){
                        dp[k][i][j] = max( dp[k-1][i][j] ,dp[k-1][i-zero][j-one]+1 );
                    }
                }
            }
        }
        return dp[size][m][n];
    }
};

//进行考虑压缩空间；dp[i][j]表示i个0 和j个1 ，最多有多少个字符串；

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>( n+ 1, 0));

        dp[0][0] = 0 ;

        for( auto str:strs){

            int zeros = 0 ;
            int ones = 0 ;
            for( const auto s:str){
                if( s=='1'){
                    ones++;
                }else{
                    zeros++;
                }
            }

            for( int i = m ; i >=zeros ;i--){

                for( int j = n ;j >= ones; j--){

                    dp[i][j] = max( dp[i][j] , dp[i-zeros][j-ones]+1);

                }
            }
        }

        return dp[m][n];
    }
};

//方法三：用时比较短

class Solution {
public:

    std::tuple<int, int> getNumber(const string& str) {
        int ones = 0;

        for (const auto& c : str) {

            if (c == '1') ++ones;
            
        }

        return make_tuple(ones, str.length() - ones);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        if(strs.size() == 0 || (m==0 && n==0)){
            return 0;
        }

        int dp[101][101] = { 0 };

        int ones, zeros;

        for (const auto& s : strs) {

            tie(ones, zeros) = getNumber(s);

            for (int i = m; i >= zeros; --i) {

				for (int j = n; j >= ones; --j) {

                    if ((1 + dp[i - zeros][j - ones]) > dp[i][j])

					    dp[i][j] = 1 + dp[i - zeros][j - ones];

				}
			}
        }
        return dp[m][n];
    }
};
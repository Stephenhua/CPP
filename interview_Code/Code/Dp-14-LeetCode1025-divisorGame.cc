#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
1025. 除数博弈
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

 

示例 1：

输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示例 2：

输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。

*/

/*
dp[]代表一个长度为n+1的数组，如果 dp[n-x]为false,则Alice会减去x,即 Bob==dp[n-x]==false, Alice胜。否则Alice输，因为不管x是多少，dp[n-x]为true, 则dp[n]==Alice==false.

作者：charles-gao
链接：https://leetcode-cn.com/problems/divisor-game/solution/dong-tai-gui-hua-he-shu-xue-si-wei-by-charles-gao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool divisorGame(int N) {
        if( N == 1){
            return false;
        }

        if( N == 2){
            return true;
        }

        bool dp[N+1];
        dp[1] = false;
        dp[2] = true;

        for( int i = 3 ;i <=N ;i++){

            dp[i] = false;

            for( int j =1 ; j<i ;j++){
                if( i%j == 0 && !dp[i-j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

//方法二：直接用数学进行判断奇偶性；
class Solution {
public:
    bool divisorGame(int N) {
        return !(N % 2) ;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
464. 我能赢吗 --博弈论的问题，比较困难；

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

示例：

输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
*/
/*
极小化+极大化的 、博弈论、位运算实现；
主要体现在游戏当中

*/
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if( maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal ){
            return false;
        }

        vector<int> vis( (1<<maxChoosableInteger)-1,-1);
        int num = 0 ;
        return Core( vis ,maxChoosableInteger,desiredTotal,num);
    }
    bool  Core( vector<int>& vis ,int maxChoosableInteger ,int desiredTotal,int num){
        if( ~vis[num] ){
            return vis[num];
        }

        vis[num] = 0 ;

        for( int i = 1 ;i <=maxChoosableInteger; ++i){
            //如果这部分访问过，则直接跳出去；
            if( num & (1 << (i-1))){
                continue;
            }
            if( i >= desiredTotal){
                vis[num] = 1 ;
                break;
            }

            bool next = Core( vis ,maxChoosableInteger,desiredTotal-i ,num |(1 <<(i-1)));
            if( next == false){
                vis[num] =1 ;
                break;
            }
        }

        return vis[num];

    }
};

//

class Solution {
public:
    bool canIWin(int nums, int sum) 
     {
        if(sum==0) return true;
        if((1+nums)*nums/2<sum) return false;
        return dfs(nums,sum,0,new int[1<<20],true);
    }
    bool dfs(int nums,int sum,int visited,int memo[],bool turn)
    {
        if(memo[visited]==1) return true;
        if(memo[visited]==2) return false;
        if(sum<=0){
            if(turn){
                memo[visited]=2;
                return false;
            }
            memo[visited]=1;
            return true;
        }
        for(int i=nums;i>0;i--){
            if(((visited>>(i-1))&1)==1) continue;
            if(turn&&dfs(nums,sum-i,visited|(1<<(i-1)),memo,turn==true?false:true)){//A 一种情况就够了
                memo[visited]=1;
                return true;
            }
            else if(!turn&&!dfs(nums,sum-i,visited|(1<<(i-1)),memo,turn==true?false:true)){ //B 的每种情况都需要要A赢
                memo[visited]=2;  
                return false;
            }
        }
        if(turn){//A true ,B false
            memo[visited]=2;
        }else{
            memo[visited]=1;
        }
        return !turn;
    }
};
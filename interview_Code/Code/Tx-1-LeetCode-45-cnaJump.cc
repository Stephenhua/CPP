#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>

using namespace std;

/*
55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

*/

/*
思路一：
1）如果将某一个点作为起点，那么nums[i]的值表示其可以跳跃的距离；
2）对每一个能跳的位置进行尝试，将最远的距离即表示索引值，不断的更新，
3）如果可以一直跳到最后就可以成功；


*/
class Solution {
public:
    bool canJump(vector<int>& nums) {

        //表示最大范围的索引；
        int  k = 0 ;
        
        for( int i = 0 ;i <nums.size() ;i++){
            if( i > k ){
                return false;
            }

            k = max( k , i+nums[i]);
        }
        return true;
    }
};

//方法二：
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

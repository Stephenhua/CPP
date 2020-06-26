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
思路一：尽可能到达最远位置；
如果能到达某个位置，那么一定可以到达其他位置；
方法： 初始化最原位置为0 ， 然后遍历数组，如果当前位置能到达，并且当前位置+条数 》 最远位置，就更新最远位置。
最后比较最远位置和数组长度；
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int k = 0 ;
        for( int i = 0 ; i < nums.size() ;i++){
            if( i > k ){
                return false;
            }

            k = max( k , i+nums[i]);
        }
        return true;
    }

};
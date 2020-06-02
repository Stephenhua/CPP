#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
题目：90. 子集 II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
方法一：在进行排序之后，会出现重复数字，主要问题是如何将重复的数组只保留一个既可以，多余的并不需要；
出现重复解的为 [2] [2'] 和 [1, 2] [1, 2']

主要为了实现剪纸运算；

观察选取到重复的解的特点， 重复的解是因为有 2 个或以上个相同的元素（如 2， 2'）在同一层回溯过程中被分别选择， 作为最终解的一部分了.
所以处理这种问题， 就是要在回溯过程中区分出来这种数值相同的情况（就是要区分出来 2 == 2'）
因为输入数据已经经过排序， 所以一种显而易见的做法就是在回溯时， 检查当前元素是否和上一个元素相同，即 nums[i - 1] == nums[i] 如果发现和上一个相同了就饿可以直接跳过（如 nums = [1, 2, 2'] nums[1] == nums[2], nums[2] 就直接跳过了）
需要注意的是 nums[i - 1] == nums[i] 的作用是在递归树的同一层上的， 也就是防止 nums = [1, 2, 2'] 出现 [1, 2]， [1, 2'] 两个重复的解 （即： 通过 nums[1] == nums[2]: continue 进行的剪枝）
而解 [1, 2, 2'] 实际中的 2, 2' 是位于递归树的不同层级的， 也就是剪枝要从每一层的第二个元素开始， 所以还要增加一个 i > start 或者 i != start
最终相对于子集 的思路就是要增加一个 i > start && nums[i - 1] == nums[i] 或 i != start && nums[i - 1] == nums[i] 的剪枝

作者：mrsate
链接：https://leetcode-cn.com/problems/subsets-ii/solution/jian-zhi-qu-zhong-de-si-lu-by-mrsate/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

void subsetsWithDupCore( vector<vector<int>>& res, vector<int>& temp ,vector<int>& nums, int k){

    res.push_back( temp);

    for( int i = k ;i< nums.size() ;i++){

        //遇到重复的数字时，直接进行跳过，防止出现重复解；
        if( i > k && nums[i-1] == nums[i]){
            continue;
        }
        //包括该元素
        temp.push_back( nums[i]);
        //进行递归
        subsetsWithDupCore( res, temp , nums,i+1);
        //进行回溯；
        temp.pop_back();
    }
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp;

        sort( nums.begin() ,nums.end());

        subsetsWithDupCore( res, temp ,nums, 0);

        return res;

    }
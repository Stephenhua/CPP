#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

*/

class Solution {
public: 

    vector<vector<int>> res;
    vector<int> temp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end());
        int size = candidates.size();
        Core( candidates,target,0);
        return res;
    }

    void Core(vector<int>& candidates, int target ,int start ){

            if( target == 0){
                res.push_back(temp);
                return;
            }

            for( int i = start ;i <candidates.size()&&target >= candidates[i] ; i++){

                //用于去重；主要是去掉同一层级的相同节点，不出现相同的元素；https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
                if( i> start && candidates[i]== candidates[i-1]){
                    continue;
                }

                temp.push_back( candidates[i]);
                Core( candidates, target-candidates[i],i+1);//i+1表示直接到下一个节点，避免了一个数字重复多次使用；
                temp.pop_back();
            }
            return;
    }
};
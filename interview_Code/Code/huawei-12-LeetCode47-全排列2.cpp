#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*
47. 全排列 II
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/


//对于重复的数字应该进行去重操作；

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        if(nums.size() == 0 ){
            return res;
        }
        if( nums.size() == 1){
            return {{nums[0]}};
        }
        vector<int> used(nums.size(),0);

        Core(res,path,used,nums);
        return res;

    }

    void Core(vector<vector<int>>& res, vector<int>&path, vector<int>& used ,vector<int>& nums){

        if( path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        //做选择；
        for(int i = 0 ; i < nums.size() ;i ++){
            //为了避免重复，直接跳过；
            if( used[i] == 1 ){
                continue;
            }
            //去重重复项就可以实现；
            if( i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }

            path.push_back(nums[i]);
            used[i] = 1;
            Core(res,path,used,nums);
            used[i] = 0 ;
            path.pop_back();
        }
    }
};

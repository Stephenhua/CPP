#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*

46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
//思路：回溯法

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

            path.push_back(nums[i]);
            used[i] = 1;
            Core(res,path,used,nums);
            used[i] = 0 ;
            path.pop_back();
        }
    }
};

//方法二：

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        int num =1 ;
        for(int i = 1 ;i <=size ;i++){
            num *=i;
        }

        sort(nums.begin(),nums.end());

        while( num--){

            res.push_back(nums);
            nextPermutation(nums);
        }

    }

};
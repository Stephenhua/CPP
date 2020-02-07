#include<iostream>
#include <vector>
using namespace std;

//方法一：采用遍历的形式进行；
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res(1);
        for(int i=0;i<nums.size();i++){
            int cnt =res.size();
            for(int j=0;j<cnt;j++){
                vector<int> temp=res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};

//方法二:回溯求解

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> res_temp;
        subset(res,res_temp,nums,0);
        return res;
    }
    void subset(vector<vector<int>> &res, vector<int> res_temp, vector<int>&nums,int level){
        if(res_temp.size()<=nums.size()){
            res.push_back(res_temp);
        }
        for(int i=level;i<nums.size();i++){
            res_temp.push_back(nums[i]);
            subset(res,res_temp,nums,level+1);
            res_temp.pop_back();
        }
    }
};
//方法三：采用深度优先遍历；运行时间较慢；
class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int>& tmp,vector<int> &nums,int level){
        if(level>nums.size()){
            res.push_back(tmp);
            return ;
        }

        tmp.push_back(nums[level]);
        helper(res,tmp,nums,level+1);
        tmp.pop_back();
        helper(res,tmp,nums,level+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res, tmp, nums, 0);
        return res;
    }

    
};
 #include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

/*
题目：
给定一个可包含重复数字的序列，返回所有不重复的全排列
*/

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;

    if( nums.size() == 0){
        return {};
    }else if( nums.size() == 1 ){
        return {{nums[0]}};
    }else{

        vector<bool> numsBool(nums.size(),true);
        vector<int>  current ;

        sort( nums.begin() ,nums.end());

        permuteUnuqueCore(nums, current ,numsBool,res);

        return res;
    }

}

void permuteUnuqueCore( vector<int>& nums, vector<int>& current , vector<bool>& numsBool , vector<vector<int>>& res){

    if( current.size() == numsBool.size()){

        res.push_back(current);

    }else{

        for(int i = 0 ;i< nums.size() ;i++){

            if( numsBool[i]){
            // 剪枝条件：i > 0 是为了保证 nums[i - 1] 有意义
            // 写 !used[i - 1] 是因为 nums[i - 1] 在深度优先遍历的过程中刚刚被撤销选择
                
                if( i > 0 && nums[i] == nums[i-1] && numsBool[i-1]){
                    continue;
                }

                current.push_back(nums[i]);
                numsBool[i] = false;

                permuteUnuqueCore( nums, current,numsBool, res);

                numsBool[i] = true;

                current.pop_back();
            }


        }
    }
}

//方法二：采用递归的形式,这样就不会有重复的数字出现；

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //利用了set进行对递归后的序列进行降重；
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start >= nums.size()) res.insert(nums);
        // i从start开始，这样可以避免重复的数字；
        for (int i = start; i < nums.size(); ++i) {

            //用于剪纸；num[i]== nums[start]可以很好地进行去重；
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};
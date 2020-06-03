#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
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

/*
https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/
解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

回溯方法框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
            将该选择从选择列表移除
            路径.add(选择)

        backtrack(路径, 选择列表)
        # 撤销选择
            路径.remove(选择)
            将该选择再加入选择列表
*/

//方法一：如果直接在调用中包含res;
void Core( vector<vector<int>>& res, vector<int>& track, vector<int>& nums ,vector<bool>& boolnums){

    if( track.size() == nums.size()){

        res.push_back( track);

        return;
    }

    int r = INT_MAX;

    for( int i = 0 ;i <nums.size();i++){
        
        //判断当前元素是否已经进行了遍历；
        //用来删选是否已经排过序的；
        if(boolnums[i]){

            //两次去重；
            if( nums[i] != r){

                r = nums[i];

                //去重；
                if( i>0 && nums[i-1]== nums[i] && boolnums[i-1]){

                    continue;
                }

                track.push_back( nums[i]);

                boolnums[i] = false;

                Core( res,nums,track,boolnums);

                boolnums[i] = true;

                track.pop_back();
            }


        }


    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<vector<int>> res;
    vector<int> track;
    vector<bool> boolnums( nums.size() ,true);

    sort( nums.begin() ,nums.end());

    Core( res, track,nums,boolnums);

    return res;
    
}


//方法二：
class Solution {
    void permuteUniqueCore(int a, const vector<int> &nums, vector<int> &curr, vector<int> &visited, vector<vector<int>> &ret) {
        if(a == nums.size()) {
            ret.push_back(curr);
        } else {
            
            int i = 0;

            while(visited[i] == 1) ++i;

            int prev = nums[i] > 0 ? -1 : 1;

            for(; i < nums.size(); ++i) {

                if(visited[i] == 1 || nums[i] == prev) continue;

                curr.push_back(nums[i]);

                visited[i] = 1;

                permuteUniqueCore(a+1, nums, curr, visited, ret);

                visited[i] = 0;

                curr.pop_back();

                prev = nums[i];

            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(begin(nums), end(nums));
        vector<int> curr;
        vector<int> visited(nums.size(), 0);
        permuteUniqueCore(0, nums, curr, visited, ret);
        return ret;
    }
};

//方法三：如果不包含res;

vector<vector<int>> res;

void Core( vector<int>& track, vector<int>& nums ,vector<bool>& boolnums){

    if( track.size() == nums.size()){

        res.push_back( track);

        return;

    }

    for( int i = 0 ;i <nums.size();i++){
            //排除已经用过的选项；
            if( boolnums[i]){
                continue;
            }
            //排除重复的值；，只保留一个即可；

            if( i>0 && nums[i-1]== nums[i] &&(!boolnums[i-1]) ){

               continue;

            }

            track.push_back( nums[i]);

            boolnums[i] = true;

            Core(nums,track,boolnums);

            boolnums[i] = false;

            track.pop_back();
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<int> track;
    vector<bool> boolnums( nums.size() ,false);

    sort( nums.begin() ,nums.end());

    Core(nums,track,boolnums);

    return res;
    
}
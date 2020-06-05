#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;


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

/*

路径：记录到track中；
选择列表：nums中不存在于track中的值；
结束条件：nums中的元素全部都在track中出现；

*/

void Core( vector<vector<int>>& res, vector<int>& nums, vector<int>& track){

    //满足结束条件；
    if( track.size() == nums.size()){
        res.push_back( track);
        return;
    }

    //做选择；
    for( int i= 0 ; i< nums.size() ;i++){

        //为了避免重复，应该讲find加入到其中；
        vector<int>::iterator iter = find( track.begin() ,track.end() ,nums[i]);

        if( iter != track.end()){
            continue;
        }

        track.push_back( nums[i]);
        Core( res,nums,track);
        track.pop_back();

    }
}

vector<vector<int>> permute(vector<int>& nums) {

   vector<vector<int>> res; //全局变量存储答案；

   vector<int> track ;//存储路径；

    Core( res, nums, track);

    return res;
}
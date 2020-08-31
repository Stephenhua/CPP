#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/


class Solution {
    private:
        vector<vector<int>> res;

public:

    void Core( vector<int>& temp,vector<int>& candidates, int target ,int& size,int start){

        if( target == 0){

            res.push_back( temp );

            return;
        }

        for( int i=start ;i<size; i++ ){
            if( candidates[i] > target){
                return ;
            }

            temp.push_back(candidates[i]);
            Core( temp,candidates,target-candidates[i],size,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort( candidates.begin() , candidates.end());
        vector<int> temp;   
        int size = candidates.size();
        Core( temp,candidates,target,size,0);

        return res;
        
    }
};
//方法二：回溯精简；

class Solutions{
    public:
        vector<vector<int>> res;
        vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        Core(candidates, target, 0);
        return res;
    }

    void Core( vector<int>& candidates, int target ,int start){
        if( target == 0){
            res.push_back(temp);
        }else{
            for( int i = start; i< candidates.size() ;i++){
                if( target - candidates[i]>=0){
                    temp.push_back( candidates[i]);
                    Core( candidates,target-candidates[i],i);
                    temp.pop_back();
                }
            }
        }
    }
};



class Solutions{
    public:
        vector<vector<int>> res;
        vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        Core(candidates, target, 0);
        return res;
    }
    //路径：candidates中的元素；
    //选择列表：candidates中的元素；
    //结果返回条件：target =  0 ;
    //start 表示从 candidates中开始的元素；

    void  Core( vector<int>& candiates ,int target,int start ){
        if(target == 0 ){
            res.push_back(temp);
            //该语句执行完毕以后，就直接可以返回当前层；
            return;
        }else{
            //下一层遍历的时候，可以直接从最初使用的那个点进行；
            for(int i = start ; i < candiates.size() ; i++){
                //这个语句相当于减枝操作；
                if( target-candiates[i] >= 0 ){
                    temp.push_back(candiates[i]);
                    Core(candiates,target-candiates[i],i);
                    temp.pop_back();
                }
            }
        }
    }

};

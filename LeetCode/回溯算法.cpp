#include <vector>
#include <iostream>
using namespace std;


//=================================================
/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
2020-2-7
*/
//==================================================
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> tempSum;
         //1、构建辅助函数以及加上判别条件；

         if(candidates==nullptr||candidates.size()==0||target<0){
             return tempSum;
         }

         vector<int> temp;
         prcocess(0, candidates,target,temp);



        return tempSum;
    }

    private:
    //2、进行递归的过程中，第一步要判断递归的终止条件，没有终止条件则会陷入死循环，
    void process(int start,vector<int>& candidates,int target,vector<int>& temp){
        if(target<0){
            return;
        }
        if(target==0){
            tempSum.push_back(temp);
        }else{
    //3、要求组成target的组合，需要一个循环进行遍历，每遍历一次，将这个数加入到temp，然后进行下一轮的递归。
            for(int i=0;i<candidates.size();i++){
    //5、每次递归从0开始，所有数字都遍历一遍，所以则会形成重复的组合，需要改进，将变量进行修改当前数值，同时修改process函数
                temp.push_back(candidates[i]);
                process(i, start，candidates,target-candidates[i],temp);
    //4、当递归完之后进行回溯，需要删除最新的那个数；
                temp.erase();
            }
        }

    }
};


//组合

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> temp_res;
        if(n<0||k<=0||k>n){
            return temp_res;
        }
        vector<int> temp;
        gengerateCombinations(n,k,1,temp);
        return temp_res;        
    }
private:
void generateCombinations(int n,int k, int start ,vector<int> temp){
    //1、列出终止条件
    if(temp_res.size()==k){
        temp_res.push_back(temp);
        return;
    }
    //2、进行剪纸操作，
    for(int i=start,i<=n-(k-temp.size())+1;i++){
        temp.push_back(i);
        generateCombinations(n,k,i+1,temp);
        temp.erase();
    }
}
};
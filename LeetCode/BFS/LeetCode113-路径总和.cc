#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

class Solution {
    vector<vector<int> > temp_sum;
    vector<int> temp;
    public:
     void hasPathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ret) {

         sum-=root->val;
         curr->push_back(root->val);
         if(sum==0 && root->right==nullptr&&root->left==nullptr){
            ret.push_back(curr);
         }
         if(root->left){
             hasPathSum(root->left,sum,curr,ret);
             curr.pop_back();//回溯；
         }

         if(root->right){
             hasPathSum(root->right,sum,curr, ret);
             curr.pop_back();
         }

     }


    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > temp_sum;
        vector<int> temp;
        if(root==nullptr){
            return temp_sum;
        }
        hasPath(root,sum,temp,temp_sum);
        return temp_sum;        
    }
};

//方法二：采用递归的形式执行
//进行回溯算法的过程中，注意回的方式，回的方式不同，最后的结果也不相同；
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(root, sum, path, ans);
        return ans;
    }
    
    void helper(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (!node) 
            return;
        if (!node->left && !node->right) {
            if (sum == node->val) {
                ans.push_back(path);
                ans.back().push_back(node->val);
            }
            return;
        }
        path.push_back(node->val);
        helper(node->left, sum-node->val, path, ans);
        helper(node->right, sum-node->val, path, ans);
        path.pop_back();
    }
};
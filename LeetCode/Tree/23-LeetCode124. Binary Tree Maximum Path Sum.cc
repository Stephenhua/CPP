/*
题目：124. 二叉树中的最大路径和
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        max_sum(root,ans);
        return ans;
    }

    int max_sum(TreeNode* root,int ans){
        if(root==nullptr){
            return 0;
        }

        int max_left=max_sum(root->left,ans);
        int max_right=max_sum(root->right,ans);
        
        ans=max(ans,root->val);
        ans =max(ans, max_left+root->val);
        ans =max(ans,max_right+root->val);
        ans=max(ans,max_left+max_right+root->val);
        if(max_left<=0 && max_right<=0){
            return root->val;
        }else{
            return (max_left>max_right)?(max_left+root->val):(max_right+root->val);
        }
    }
};

//官方答案
class Solution {
public:
    int ans;
    bool init = false;
    
    int maxPathSum(TreeNode* root) {
        aux(root);
        return ans;
    }
    
    int aux(TreeNode* root) {
        if (root == NULL) return 0;
        
        if (!init) {
            ans = root->val;
            init = true;
        }
        
        int left = aux(root->left);
        int right = aux(root->right);
        
        int val = root->val;
        ans = max(ans, val);
        ans = max(ans, val+left);
        ans = max(ans, val+right);
        ans = max(ans, val+left+right);
        
        int maxans = max({0, val, val+left, val+right});
        return maxans;
    }
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_path_sum = numeric_limits<int>::min();
        FindMaxPathSum(root, &max_path_sum);
        
        return max_path_sum;
    }
    
    int FindMaxPathSum(TreeNode* root, int* max_path_sum) {
        if (root == nullptr) {
            return 0;
        }
        
        auto left_max = FindMaxPathSum(root->left, max_path_sum);
        auto right_max = FindMaxPathSum(root->right, max_path_sum);
        
        *max_path_sum = max(*max_path_sum, root->val + left_max + right_max);
        
        return max(root->val + max(left_max, right_max), 0);
    }
};
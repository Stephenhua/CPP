/*
题目： 二叉树最大深度；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//深度优先搜锁的问题，每个节点只进栈和出栈一次；
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int max_depth=0;
        return dfs(root,max_depth);
        
    }
    int dfs(TreeNode* root ,int max_depth){
        if(!root){
            return max_depth;
        }
        int max_left=dfs(root->left,max_depth+1);
        int max_right=dfs(root->right,max_depth+1);
        return max(max_left,max_right);
    }
};

//采用广度优先的方法进行求解；
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        int max_depth=0;
        queue<pair<TreeNode* ,int>> temp_queue;
        temp_queue.push({root,1});
        while(!temp_queue.empty()){
            TreeNode* curr_Node=temp_queue.front().first;
            int curr_depth=temp_queue.front().second;
            temp_queue.pop();

            if(curr_Node){
                max_depth=max(curr_depth,max_depth);
                temp_queue.push({curr_Node->left,curr_depth+1});
                temp_queue.push({curr_Node->right,curr_depth+1});
            }
        }
        return max_depth;

    }


};

//官方答案：最简洁而且有效,采用递归方法；
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        int sum=0;
        if(root==nullptr){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return left>right?left+1:right+1;
    }

};

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        int sum=0;
        if(root==nullptr){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }

};

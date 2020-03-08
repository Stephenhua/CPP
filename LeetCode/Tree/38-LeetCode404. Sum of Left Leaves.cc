/*
题目:404
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//使用递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==nullptr){
            return 0;
        }
        if(root->left && !root->left->left && !root->left->right){
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }

};

//使用层次遍历的方法进行求解
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); 
            q.pop();
            if (t->left && !t->left->left && !t->left->right) res += t->left->val;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return res;
    }
};

//可以使用更加有效地方法进行求解，记性标记，将左子树标记为true;,
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return treeLeftLeastSum1(root,false);
    }
    int treeLeftLeastSum1(TreeNode* root, bool isLeft){
        int sum=0;
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right == nullptr){
            if(isLeft){
                return root->val;
            }
            else{
                return 0;
            }
        }
        sum+=treeLeftLeastSum1(root->left ,true);
        sum+=treeLeftLeastSum1(root->right,false);
        return sum;
    }
};
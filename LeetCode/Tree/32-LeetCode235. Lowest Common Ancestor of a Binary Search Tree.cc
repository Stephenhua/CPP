/*
题目：235. 二叉搜索树的最近公共祖先
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

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//采用迭代的方式
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val > root->val && q->val >root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;        
    }
};

//采用迭代的形式进行求解

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val >root->val && q->val >root->val){
                root=root->right;
            }
            else if(p->val < root->val && q->val < root->val){
                root= root->left;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
}；
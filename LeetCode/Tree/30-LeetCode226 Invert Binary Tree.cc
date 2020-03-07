/*
题目：226. 翻转二叉树
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
//思想：指针的指向问题；
//采用递归实现
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        TreeNode* left=invertTree(root->left);//用于左子树的全部递归
        TreeNode* right =invertTree(root->right);//用于右子树下面部分的全部递归；
        root->left=right;//将当前接节点的指针指向另一侧，节省了运行空间；
        root->right=left;
        return root;        
    }
};

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
//采用非递归进行实现；
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            TreeNode * temp=node->left;
            node->left=node->right;
            node->right=temp;
            if(node->left)
                q.push(node->left);
            if(node->right){
                q.push(node->right);
            }
        }
        return root;
    }

};
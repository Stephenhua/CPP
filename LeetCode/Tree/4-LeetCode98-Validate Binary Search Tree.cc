/*
题目：验证二叉搜索树；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//方法一：中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int *min_value=NULL;
        return DFS(root,min_value);        
    }

    bool DFS(TreeNode* root,int* min_vaulue){
        if(!DFS(root->left,min_vaulue)){
            return false;
        }

        if(min_vaulue && *min_vaulue >=root->val){

            return false;
        }

        min_vaulue=&root->val;

        if(!DFS(root->right,min_vaulue)){
            return false;
        }
        return true;
    }
};

//采用递归的形式进行

class Solution1 {
public:
    bool isVaildBST1(TreeNode* root ,long min,long max){
        if(!root){
            return true;
        }
        if(root->val<=min || root->val>=max){
            return false;
        }

        return isVaildBST1(root->left,min,root->val)&& isVaildBST1(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root){
        return isVaildBST1(root,LONG_MIN,LONG_MAX);
    }



};

//方法三：
class Solution {
public:
    bool check(TreeNode* root, long ceil, long floor) {
        if(!root) return true;
        if(root->val >= ceil) { return false; }
        if(root->val <= floor){ return false; }
        return check(root->left, root->val, floor) && check(root->right, ceil, root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->val, LONG_MIN) && check(root->right, LONG_MAX, root->val);
    }
};
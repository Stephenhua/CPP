/*
题目：112 路径和
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

//方法一：采用深度递归的方式,只要判断终止方式和终止条件，以及如何进行操作
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return false;
        }

        if(root->left==nullptr&& root->right==nullptr){
            return root->val==sum;
        }

        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);

    }
};

//方法二：
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return false;
        }

        sum-=root->val;
        if(root->left==nullptr && root->right==nullptr && sum==0){
            return true;
        }

        if(hasPathSum(root->left,sum)){
            return true;
        }
        return hasPathSum(root->right,sum);



    }

};


//方法三：
class Solution{
    public:
    bool hasPathSum(TreeNode* root ,int sum){
        if(root==nullptr){
            return false;
        }
        return helper2(root,sum);
    }

    bool helper2(TreeNode* root,int sum){
        if(root->right==NULL && root->left==NULL){
            return (sum-root->val)==0;
        }

        if(root->right==NULL){//如果左子树没有值得话，则就不
            return helper2(root->left,sum-root->val);
        }

        if(root->left==nullptr){
            return helper2(root->right,sum-root->val);
        }

        return helper2(root->left,sum-root->val) ||helper2(root->right,sum-root->val);
    }
};
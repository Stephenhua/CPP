#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {

 Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//方法一：采用深度搜所的形式进行
public:
void dfs(TreeNode *root ,int p,int &res){
    if(root==nullptr){
        return ;
    }
    
    //用于求和，每次遍历一个节点进行求和相加；
    p=10*p+root->val;
    //每个节点都需要完成的事情
    //只有到达了叶子最下面的叶子节点时，才会出现相加到全部变量中；
    if(root->left==nullptr&&root->right==nullptr){
        res+=p;
        return ;
    }
    dfs(root->left,p,res);
    dfs(root->right,p,res);
    }

    int sumNumbers(TreeNode*root){
        int res=0;
        dfs(root ,0,res);//深度优先的算法
        return res;
    }
};

//解法二：采用最优的形式进行
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        res=sumNumbersDFS(root,0);
        return res;
    }
    int  sumNumbersDFS(TreeNode *root,int sum){
        if(!root)return 0;
        if(!root->left&&root->right==nullptr) return sum*10+root->val;
        return sumNumbersDFS(root->left,sum*10+root->val)+sumNumbersDFS(root->right,sum*10+root->val);
    }
};
/*
题目：二叉树的中序遍历；
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

//采用的递归形式
class Solution{
    public:
    void dfs(vector<int>&result, TreeNode*root){
        if(root==nullptr){
            return ;
        }
        
        dfs(result,root->left);
        result.push_back(root->val);
        dfs(result,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        vector<int > result;
        dfs(result,root);
        return result;
    }
};

//采用栈的形式进行求解
class Solution{
    public:
    vector<int> inorderTraversal(TreeNode* root){

        stack<TreeNode*> s;
        vector<int> solution;
        if(!root) return solution;
        TreeNode* cur=root;
        while(cur || !s.empty()) {
          while(cur) {
              s.push(cur);
              cur=cur->left;
          }
            TreeNode* node=s.top();
            s.pop();
            solution.push_back(node->val);
            cur=node->right;
        }
        return solution;
    }

};
//采用Morris遍历，时间复杂度为O(1),空间复杂度为O(n)；
//链接：https://zhuanlan.zhihu.com/p/89858150
/*算法流程：
1）令根节点为current节点；

2）current是否为空
    a）如果为空
        则结束
    b）如果不为空
        current是否有左孩子
            如果有
                在Current左子树中，令current称为最右侧的右子节点；
                移动到左孩子，并把父节点左指针删除，防止循环；
            如果没有
                输出current的值
                current移动到右孩子
                继续循环current的 2）开始部分
*/

void Morris_InorederTraversal(TreeNode* root){
    TreeNode* cur=root;
    TreeNode * pre;
    while(cur!=NULL){
        if(cur->right==nullptr){
            cout<<cur->val;
            cur=cur->right;
        }else{
            pre=cur->left;
            while(pre->right!=nullptr){
                pre=pre->right;
            }

            pre->right=cur;
            //删除左孩子防止循环

            TreeNode* temp=cur;
            cur=cur->left;
            temp->left=nullptr;
        }
    }
}

//Morris前序遍历

void Morris_PreTraversal(TreeNode* root){
    TreeNode* cur=root;
    TreeNode * pre;
    while(cur!=nullptr){

        if(cur->left==nullptr){
            cout<<cur->val<<endl;
            cur=cur->right;
        }else{
            pre=cur->left;
            while(pre->right!=nullptr){
                pre=pre->right;
            }
            if(pre->right ==nullptr){
                cout<<cur->val;
                pre->right=cur;
                cur=cur->left;
            }else{
                pre->right=nullptr;
                cur=cur->right;
            }
        }
    }

}
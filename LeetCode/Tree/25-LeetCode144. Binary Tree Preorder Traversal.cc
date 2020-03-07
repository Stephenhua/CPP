/*
题目：144. 二叉树的前序遍历
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
//方法一：前序遍历；递归法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root){
            return result;
        }
        preOrder(root,result);
        return result;
    }
    void preOrder(TreeNode* root,vector<int> result){
        if(!root){
            return ;
        }
        result.push_back(root->val);
        preOrder(root->left,result);
        preOrder(root->right,result);
    }
};

//方法二：采用迭代法进行求解

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode* >result;
        vector<int> Result;

        if(!root){
            return Result;
        }
        result.push(root);
       while(!result.empty()){
           TreeNode* temp= result.top();
           Result.push_back(temp->val);
           result.pop();
           if(temp->right!=NULL ){
               result.push(temp->right);
           }

           if(temp->left!=NULL){
               result.push(temp->left);
           }


       }
        return Result;
    }

};

//方法三：借助辅助结点P,
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(p ||!s.empty()){//判断P是否为空以及P指针上面是否为空；
            if(p){
                s.push(p);
                res.push_back(p->val);
                p=p->left;
            }else{
                TreeNode* t=s.top();
                s.pop();//将最顶层的点进行遍历；
                t=t->right;//转向右子树；；
            }
        }
         return res;
    }
};
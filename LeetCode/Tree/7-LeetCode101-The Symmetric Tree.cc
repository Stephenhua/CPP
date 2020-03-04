/*
题目：堆成二叉树；
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

//方法一：进行递归；
/*
递归结束的条件：
1）都为空指针，则返回true
2）只有一个空指针，则返回false；

递归过程：
1）判断两个指针的当前节点是否相等；
2）判断A的右子树与B的左子树是否对称；
3）判断Ade左子树与B的右子树是否

*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root );
        
    }
    bool isMirror(TreeNode * root ,TreeNode* root1){
        if(root ==nullptr && root1==nullptr){
            return true;
        }

        if(root==nullptr || root1==nullptr){
            return false;
        }

        return (root->val==root1->val ) &&isMirror(root->left,root1->right)&& isMirror(root->right,root1->left);
    }
};
//使用栈进行递归遍历；
class Solution {
public:
     bool isSymmetric(TreeNode* root) {
         if(root==NULL){
             return true;
         }

         stack<TreeNode*> result;
         result.push(root->left);
         result.push(root->right);
         while(!result.empty()){
             TreeNode* t1=result.top();
             result.pop();
             TreeNode* t2=result.top();
             result.pop();

             if(!t1&& !t2){
                 continue;
             }

             if(!t1||!t2){
                 return false;
             }

             if(t1->val !=t2->val){
                 return false;
             }

             result.push(t1->left);
             result.push(t2->right);
             result.push(t1->right);
             result.push(t2->left);
         }
         return true;

     }
};
/*
题目：相同的树；
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

//方法一：采用递归法
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if((p==NULL &&q!=NULL) || (p!=NULL && q==NULL) || (p->val!=q->val)){
            return false;
        }
        return (isSameTree(p->left,q->left)&& (isSameTree(p->right,q->right)));
    }
};

//方法二：采用判断的形式；
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){
            return true;

        }else if(p==NULL||q==NULL){
            return false;
        }
        if(!isSameTree(p->left,q->left)){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        if(!isSameTree(p->right,q->right)){
            return false;
        }
        return true;

    }
};
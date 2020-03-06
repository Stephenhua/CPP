/*
题目：110. 平衡二叉树
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
//判断是否为平衡二叉树，则采用后序遍历的方式遍历整个二叉树，遍历左右节点可以判断左右节点的深度，是不是平衡二叉树，从底上下的方式进行；
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth= 0;
        return isBalanced_1(root,&depth);

    }

    bool isBalanced_1(TreeNode* pRoot ,int *Depth){
        if(pRoot==nullptr){
            *Depth=0;
            return true;
        }

        int left ,right;
        if(isBalanced_1(pRoot->left,&left)&& isBalanced_1(pRoot->right,&right)){
            int diff=left-right;
            if(diff<=1 &&diff >=-1){
                *Depth=1+(left>right)?left:right;
                return true;
            }
        }
        return false;
    }
};
//采用递归的手段进行；比较每一个节点的左子树和右子树的之间深度的关系，从底到顶的方式进行；
class Solutions{
    public:

    bool isBalancedRes=true;
    bool isBalanced(TreeNode* root){
        if(!root){
            return true;
        }
        isBalancedCore(root);
        return isBalancedRes;
    }

    int isBalancedCore(TreeNode* root){
        if(!root){
            return 0;
        }else{
            int left=isBalancedCore(root->left);
            int right=isBalancedCore(root->right);
            if(abs(left-right)>1){
                isBalancedRes=false;
            }
            return 1+max(left,right);
        }

    }
};

//方法三：
class Solutions{
    bool isBalanced(TreeNode* root){
        return search(root)>=0;
    }
    int search(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=search(root->left);
        int right=search(root->right);

        if(right<0 ||left <0 ||abs(right-left)>1){
            return -1;
        }else{
            return max(left,right)+1;
        }
    }

};
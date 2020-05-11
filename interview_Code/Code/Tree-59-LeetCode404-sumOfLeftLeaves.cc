#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：左叶子之和
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：采用不带返回值的递归调用；
void Core(TreeNode* root ,int& res){
    if(root == nullptr){
        return  ;
    }

    if(root->left!= nullptr && root->left->left == nullptr && root->left->right == nullptr){
        res +=root->left->val;
    }

    Core(root->left ,res);
    Core(root->right ,res);

}
int sumOfLeftLeaves(TreeNode* root) {
    if(root == nullptr){
        return 0 ;
    }

    int res =0 ;
    Core(root,res);
    return res;
}

//方法二：采用带有返回值得递归调用；

int sumOfLeftLeaves(TreeNode* root){
    return dfs(root);
}

int dfs(TreeNode* root){
    if(root == nullptr){
        return 0 ;
    }
    int sum = 0;
    if(root->left!=nullptr && root->left->left!= nullptr && root->left->right != nullptr){
        sum += root->left->val;
    }

    return dfs(root->left)+ dfs(root->right)+sum ;
    
}
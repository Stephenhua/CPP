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

题目：最大BST子树；

*/

bool isVaildBST( TreeNode* root ,int min ,int max){
    if( root= nullptr){
        return true;
    }

    if( root->val <= min || root->val >=max){
        return false;
    }

    return isVaildBST(root->left ,min,root->val) && isVaildBST(root->right , root->val ,max );

}

int count(TreeNode* root){
    if(root == nullptr){
        return 0 ;
    }

    return count(root->left)+count(root->right)+1;

}
int largestBSTSubtree( TreeNode* root){

    if(root == nullptr){
        return 0;
    }
    //先判断是不是搜索二叉树
    if( isVaildBST( root ,INT_MIN ,INT_MAX)){
        //统计二叉树的节点个数；
        return count(root);
    }

    return max(largestBSTSubtree(root->left) ,largestBSTSubtree(root->right));
}
#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：反转二叉树
*/

//采用递归的形式进行求解；

TreeNode* invertTree(TreeNode* root) {

    if(root == nullptr){
        return nullptr;
    }
    return root;
}

void  invertTreeCore( TreeNode* root){

    if(root->left == nullptr && root->right == nullptr){
        return ;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left){
        invertTreeCore(root->left);
    }

    if(root->right){
        invertTreeCore(root->right);
    }
  }



TreeNode* invertTree( TreeNode* root){

      if(root == nullptr){
          return nullptr;
      }

      TreeNode* TLeft = invertTree(root->left);
      TreeNode*TRight = invertTree(root->right);

      root->left = TRight;
      root->right = TLeft;

      return root;
  }
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


  //方法二：采用迭代的形式进行求解
class Solution {
public:
    TreeNode* invertTree(TreeNode* root){
        queue<TreeNode*> q;

        if( root != nullptr ){
            q.push(root);
        }

        while( q.size() != 0){

            TreeNode* tr = q.front();//获取队列的首个元素；
            q.pop();

            swap(tr->left,tr->right);//交换左右子树的指针；
            
            //更新之后的左右子树直接压入到queue中，实现迭代遍历；
            if( tr->left){
                q.push(tr->left);
            }

            if( tr->right){
                q.push(tr->right);
            }
        }

        return root;


    }
};  

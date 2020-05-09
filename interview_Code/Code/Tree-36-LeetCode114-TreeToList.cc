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
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
TreeNode* pre =nullptr;

void flattenCore(TreeNode* root){
    if(root == nullptr){
        return;
    }

    flattenCore(root->right);
    flattenCore(root->left);
    root->left = nullptr;
    root->right = pre;
    pre= root;
}
    void flatten(TreeNode* root) {
	    flattenCore(root);
	}

//采用非递归的形式进行
void flatten( TreeNode* root){
    if(root == nullptr){
        return;
    }

    TreeNode *p = root;
    while ( p != nullptr){
        TreeNode * cur = p->right;

        p->right = p->left;
        p->left = nullptr ;
        TreeNode* t = p;
        while( t->right){
            t = t->right;
        }

        t->right = cur ;
        p = p->right;
    }
}
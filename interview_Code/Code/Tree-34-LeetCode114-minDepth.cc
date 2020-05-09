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
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0 ;
        }
        int left= minDepth(root->left);
        int right = minDepth(root->right);
        return !root->left || !root->right?left+right+1:1+std::min(left,right);
    }
//方法二：
    int minDepth(TreeNode* root) {
      if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return 1;
        }

        int min_Dpth=INT_MAX;
        if(root->left){
            min_Dpth=min(minDepth(root->left),min_Dpth);
        }
        if(root->right){
            min_Dpth=min(minDepth(root->right),min_Dpth);
        }

        return min_Dpth+1;
    }
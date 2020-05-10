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
题目：二叉树的右视图
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//方法一：采用广度优先算法进行求解；

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root == nullptr){
        return res;
    }

    queue<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()){

        int size =nodes.size();
        res.push_back(nodes.back()->val);

        for(int i =0 ;i <size; i++){
            
            TreeNode* node = nodes.front();
            nodes.pop();

            if(node->left){
                nodes.push(node->left);
            }

            if(node->right){
                nodes.push(node->right);
            }
        }
    }

    return res;
}
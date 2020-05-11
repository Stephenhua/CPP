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
题目：寻找二叉树的叶子结点；
给你一棵二叉树，请按以下要求的顺序收集它的全部节点：

依次从左到右，每次收集并删除所有的叶子节点
重复如上过程直到整棵树为空
 

示例:

输入: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

输出: [[4,5,3],[2],[1]]
 

解释:

1. 删除叶子节点 [4,5,3] ，得到如下树结构：

          1
         / 
        2          
 

2. 现在删去叶子节点 [2] ，得到如下树结构：

          1          
 

3. 现在删去叶子节点 [1] ，得到空树：

          []         

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-leaves-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：采用结点的最大深度进行计算，将具有同一个深度的节点进行放置到同一个vector中，从底向上进行计算；

int  dfs( TreeNode* root ,map<int,vector<int>>& res){
    if(root == nullptr){
        return 0;
    }

    int d = 1+ max( dfs(root->left, res),dfs(root->right,res));

    res[d].push_back(root->val);
    return d;
}
vector<vector<int>> findLeaves(TreeNode* root) {

    map<int ,vector<int>> res;
    dfs(root ,res);
    vector<vector<int>> result;
    for( auto &p:res){
        result.push_back(p.second);
    }
    return result;
}

//判断条件 root->right 和root->left 都为nullpter时，为同一个类型；

void dfs(TreeNode* root ,vector<int>& delNode){
    if(root == nullptr){
        return;
    }

    if( root->left == nullptr && root->right == nullptr){
        delNode.push_back(root->val);
        root =nullptr;
        return;
    }
    
    dfs(root->left ,delNode);
    dfs(root->right ,delNode);
    
}
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> vt;
    bool bLeaf = false;

    while(root !=nullptr){
        vector<int> delNode;
        dfs(root ,delNode);
        vt.push_back(delNode);
    }
    return vt;
}


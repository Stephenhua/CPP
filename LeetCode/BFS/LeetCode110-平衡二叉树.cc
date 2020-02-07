#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//方法一：从低到顶的地提前阻断法
/*
对二叉树做深度优先遍历DFS，递归过程中：
终止条件：当DFS越过叶子节点时，返回高度0；
返回值：
从底至顶，返回以每个节点root为根节点的子树最大高度(左右子树中最大的高度值加1max(left,right) + 1)；
当我们发现有一例 左/右子树高度差 ＞ 1 的情况时，代表此树不是平衡树，返回-1；
当发现不是平衡树时，后面的高度计算都没有意义了，因此一路返回-1，避免后续多余计算。
最差情况是对树做一遍完整DFS，时间复杂度为 O(N)。
*/
 Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int depth(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int left =depth(root->left);
        if(left==-1){
            return -1;
        }
        int right=depth(root->right);
        if(right ==-1){
            return -1;
        }
        return abs(left-right)<2?max(left,right)+1:-1;
    }
    bool isBalanced(TreeNode* root) {
        return depth(root)!=-1;        
    }

    

};

//==========================================
//方法二：采用同样的形式进行深度优先的方法进行判别
//===========================================
class Solution {
public:
    int dfs(TreeNode* head)
    {
        if (head==NULL)
            return 0;
        int d_left = dfs(head->left);
        int d_right = dfs(head->right);
        
        if (d_left>=0 and d_right>=0 and abs(d_left-d_right)<=1)
            return max(d_left, d_right)+1;
        else
            return -1;
    }
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root)>=0;
    }
};

//==========================================
//方法三：采用同样的形式进行深度优先的方法进行判别
//===========================================
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        depth(root, flag);
        return flag;
    }
    int depth(TreeNode* root, bool& flag){
        
        if (root == NULL){
            return 0;
        }
        int left = depth(root->left, flag);
        int right = depth(root->right, flag);
        if (abs(left - right) > 1){//该判断可以有效介绍判断；
            flag = false;
        }
        return max(left, right) + 1;
    }
};
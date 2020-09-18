#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right;
    TreeNode(int x ) :val(x),left(NULL),right(NULL){ }
};

/*
783. 二叉搜索树节点最小距离
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。

*/

/*
二叉搜索树：中序遍历实际上相当于从左到右依次遍历；
*/
class Solution {
public:
int res = INT_MAX;
int prev  ;
    int minDiffInBST(TreeNode* root) {

        dfs(root);
        return res;
    }

    void dfs( TreeNode* root){
        if( root == nullptr ){
            return ;
        }
        dfs(root->left);
        if( prev ){
            res = min ( res , root->val - prev);
        }
        prev = root->val;

        dfs(root->right);
    }
};
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

 Definition for a binary tree node.

class Solution {
public:
    int max_sum=INT_MIN;//设定为全局变量
    int max_gain(TreeNode * node){
        
        if(node ==nullptr){
            return 0;
        }

        int left_gain=max(max_gain(node->left),0);
        int right_gain=max(max_gain(node->right),0);
        int price_newpath= node->val+left_gain+right_gain;

        max_sum=max(max_sum,price_newpath);

        return node->val+max(left_gain,right_gain);

       }
    
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;

        
    }
};


//方法二：采用深度搜索形式进行
class Solution {
public:
    int maxValue;
    
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN;
        dfs_pathsum(root);
        return maxValue;
    }
    
    int dfs_pathsum(TreeNode* node) {
        //判断边界条件
        if (!node)
            return 0;
        //进行深度优先计算左右子树的值
        int left = max(0, dfs_pathsum(node->left));
        int right = max(0, dfs_pathsum(node->right));
        //计算节点的值，判断当前节点与全局变量的值进行比较，深度搜索始终将最大的值存起来
        maxValue = max(maxValue, left + right + node->val);
        //将有效路径的值存起来
        return max(left, right) + node->val;
    }
};


//方法三：依旧采用深度搜索的形式进行
class Solution {
public:
    int result = 0;
    int helper(TreeNode * root) {
        if (root == nullptr)
            return 0;
        int leftVal = helper(root->left);
        int rightVal = helper(root->right);
        result = max(result, max(root->val, max(max(root->val + leftVal, root->val + rightVal), root->val + leftVal + rightVal)));
        return max(max(root->val + leftVal, root->val + rightVal), root->val);
    }
    int maxPathSum(TreeNode* root) {
        result = root->val;
        helper(root);
        return result;
    }
};
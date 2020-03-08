/*
题目:213 打家劫舍三
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//方法一：采用递归的形式进行计算
/*
爷爷节点获取到最大的偷钱数是多少呢？
1、首先要明确相邻的节点不能偷，也就是爷爷选择偷，儿子就不能偷了，但是孙子可以偷
2、二叉树只有左右两个孩子，一个爷爷最多2个儿子，4个孙子
根据以上条件，可以得出单个节点的钱该怎么算：
(4个孙子的偷的钱+爷爷的钱)  VS   (两个儿子偷的钱)
https://leetcode-cn.com/problems/house-robber-iii/solution/c-dong-tai-gui-hua-by-xdb-3/
*/
class Solution {
public:
	int rob(TreeNode* root) {
		if (root == nullptr) return 0;
		int money = root->val;
		if (root->left != nullptr) {//左孩子不为空，把孙子的钱抢了
			money += rob(root->left->left) + rob(root->left->right);
		}
		if (root->right!=nullptr)//右孩子不为空，把孙子的钱抢了
		{
			money += rob(root->right->left) + rob(root->right->right);
		}
		return max(money, rob(root->left) + rob(root->right));//抢孙子及爷爷的钱和抢两个儿子的钱进行比较
	}
};


//方法二：采用哈希表进行缓存；，然后进行递归操作
class Solution1 {
public:
	int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return Core(root,dp);
    }
    int Core(TreeNode* root, unordered_map<TreeNode*,int>& dp){
        if(root==nullptr){
            return 0;
        }

        if(dp.find(root)!=dp.end()){
            return dp[root];
        }

        int money=root->val;
        if(root->left!=nullptr){
            money+=Core(root->left->left,dp)+Core(root->left->right,dp);
        }
        if(root->right!=nullptr){
            money+=Core(root->right->left,dp)+Core(root->right->right,dp);
        }
        money=max(money,Core(root->left,dp)+Core(root->right,dp));
        dp.insert({root,money});
        return dp[root];
    }
};

//方法三：采用递归的形式进行计算；、

    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }

//方法四：依旧分为两种情况；

    class Solution {
    private:
    unordered_map<TreeNode*,int>m;

public:
    int dfs(TreeNode* node){
        if(!node) return 0;
        if(m.count(node)) return m[node];
        if( node->left && node->right)
            m[node] = max(dfs(node->left)+dfs(node->right),node->val+dfs(node->left->left)+dfs(node->left->right)+dfs(node->right->left)+dfs(node->right->right));
        else if(!node->left && node->right)
            m[node] = max(dfs(node->left)+dfs(node->right),node->val+dfs(node->right->left)+dfs(node->right->right));
        else if(node->left && !node->right)
            m[node] =max(dfs(node->left)+dfs(node->right),node->val+dfs(node->left->left)+dfs(node->left->right));
        else
            m[node] = node->val;
        return m[node];
    }
    
    
    int rob(TreeNode* root) {
        m[NULL] =0;
        dfs(root);
        return m[root];
    }
};
/*
题目：111. 二叉树的最小深度
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
/*
解题思路：
很多人写出的代码都不符合 1,2 这个测试用例，是因为没搞清楚题意

题目中说明:叶子节点是指没有子节点的节点，这句话的意思是 1 不是叶子节点

题目问的是到叶子节点的最短距离，所以所有返回结果为 1 当然不是这个结果

另外这道题的关键是搞清楚递归结束条件:
分为三种情况去讨论，叶子结点，单个节点，没有节点；

叶子节点的定义是左孩子和右孩子都为 null 时叫做叶子节点
1）当 root 节点左右孩子都为空时，返回 1
2）当 root 节点左右孩子有一个为空时，返回不为空的孩子节点的深度
3）当 root 节点左右孩子都不为空时，返回左右孩子较小深度的节点值
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        //对应的第一种情况；
        if(root->right==nullptr && root->left==nullptr){
            return 1;
        }

        //左右孩子只有一个为空，那么需要返回较大的那个孩子的深度；
        int m1=minDepth(root->left);
        int m2=minDepth(root->right);
        //只有一个节点为空，说明，m1或者m2有一个为空，所以m1+m2+1符合这个要求；
        if(root->left==nullptr || root->right==nullptr){
            return m1+m2+1;
        }

        //第三种情况，左右孩子都不为空，则返回最小值；

        return min(m1,m2)+1;


    }
};

//方法二：只采用递归的方法进行求解；
class Solutions{
    public:
    int minDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left){
            return 1+minDepth(root->right);//如果当前节点的右子树为空，则直接计算自叶子结点的值；
        }else if(!root->right){
            return 1+minDepth(root->left);//同上；
        }

        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return 1+min(left,right);
    }
};
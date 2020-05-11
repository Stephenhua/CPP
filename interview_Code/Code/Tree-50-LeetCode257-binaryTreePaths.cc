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
题目：二叉树的所有路径；
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//方法一：递归

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr){
            return res;
        }

        dfs( root,res, to_string(root->val));
        return res;
    }

    void dfs( TreeNode* root ,vector<string>& res, string strpath){

        if( root->left == nullptr && root->right == nullptr){
            res.push_back( strpath);
            return;
        }

        if( root->left != nullptr){
            dfs( root->left ,res, strpath+"->"+to_string(root->left->val));
        }

        if( root->right != nullptr){
            dfs( root->right ,res, strpath +"->"+ to_string(root->right->val));
        }
    }

    //非迭代法
    void process(TreeNode* node , vector<string>& v){

        if( node->left == nullptr && node->right == nullptr){
            v.back() += to_string(node->val);
            return;
        }else if( node->left && node->right == nullptr)
        {
            v.back() += (to_string(node->val + '->'));
            process( node->left ,v);             
        }else if( node->right  && node->left == nullptr){
            v.back() += (to_string(node->val + '->'));
            process( node->right ,v); 
        }else{
            v.back() += (to_string(node->val + '->'));
            string s = v.back();
            process(node->left,v);
            v.push_back(s);
            process(node->right,v);
        }
        
    }

        vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr){
            return res;
        }
        res.push_back(string());
        process( root ,res);
        return res;
    }

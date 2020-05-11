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
题目: 二叉树最长连续序列
*/
//方法一:采用递归的形式进行；
    int res = 0;

    int longestConsecutive(TreeNode* root) {
        if(root == nullptr){
            return res;
        }

        Core( root ,1);
        return res;
    }

    void Core( TreeNode* root ,int ans){
        if( root->left == nullptr && root->right == nullptr){
            res = max(res ,ans);
        }

        if(root->left){

            if( root->left->val != root->val+1){//如果不符合则需要重新进行查找；
                res = max( res, ans);//保存最大值；
                Core( root->left ,1);//重新进行查找；
            }else{
                Core( root->left,ans+1);
            }
        }

        if(root->right){

            if(root->right->val != root->val+1){
                res = max( res, ans);
                Core(root->right ,1);
            }
            else{
                Core( root->right ,ans+1);
            }
        }
    }

    //方法二:更简单；

int longestConsecutive(TreeNode* root) {
        if(root == nullptr){
            return res;
        }

        dfs( root ,1);
        return res;
}

void dfs( TreeNode* root ,int k){

    if( root == nullptr){
        return;
    }

    res = max( res, k);

    if( root->left !=nullptr){

        if( root->left->val == root->val+1){
            dfs(root->left ,k+1);
        }else{
            dfs(root->left,1);
        }
    }

    if( root->right != nullptr){

        if(root->right->val == root->val+1){
            dfs(root->right, k+1);
        }else{
            dfs(root->right, 1);
        }
    }
}
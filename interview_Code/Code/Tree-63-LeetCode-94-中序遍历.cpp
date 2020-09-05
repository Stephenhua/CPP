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

//递归；
vector<int> res;

vector<int> Inorder(TreeNode* root){
    Core(root);
    return res;
}

void Core(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    if(root->left){
        Core(root->left);
    }
    res.push_back(root->val);
    if(root->right){
        Core(root->right);
    }
}

//迭代法

vector<int> Inorder(TreeNode* root ){
    vector<int> res;
    if(root == nullptr ){
        return res;
    }

    stack<TreeNode*> sta;
    TreeNode* cur = root ;
    while (!sta.empty() || cur)
    {
        if(cur != nullptr ){
            sta.push(cur);
            cur = cur->left;
        }else{
            cur = sta.top();
            sta.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
    return res;
    
}
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

vector<int> preOrder(TreeNode* root ){
    vector<int> res;
    if( root == nullptr ){
        return res;
    }

    stack<TreeNode*> sta ;
    sta.push(root);
    while(!sta.empty()){
        TreeNode * cur = sta.top();
        sta.pop();
        res.push_back(cur->val);

        if(cur->right){
            sta.push(cur->right);
        }

        if(cur->left){
            sta.push(cur->left);
        }
    }
    return res;
}

//递归实现；
vector<int> res;
vector<int> preOrder(TreeNode* root){
    Core(root);
    return res;
}

void Core(TreeNode* root){
    if(root == nullptr ){
        return ;
    }

    res.push_back(root->val);
    Core(root->left);
    Core(root->right);
}
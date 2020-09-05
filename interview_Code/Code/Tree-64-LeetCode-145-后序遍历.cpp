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


vector<int> res;
vector<int> inorderTraversal(TreeNode* root){
    
    Core(root);
    return res;
}

void Core(TreeNode* root ){
    if(root == nullptr ){
        return ;
    }
    Core(root->left);
    Core(root->right);
    res.push_back(root->val);
}

//迭代法
vector<int> posterTraversal(TreeNode* root ){
    vector<int> res;
    if( root == nullptr ){
        return res;
    }
    stack<TreeNode*> sta;
    sta.push(root);
    while (!sta.empty())
    {
        TreeNode* cur = sta.top();
        sta.pop();
        res.push_back(cur->val);
        if(root->left){
            sta.push(root->left);
        }
        if(root->right){
            sta.push(root->right);
        }
        /* code */
    }

    reverse(res.begin(),res.end());
    return res;
    
}

//迭代法二：进行直接选择仅利用栈去判断该节点是否为父结点，创新性思路是每次在栈中压入父节点后压入nullptr，之后再依次压入右子节点和左子节点。

vector<int> posterTraversal(TreeNode* root ){
    vector<int> res;
    if(root == nullptr ){
        return res;
    }

    stack<TreeNode* > sta;
    sta.push(root);
    vector<int> res;

    while( !sta.empty()){
        TreeNode* curNode = sta.top();
        if(curNode == nullptr){
            sta.pop();
            res.push_back(sta.top()->val);
            sta.pop();
            continue;
        }

        sta.push(nullptr);
        if(curNode->right){
            sta.push(curNode->right);
        }

        if(curNode->left){
            sta.push(curNode->left);
        }
    }

    return res;
}
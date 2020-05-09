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


//后序遍历，

//方法一：非递归；

vector<int> postorderTraversal(TreeNode* root) {

    vector<int> result;

    if(root == nullptr){
        return result;
    }

    stack<TreeNode*> temp;
    TreeNode* last = nullptr;

    while( !temp.empty() || root){
        
        if(root){
            temp.push(root);
            root = root->left;
        }else{
            TreeNode* node = temp.top();
            if( node->right && last != node->right){
                root = root->right;
            }else{
                result.push_back(node->val);
                last = node;
                temp.pop();                
            }
        }
    }
    return result;
}
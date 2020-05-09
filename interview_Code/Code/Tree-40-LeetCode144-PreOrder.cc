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
前序遍历
*/
//方法一：非递归；
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }

        stack<TreeNode*> stackNode;
        stackNode.push(root);

        while (!stackNode.empty())
        {
            TreeNode* node = stackNode.top();
            stackNode.pop();
            result.push_back(node->val);
        //先向右遍历，然后向左遍历；
            if(node->right){
                stackNode.push(node->right);
            }
            if(node->left){
                stackNode.push(node->left);
            }
        }
        return result;        
    }
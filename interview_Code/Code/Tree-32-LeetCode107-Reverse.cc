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
二叉树的层次遍历 II
*/

//采用先遍历，然后进行求解；
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> NodeStack;
    NodeStack.push(root);
    stack<vector<int>> temp_result;
    while (!NodeStack.empty())
    {
        int size = NodeStack.size();
        vector<int> tmep;
        while (size--)
        {
            TreeNode* node = NodeStack.front();
            NodeStack.pop();
            tmep.push_back(node->val);
            if(node->left){
                NodeStack.push(node->left);
            }

            if(node->right){
                NodeStack.push(node->right);
            }
            /* code */
        }
        temp_result.push(tmep);        
        /* code */
    }

    while(!temp_result.empty()){
        vector<int> temp = temp_result.top();
        temp_result.pop();
        result.push_back(temp);
    }
    return result;
    
 }

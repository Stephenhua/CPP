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

题目：二叉树层次遍历

*/
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if( root == NULL){
            return result;
        }

        queue<TreeNode*> stackTree;
        stackTree.push(root);

        while( !stackTree.empty()){
            int size = stackTree.size();
            vector<int> temp_result;
            while(size--){
                TreeNode* node = stackTree.front();
                stackTree.pop();
                temp_result.push_back(node->val);
                if(node->left){
                    stackTree.push(node->left);
                }

                if(node->right){
                    stackTree.push(node->right);
                }
            }

            result.push_back(temp_result);
        }

        return result;        
    }
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
题目： 二叉树的锯齿形层次遍历
*/
//方法一：直接进行求解，然后利用二分法进行交换；
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if( root == NULL){
            return result;
        }

        queue<TreeNode*> stackTree;
        stackTree.push(root);
        bool flag =true;

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

        for(int i =1 ;i<result.size() ;i+=2){
            reverse(result[i].begin() ,result[i].end());
        }

        return result;       
    }
//方法二：利用两个队列进行求解；翻转数组直接就可以；

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        queue<TreeNode*> current ,next;

        bool left_to_right = true;

        if(root == nullptr){
            return result;
        }else{
            current.push(root);
        }

        while(!current.empty()){
            vector<int> level;

            while( !current.empty()){
                TreeNode* node = current.front();
                current.pop();

                level.push_back( node->val);

                if(node->left !=nullptr){
                    next.push(node->left);
                }
                if(node->right != nullptr){
                    next.push(node->right);
                }
            }

            if(!left_to_right){
                reverse(level.begin() ,level.end());
            }

            result.push_back(level);
            left_to_right = !left_to_right;
            swap(next ,current);
        }

        return result;

    }
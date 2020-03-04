/*
题目：二叉树的层次遍历；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){//可以根据队列的大小判断是否结束
                vector<int> temp_result;
            int levl_size=myQueue.size();//判断队列的大小
            for(int i=0;i<levl_size;i++){
                TreeNode* node= myQueue.front();
                temp_result.push_back(node->val);
                 myQueue.pop();
                 
                if(node->left!=NULL){
                    myQueue.push(node->left);
                }

                if(node->right!=NULL){
                    myQueue.push(node->right);
                }

            }
            result.push_back(temp_result);

        }
        return result;      


    }
};
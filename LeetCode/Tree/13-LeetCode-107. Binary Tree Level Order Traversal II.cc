/*
题目： 107. 二叉树的层次遍历 II
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> nextLevel;
        if(root!=NULL){
            nextLevel.push(root);
            visitNextLevel(nextLevel);
        }
        return res;
    }

    void visitNextLevel(queue<TreeNode*> curLevel){
        queue<TreeNode*> nextLevel;//存放下一层的节点；
        vector<int> vals;//存放当前层的元素值；
        while(!curLevel.empty()){
            TreeNode* root=curLevel.front();
            curLevel.pop();
            vals.push_back(root->val);
            if(root->left)
            {
                nextLevel.push(root->left);
            }
            if(root->right){
                nextLevel.push(root->right);
            }
        }
        if(!nextLevel.empty()){
            visitNextLevel(nextLevel);
        }
        res.push_back(vals);
    }
};

//官方答案
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        // 1. use BFS to go through the tree, and provide the level order
        // 1-1. build adjacency list? Nope, this is a tree structure already.
        // 1-2. recursive traverse the tree in BFS order
        // 2. return the output in reverse level order
        // just use std::reverse() in <algorithm>
        // but, how can I determine the right level? use two level queue?
        // 1. parent queue, 2. child queue
        
        vector<vector<int>> results;
        vector<int> level_results; 
        
        
        
        int level = 0;
        queue<TreeNode*> queue1, queue2;
        queue<TreeNode*> *parentQueue = &queue1;
        queue<TreeNode*> *bufferQueue = &queue2;
        if(root != nullptr) parentQueue->push(root);
        else return results;
        
        
        
        while( !parentQueue->empty() ){
            TreeNode* theNode = parentQueue->front(); parentQueue->pop(); 
            
            level_results.push_back(theNode->val);
            
            if( theNode->left != nullptr ) bufferQueue->push( theNode->left );
            if( theNode->right != nullptr ) bufferQueue->push( theNode->right );
            
            if(parentQueue->empty()){
                queue<TreeNode*> *temp = parentQueue;
                parentQueue = bufferQueue;
                bufferQueue = temp;
                
                results.push_back(level_results);
                level_results.resize(0);
            }
            
        }
        
        
        
        reverse( results.begin(), results.end() );
        return results;
        
        
    }
};


//效率最高的
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> currlayer;
            for(int i = 0; i < size; i++){
                TreeNode* curr =  q.front();
                q.pop();
                currlayer.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            res.push_back(currlayer);
            currlayer.clear();
        }
        reverse(res.begin(), res.end());//直接进行翻转就可以实现；
    //reverse函数实现时，其内部采用前后指针进行，两个之间进行替换，实现前后跌倒；
        return res;
    }
};
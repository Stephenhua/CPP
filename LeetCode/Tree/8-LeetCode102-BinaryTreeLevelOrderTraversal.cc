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

//采用队列的方式进行，而实现迭代的遍历的时候，需要使用栈排序；
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){//可以根据队列的大小判断是否结束。然后只保留一层的节点信息
                vector<int> temp_result;
            int levl_size=myQueue.size();//判断队列的大小
            for(int i=0;i<levl_size;i++){

                TreeNode* node= myQueue.front();
                temp_result[i]=node->val;
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

//采用两个队列进行判断；
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p && q || !q && p) return false;
        // Iterative method
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        
        while (!qp.empty() && !qq.empty()) {
            if (qq.size() != qp.size())
                return false;
            int sz = qp.size();
            while (sz--) {
                auto p_cur = qp.front();
                auto q_cur = qq.front();
                qq.pop();
                qp.pop();
                if (p_cur->val != q_cur->val)
                    return false;
                if (p_cur->left && !q_cur->left || p_cur->right && !q_cur->right ||!p_cur->left && q_cur->left ||!p_cur->right && q_cur->right)
                    return false;
                if (p_cur->left && p_cur->left) {
                    if (p_cur->left->val != p_cur->left->val)
                        return false;
                    else {
                        qp.push(p_cur->left);
                        qq.push(q_cur->left);
                    }    
                }
                if (p_cur->right && q_cur->right) {
                    if (p_cur->right->val != p_cur->right->val)
                        return false;
                    else {
                        qp.push(p_cur->right);
                        qq.push(q_cur->right);
                    }
                }
            }
        }
        
        if (!qp.empty() || !qq.empty())
            return false;
        
        return true;
    }
};
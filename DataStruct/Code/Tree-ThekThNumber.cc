/*
题目：统计二叉树每层节点的个数；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include "BinaryTreeNode.h"
using  namespace std;

//迭代法

//采用队列的方式进行，而实现迭代的遍历的时候，需要使用栈排序；
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        vector<int> result;
        if(root==nullptr){
            return result;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){//可以根据队列的大小判断是否结束。然后只保留一层的节点信息
                vector<int> temp_result;
            int levl_size=myQueue.size();//判断队列的大小
            temp_result.push_back(levl_size);
            for(int i=0;i<levl_size;i++){

                TreeNode* node= myQueue.front();
                //temp_result[i]=node->val;
                 myQueue.pop();

                if(node->left!=NULL){
                    myQueue.push(node->left);
                }

                if(node->right!=NULL){
                    myQueue.push(node->right);
                }

            }
            //result.push_back(temp_result);

        }
        return result;      


    }
};


//方法二：采用递归法

int COUNT_tree(Tnode *root, int depth, int k, int *number) {
    if (root == NULL)
        return 0;
    if (depth == k) {
        (*number)++;
    }
    COUNT(root->Lchild, depth + 1, k, number);
    COUNT(root->Rchild, depth + 1, k, number);
    return *number;
}

int KthNode( int k){
    if(k<0){
        return 0;
    }
    return kThnNodeCore(root,k);
}

int  kThnNodeCore(BinaryTreeNode* root ,int k){

    if(root==nullptr){
        return 0;
    }
    if(k==0){
        return 1;
    }else
    {
        return kThnNodeCore(root->left, k-1) +kThNodeCore(root->right,k-1);
    }
}


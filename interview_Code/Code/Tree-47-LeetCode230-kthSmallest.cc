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
题目：二叉搜索树中第k小的元素；
*/

//方法一：采用广度优先的方式进行遍历；

vector<int>res;
    int kthSmallest(TreeNode* root, int k) {
    Mild_Order(root,res);
    //sort(res.begin(),res.end(),greater<int>());
    return res[k-1];
    }
    void Mild_Order(TreeNode* root,vector<int>&res)
    {
        if(!root) return;
        Mild_Order(root->left,res);
        res.push_back(root->val);
        Mild_Order(root->right,res);
    }
//方法二：采用递归的形式进行；
int kthSmallest(TreeNode* root, int k) {

    if( (root == nullptr) ||( k==0)){
        return 0;
    }
    int value = 0;
    int res;

    kthSmallestCore( root ,k ,value,res);
    return value;
}

void kthSmallestCore( TreeNode* root ,int k,int&value ,int res){

        if(root == nullptr){
            return  ;
        }

        if(root->left != nullptr){
            kthSmallestCore(root->left ,k ,value,res);
        }
        value++;
        if( value == k){

            value = root->val;

            return;
        }



        if(root->right != nullptr){
            kthSmallestCore(root->right,k, value,res);
        }
}
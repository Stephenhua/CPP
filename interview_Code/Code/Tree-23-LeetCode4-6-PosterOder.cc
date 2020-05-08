#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
using namespace std;

/*
题目：后继者
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//方法一：采用递归的形式；
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if( root == nullptr){
            return nullptr;
        }

       if( root->val <= p->val){
           return inorderSuccessor(root->right , p);
       }else{
           TreeNode* leftNode = inorderSuccessor(root->left , p);

           if(leftNode == nullptr){
               return root ;
           }else
           {
               return leftNode;
           }
           
       }
    }

//方法二：采用vector进行存储搜索二叉树的值，然后进行遍历

void inorder(TreeNode* root ,vector<TreeNode*> &res){
    if( root->left){
        inorder(root->left ,res);
    }

    res.push_back(root);

    if(root->right){
        inorder(root->right ,res);
    }
}
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        vector<TreeNode*> res;

        inorder(root ,res);

        res.push_back(nullptr);

        for(int i = 0; i<res.size() ;i++){
            if(res[i] == p){
                return res[i+1];
            }
        }
        return nullptr;


    }

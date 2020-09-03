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
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//方法一：递归的方法进行求解；
    void inordreTraversalCore( TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        if(root->left){
            inordreTraversalCore(root->left ,result);
        }

        result.push_back(root->val);

        if(root->right){
            inordreTraversalCore(root->right ,result);
        }
        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result ;
       inordreTraversalCore(root, result);
        return result;
    }


//方法二：采用非递归的形式进行求解；
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        if(root == nullptr){
            return result  ;
        }
        stack<TreeNode*> temp;
        while( !temp.empty() || root){
            //向左遍历；
            while(root !=nullptr){
                temp.push(root);
                root = root->left;
            }
            //根元素；
            root = temp.top();
            temp.pop();

            result.push_back(root->val);
            //向右遍历；
            root = root->right;

        }

        return result;

    }
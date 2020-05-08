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
实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
    2
   / \
  1   3
输出: true
示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：采用中序遍历，进行递归
bool flag ;
long val;
void isValidBSTCore(TreeNode* root){

    if(root == nullptr || !flag){
        return ;
    }
    isValidBSTCore(root->left);

    if(root->val > val){
        val = root->val;
    }else{
        flag = false;
    }
    isValidBSTCore(root->right);
}

    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        flag =true;
        val  = LONG_MIN;
        isValidBSTCore(root);
        return flag;
    }

//方法二：采用栈的形式进行求解；

bool isVaildBST(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    stack<TreeNode*> stackNode;

    TreeNode* currNode =nullptr;

    while( !stackNode.empty() || root!=nullptr){
        //进行左子树；
        while(root!=nullptr){
            stackNode.push(root);
            root =root->left;
        }

        root = stackNode.top();
        stackNode.pop();
        if(currNode!=nullptr && currNode->val >= root->val){
            return false;
        }

        currNode = root ;

        root =root->right;
    }
    return true;
}

//方法三：采用前序的遍历形式进行；

bool isBSTCore(TreeNode* root , TreeNode* min ,TreeNode* max){

    if( root == nullptr){
        return true;
    }

    if( min!=nullptr && root->val <= min->val){
        return false;
    }
    if(max != nullptr && root->val >= max->val){
        return false;
    }

    if(!isBSTCore(root->left,min ,root )){
        return false;
    }

    if( !isBSTCore(root->right ,root,max)){
        return false;
    }

    return true;
}
bool isVaildBST(TreeNode* root){

    if( !isBSTCore( root ,nullptr ,nullptr)){
        return false;
    }

    return true;

}

//方法四：采用递归的形式

bool isVaildBST(TreeNode* root){

    return isaildBSTCore(root ,LONG_MIN, LONG_MAX);

}

bool isaildBSTCore( TreeNode* root ,long long lower ,long long upper){

    if( root == nullptr ){
        return true;
    }

    if( root->val <= lower || root->val >= upper){
        return false;
    }

    return isaildBSTCore(root->left ,lower , root->val)&&isaildBSTCore(root->right , root->val ,upper);
    
}
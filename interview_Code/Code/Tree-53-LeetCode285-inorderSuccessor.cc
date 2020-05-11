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
题目：二叉搜索树的顺序后继；
给你一个二叉搜索树和其中的某一个结点，请你找出该结点在树中顺序后继的节点。

结点 p 的后继是值比 p.val 大的结点中键值最小的结点。

 

示例 1:



输入: root = [2,1,3], p = 1
输出: 2
解析: 这里 1 的顺序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。
示例 2:



输入: root = [5,3,6,2,4,null,null,1], p = 6
输出: null
解析: 因为给出的结点没有顺序后继，所以答案就返回 null 了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/inorder-successor-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//采用递归的形式进行；
vector<TreeNode*> res;
void inordreSuccessorCore( TreeNode* root ,TreeNode* p){

    if( root == nullptr){
        return ;
    }

    inordreSuccessorCore(root->left ,p);
    res.push_back(root);
    inordreSuccessorCore(root->right ,p);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root  == nullptr){
        return nullptr;
    }

    inordreSuccessorCore(root,p);
    int i=0;
    for( ;i<res.size();i++){
        if( res[i] == p){
            break;
        }
    }

    if( i!=res.size()-1){
        return res[i+1];
    }else{
        return nullptr;
    }
}

//采用迭代的形式进行计算,一直进行分支判断；

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* res = nullptr;

    while( root){
        if( root->val > p->val){
            res =root ;
            root =root->left;//这样遍历将会从定向上找到最小的最大的值；
        }else{
            root = root->right;
        }
    }
    return res;
}
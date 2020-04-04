/*
题目：统计二叉树节点的个数；
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

int TreeSize(BinaryTreeNode* root){
    if(root==nullptr){
        return 0;
    }

    int leftNode=TreeSize(root->m_pLeft);
    int rightNode =TreeSize(root->m_pRight);
    return 1+leftNode+rightNode;
}
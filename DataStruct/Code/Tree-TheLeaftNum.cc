/*
题目：统计二叉树叶子结点的数量；
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


int TheLeafsNum(BinaryTreeNode* root){
    int nodes=0;
    if(root==nullptr){
        return 0;
    }else if(root->m_pLeft==nullptr && root->m_pRight==nullptr){
        return 1;
    }else{
        nodes=TheLeafsNum(root->m_pLeft)+TheLeafsNum(root->m_pRight);
    }

    return nodes;
}
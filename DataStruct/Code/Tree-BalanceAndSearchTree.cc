#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;


/*
如何判断一个二叉树为平衡二叉搜索树，即AVL

分别对齐进行判断就可以实现；

*/

bool isAVL(BinaryTreeNode* root){

    int Depth = 0 ;
    if(isBST(root, Depth) && isSearchTree(root)){
        return true;
    }
    return false ;
}

bool isBST(BinaryTreeNode* root, int Depth){
    if(root == nullptr ){
        return true;
    }

    int left ,right ;
    if(isBST(root->m_pLeft, &left)&& isBST(root->m_pRight, &right)){

        int diff = left -right ;

        if(diff >=-1 && diff<=1){

            Depth = 1+ (left>right? left : right);
            
            return true;

        }
    }

    return false ;
}

bool isSearchTree(BinaryTreeNode* pRoot){

    stack<BinaryTreeNode* > temp ;

    BinaryTreeNode* pre = nullptr;
    BinaryTreeNode* cur = pRoot;
    temp.push(pRoot);

    if(!temp.empty() || (cur!=nullptr)){
        
        while( cur->m_pLeft !=nullptr){
            
            temp.push(cur);
            cur =cur->m_pLeft;
        }

        cur = temp.pop();

        if(pre != nullptr && pre->m_nValue >= cur ->m_nValue){
            return false;
        }

        pre = cur;
        
        cur = cur->m_pRight;
    }

    return true;
}
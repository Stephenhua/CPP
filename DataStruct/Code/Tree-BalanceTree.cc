#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "BinaryTreeNode.h"
using namespace std;

/*
题目：判断二叉树是否为平衡二叉树

*/
//方法一：通过递归高度进行求解；

int height(BinaryTreeNode* pRoot){
    if(pRoot == nullptr){
        return ;
    }

    int left = height( pRoot->m_pLeft);
    int right = height( pRoot->m_pRight);

    return (left > right)? (left+1):( right+1);

}
bool isBalanced(BinaryTreeNode* pRoot){
    if(pRoot==nullptr){
        return true;
    }

    int left=height(pRoot->m_pLeft);

    int right = height( pRoot->m_pRight );

    int diff =left -right ;

    if( diff <-1 || diff> 1){
        return fasle;
    }
    return isBalanced(pRoot->m_pLeft)&& isBalanced(pRoot->m_pRight);

}


//方法二：采用有序遍历，然后从底向上的方式进行

bool isBalanced( BinaryTreeNode* pRoot){
    int Depth = 0 ;

    return isBalancedCore(pRoot , Depth );
}

bool isBalancedCore(BinaryTreeNode* pRoot , int Depth){

    if(pRoot==nullptr){
        Depth = 0;
        return true;
    }

    int left ,right ;

    if(isBalancedCore( pRoot->m_pLeft,&left)&& isBalancedCore(pRoot->m_nValue,& right)){
        int diff = right -left ;

        if(diff<=1 && diff >=-1){
            *Depth =1+ (left >right ？ left : right);
            return true;
        }
    }
    return false ;
    
}
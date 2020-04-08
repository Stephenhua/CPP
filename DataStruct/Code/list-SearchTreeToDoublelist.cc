#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <stack>
#include <cmath>
#include "string.h"
#include "list.h"
using namespace std;

/*
【题目描述】
对于二叉树的节点来说，有本身的值域，有指向左孩子和右孩子的两个指针；
对双向链表的节点来说，有本身的值域，有指向上一个节点和下一个节点的指针。
在结构上，两种结构有相似性，现有一棵搜索二叉树，请将其转为成一个有序的双向链表。

【要求】
如果链表的长度为 N, 时间复杂度达到 O(N)。
*/

struct BinaryteeNode{
    int m_nValue;
    BinaryteeNode* m_pLeft;
    BinaryteeNode* m_pRight;
};

BinaryteeNode* Convert( BinaryteeNode* pRoot){
    if(pRoot == nullptr){
        return pRoot;
    }

    BinaryteeNode* pLastNodeInList = ConvertNode(pRoot,& pLastNodeInList);

    //返回头节点；

    BinaryteeNode* pHeadOfList = pLastNodeInList;
    
    while(pHeadOfList !=nullptr && pHeadOfList->m_pLeft!=nullptr){
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;

}

//采用中序遍历的形式进行求解；

BinaryteeNode* ConertNode(BinaryteeNode* root ,BinaryteeNode** pLastNodeInList){

    if(pNode==nullptr){
        return ;

        BinaryteeNode* pCurrentNode = root;
        
        if(pCurrentNode->m_pLeft !=nullptr){
            ConertNode(pCurrentNode->m_pLeft, pLastNodeInList);
        }

        pCurrentNode->m_pLeft = *pLastNodeInList;
        if(*pLastNodeInList != nullptr){
            (*pLastNodeInList)->m_pRight = pCurrentNode;
        }
        *pLastNodeInList = pCurrentNode;

        if(pCurrentNode->m_pRight != nullptr){
            ConertNode( pCurrentNode->m_pRight, pLastNodeInList);
        }
    }
}
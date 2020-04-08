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
题目：复制含有随机指针节点的链表

*/

struct ComplexListNode{
    int m_nValue;
    ComplexListNode* m_pNextNode;
    ComplexListNode* m_pSobling;
};

//先复制节点
void CloneNode(ListNode* pHead){
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr){

        ComplexListNode* pCloned= new ComplexListNode();
        pCloned->m_pNextNode = pHead->m_pNext;

        pCloned->m_nValue = pNode->m_nValue;

        pCloned->m_pSobling = nullptr;

        pNode->m_pNextNode = pCloned;

        pNode = pCloned->m_pNextNode ;
    }
}
//复制参考节点

void ConnectSiblingNodes( ComplexListNode* pHead){
    ComplexListNode* CurrNode = pHead;

    while(CurrNode !=nullptr ){
        ComplexListNode* pConed= CurrNode->m_pNextNode;

        if(CurrNode->m_pSobling != nullptr){
            
          pConed->m_pSobling = CurrNode->m_pSobling ;
            
        }
        CurrNode = pConed->m_pNextNode ;
    }
}
//断开链表；

ComplexListNode* ReConnectNodes (ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;

    if(pNode != nullptr){

        pClonedHead = pClonedNode = pNode->m_pNextNode;

        pNode->m_pNextNode = pClonedNode->m_pNextNode;

        pNode = pNode->m_pNextNode;
    }

    while(pNode != nullptr){
        
        pClonedNode->m_pNextNode = pNode->m_pNextNode;

        pClonedNode = pClonedNode->m_pNextNode;

        pNode->m_pNextNode = pClonedNode->m_pNextNode;// 将下一个节点进行分开操作；

        pNode = pNode->m_pNextNode ; //移动节点指针

    }
}


ComplexListNode* Clone( ComplexListNode* pHead){

    CloneNode(pHead);

    ConnectListNodes(phead);
    
    ReConnectNodes(pHead);
}
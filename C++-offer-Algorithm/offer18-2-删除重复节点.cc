#include "Lsit.h"
#include <cstdio>


void DeleteDuplication(ListNode ** pHead){
    if(pHead == nullptr ||*pHead ==nullptr){
        return;
    }

    ListNode * preNode=nullptr;//初始化前一个节点
    ListNode *pNode=*pHead;//初始化第二个节点；
    while (pNode!=nullptr)
    {
        /* code */
        ListNode* pNext=pNode->m_pNext;
        bool NeedDeelete =false;
        if(pNext!=nullptr &&pNext->m_nValue==pNode->m_nValue){
            NeedDeelete=true;
        }

        if(!NeedDeelete){
            preNode=pNode;
            pNode=pNode->m_pNext;
        }
        else{//处理连续循环的指针
            int value =pNode->m_nValue;
            ListNode* pToBeDel=pNode;//记录当前节点与下一个节点相等时，保存其值然后进行删除
            while (pToBeDel!=nullptr&&pToBeDel->m_nValue==value)
            {
                pNext=pToBeDel->m_pNext;
                
                delete pToBeDel;
                pToBeDel=nullptr;
                pToBeDel=pNext;                
                /* code */
            }
            if(preNode==nullptr){
                *pHead=pNext;
            }
            else{
                preNode->m_pNext=pNext;
            }
            pNode=pNext;
        }
    }
    
}
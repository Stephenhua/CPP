
#include "LetCode35.h"
using namespace std;

ComplexListNode* ComplexList::CreateNode(int value){
    ComplexListNode *pNode= new ComplexListNode();
    pNode->m_nValue=value;
    pNode->m_pNext=nullptr;
    pNode->m_pSibling=nullptr;
    return pNode;

}


void ComplexList::BuildNodes(ComplexListNode * pNode ,ComplexListNode* pNext,ComplexListNode* pSibling){
    if(pNode != nullptr){
        pNode->m_pNext=pNext;
        pNode->m_pSibling=pSibling;
    }
}


void ComplexList::PrintList(ComplexListNode* pHead){
    ComplexListNode *pNode = pHead;
    while(pNode != nullptr){
        printf("The value of this node is :%d .\n",pNode->m_nValue);

        if(pNode->m_pSibling!=nullptr){
            printf("The value of its sibling is :%d\n",pNode->m_pSibling->m_nValue);
        }
        printf("\n");
        pNode=pNode->m_pNext;
    }
}
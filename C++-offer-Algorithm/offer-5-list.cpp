struct ListNode{
    int m_nValue;
    ListNode * m_pNext;
};

void RemoveNode(ListNde ** pHead, int value ){
    if(pHead == nullptr || *pHead == nullptr){
        return ;
    }  
    ListNode *pToBeDeleted = nullptr;
    
    if((*pHead)->m_nValue ==value){
        pToBeDeleted= *pHead;
        *pHead=(*pHead)->m_pNext;
    }

    else{
        ListNode * pNode = *pHead;
        while(pNode->m_nValue!=nullptr && pNode->m_pNext->m_nValue!= value){
            pNode =pNode->m_pNext;
        }

        if (pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue == value){
            pToDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
        
    }

    if(pToBeDeleted != nullptr){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
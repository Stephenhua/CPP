#include <iostream>
#include "list.h"

using namespace std;

ListNode * oddEvenList( ListNode* head){
    if(head == nullptr || head->m_pNext == nullptr){
        return head;
    }

    ListNode *odd = head;
    ListNode* even = odd->m_pNext;

    while( even && even->m_pNext){

        //进行链表替换；
        ListNode* temp = odd->m_pNext;

        odd->m_pNext = even->m_pNext;

        even->m_pNext = odd->m_pNext->m_pNext;

        odd->m_pNext->m_pNext =  temp ;

        //更新节点；
        odd = odd->m_pNext ;
        even = even->m_pNext;
    }

    return head;


}
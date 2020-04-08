#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <stack>
#include "string.h"
#include "list.h"
using namespace std;

/*
给定链表的头节点head，实现删除链表的中间节点的函数。

例如：

步删除任何节点；

1->2，删除节点1；

1->2->3，删除节点2；

1->2->3->4，删除节点2；

1->2->3->4-5，删除节点3；

【要求】
如果链表的长度为 N, 时间复杂度达到 O(N), 额外空间复杂度达到 O(1)

*/
ListNode* DeleteNode(ListNode* pHead){
    if(phead == nullptr && pHead->m_pNext == nullptr){
        return pHead;
    }

    if(pHead->m_pNext->m_pNext == nullptr){
        return pHead；
    }
    
    ListNode* fast = pHead->m_pNext->m_pNext;
    ListNode* slow = pHead;
    while(fast->m_pNext !=nullptr && fast->m_pNext->m_pNext !=nullptr){
        slow = slow->m_pNext;
        fast = fast->m_pNext->m_pNext;
    }
    //删除中间节点

    slow->m_pNext = slow->m_pNext->m_pNext;
    return pHead;
}
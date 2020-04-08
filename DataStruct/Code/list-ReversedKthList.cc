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
7、将单链表的每K个节点之间逆序

【题目描述】
给定一个单链表的头节点head, 实现一个调整单链表的函数，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。

例如：

链表:1->2->3->4->5->6->7->8->null, K = 3。

调整后：3->2->1->6->5->4->7->8->null。其中 7，8不调整，因为不够一组。

【要求】
如果链表的长度为 N, 时间复杂度达到 O(N)。

*/

ListNode* reversedKthNode( ListNode* head ,int n){
    if(head == nullpter || head->m_pNext == nullptr){
        return head;
    }

    ListNode* curr =head;

    for(int i=1;i<n && cur!=nullptr ;i++){
        curr = curr->m_pNext;
    }

    if( curr == nullptr){
        return head;
    }

    //将temp指向剩余节点；

    ListNode* temp = curr->m_pNext;

    curr->m_pNext = nullptr;

    ListNode* newHead = reversed(head);

    ListNode * newTemp = reversedKthNode( temp, n);
    return newHead;
}

//采用迭代的形式进行反转链表；
ListNode* reversed(ListNode* head){
    if(head == nullptr || head->m_pNext == nullptr){
        return head;
    }

    ListNode* newHead= reversed(head->m_pNext);

    head->m_pNext->m_pNext = head;
    
    head->m_pNext = nullptr;

    return newHead;
}
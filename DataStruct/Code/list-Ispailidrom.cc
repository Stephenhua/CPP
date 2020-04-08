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
给定一个链表的头节点 head, 请判断该链表是否为回文结构。

例如：

1->2->1，返回 true.

1->2->2->1, 返回 true。

1->2->3，返回 false。
【要求】
如果链表的长度为 N, 时间复杂度达到 O(N)。

*/

//方法一：引入辅助栈，将元素压入栈中，然后弹出挨个进行对比
//时间复杂度为：O（N)，空间复杂度为O(n)

bool IsPailidrom(ListNode* pHead){
    if(pHead==nullptr ||pHead->m_pNext==nullptr){
        return true;
    }
    ListNode* Node =pHead;
    stack<ListNode*> ListStack;

    while(Node!=nullptr){
        ListStack.push(Node);
        Node=Node->m_pNext;
    }

    while(!ListStack.empty()){
        ListNode* Node= ListStack.pop();
        if(Node->m_nValue!=pHead->m_nValue){
            return false;
        }
        pHead =pHead->m_pNext;

    }
    return true;
}


//方法二：引入辅助站，不过只是将后半部分押入到栈中；

bool IsPailidrom_2(ListNode* head){

    if(pHead==nullptr ||pHead->m_pNext==nullptr){
        return true;
    }

    ListNode* slow =head;
    ListNode* fast = head;
    stack<ListNode*> ListStack;
    while(fast->m_pNext!=nullptr && fast->m_pNext->m_pNext!=nullptr){
        slow=slow->m_pNext;
        fast=fast->m_pNext->m_pNext;
    }

    slow=slow->m_pNext;
    while(slow!=nullptr){
        ListStack.push(slow);
        slow=slow->m_pNext;
    }

    //进行判断

    while(!ListStack.empty()){
        ListNode* temp= ListStack.pop();
        if(head->m_nValue!= temp->m_nValue){
            return false;
        }
        head = head->m_pNext;
    }
    return true;

}

//方法三：空间复杂度为O（1），时间复杂度为O（n);
/*
方法：以把链表的后半部分进行反转，然后再用后半部分与前半部分进行比较就可以了。
这种做法额外空间复杂度只需要 O(1), 时间复杂度为 O(n)。
*/
ListNode* Reverse(ListNode* Node){

    if(Node== nullptr || Node->m_pNext ==nullptr ){
        return Node;
    }

    ListNode* newHead =Reverse(Node->m_pNext);
    
    Node->m_pNext->m_pNext = Node;
    Node->m_pNext = nullptr;
    return newHead;
}

bool IsPailidrom_3(ListNode* pHead){
    if(pHead == nullptr || pHead->m_pNext ==nullptr){
        return true;
    }

    ListNode* slow=pHead;
    ListNode* fast = pHead;

    //slow指向中间节点；
    while(fast->m_pNext!=nullptr && fast->m_pNext->m_pNext!=nullptr){
        fast=fast->m_pNext->m_pNext;
        slow= slow->m_pNext;
    }

    ListNode* revHead =Reverse(slow->m_pNext);

    while(revHead!=nullptr){
        if(revHead->m_nValue != pHead->m_nValue){
            return false;
        }
        revHead = revHead->m_pNext;
        pHead = pHead->m_pNext;
    }
    return true;
}
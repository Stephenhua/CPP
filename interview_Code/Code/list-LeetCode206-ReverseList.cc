#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
   
/*
翻转列表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

*/

//方法一：递归法

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* t = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return t;
    
}

//方法二：迭代法
    ListNode* reverseList(ListNode* head) {


        ListNode* start = head;
        ListNode* preNode= NULL;
        ListNode* reverseNode = NULL;

        while( start != NULL){

            ListNode* pNext = start->next;
            if( pNext == NULL){
                reverseNode = start;
            }


            start->next = preNode;
            
            preNode = start;
            start = pNext;
        }
        return reverseNode;

    }

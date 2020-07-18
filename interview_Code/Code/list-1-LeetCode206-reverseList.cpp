#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

/*
206. 反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* reverseNode = nullptr;

        while( cur != nullptr){
            //判断当前节点的下一个节点；
            ListNode* pNext = cur->next;
            //如果当前节点到了链表末尾，
            if( pNext == nullptr){
                reverseNode = cur;
            }
            //下个循环中，当前节点位pnext;
            cur->next = prev;
            //更新prev；
            prev = cur;
            cur = pNext;
        }

        return reverseNode;
    }

};
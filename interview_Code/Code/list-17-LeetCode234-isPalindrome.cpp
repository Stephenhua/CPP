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
234. 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {

    }
};

//找到中间的位置，然后向后遍历，然后进行反转；

ListNode* Reverse( ListNode* Node){
    if( Node == nullptr || Node->next == nullptr){
        return Node;
    }

    ListNode* newNode = Reverse(Node->next);
    Node->next->next = Node;
    Node->next = nullptr;
    return newNode;

}

bool IsPalidrom( ListNode* pHead){

    if( pHead == nullptr || pHead->next == nullptr){
        return true;
    }

    ListNode* slow = pHead;
    ListNode* fast = pHead;

    while( fast->next != nullptr && fast->next->next !=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* revHead = Reverse(slow->next);

    while( revHead != nullptr){
        if( revHead->val != pHead->val){
            return false;
        }

        revHead = revHead->next;
        pHead = pHead->next;
    }

    return true;

}

//方法二：
bool IsPalidrom( ListNode* pHead){

    if( pHead == nullptr || pHead->next == nullptr){
        return true;
    }

    ListNode* slow = pHead;
    ListNode* fast = pHead;

    while( fast->next != nullptr && fast->next->next !=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    //从中间进行反转；
    ListNode* last = slow->next ;
    while( last->next){

        ListNode* temp = last->next;

        last->next = temp->next;

        temp->next = slow->next;

        slow ->next = temp;
    }

    while( slow->next != nullptr){
        if( revHead->val != pHead->val){
            return false;
        }

        slow->next = revHead->next;
        pHead = pHead->next;
    }

    return true;

}
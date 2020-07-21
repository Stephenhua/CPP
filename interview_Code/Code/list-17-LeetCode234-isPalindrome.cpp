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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = NULL;
        while(slow)
        {
            //第一步：找到下一个节点；
            auto tmp = slow->next;
            //第二步：将当前节点的下一跳指针指向节点前面的节点；
            slow->next = pre;
            //第三步：将pre节点向后移动，即赋值；
            pre = slow;
            //第四步：将slow节点同时向后移动一位；
            slow = tmp;
        }
        while(head && pre)
        {
            if(pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
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

//递归解法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* start = head;
        ListNode* dummy = new ListNode( -1);
        ListNode* pre = nullptr;
        ListNode* cur = dummy->next;

        while( cur != nullptr ){
            ListNode* nextNode = cur->next;

            if(nextNode == nullptr ){
                dummy->next = cur;
            }
            cur->next = pre;
            pre =cur;
            cur = nextNode;
        }
        return dummy->next;
    }
};

//迭代法：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //意思是如果链表只有一个节点的时候反转也是它自己，直接返回即可。
        if( head == nullptr || head->next == nullptr ){
            return head;
        }
        //每次输出是节点首个节点，所以，返回的也是第一个节点；
        ListNode* node = reverseList( head->next);
        //就是将head->next的下一个指针直接指向head；
        head->next->next = head;
        //head的next值变为head;
        head->next = nullptr;
        return node ;
    }
};
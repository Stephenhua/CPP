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
        ListNode* pre = dummy;
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
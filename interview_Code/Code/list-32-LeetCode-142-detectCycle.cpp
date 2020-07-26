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
142. 环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *pHead) {
         if( pHead == nullptr || pHead->next == nullptr){
            return nullptr;
        }
        
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        


        while( fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow){
                slow = pHead;
                while( fast != slow ){
                 
                    fast = fast->next;
                    slow = slow->next;
                }
                 return fast;

            }
        }

        return nullptr;
    }
};
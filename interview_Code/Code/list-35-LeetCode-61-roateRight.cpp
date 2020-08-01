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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(nullptr){}
};

/*
61. 旋转链表
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

*/

  class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == nullptr || !head->next){
            return head;
        }

        ListNode* tail = head;

        int n = 1 ;
        while( tail->next != nullptr){
            tail = tail->next;
            n++;
        }

        int m = n %k;
        ListNode* p = head;

        if( m != 0 ){
            m = n - m- 1;//得到正序得头节点符号；
            tail->next = head;

            while ( m > 0)
            {
                p = p->next;//找到最末尾得节点进行求解；
                m--;
            }

            head = p->next;
            p->next = nullptr;
            
        }

        return head;
    }
  };

  /*
方法二：用快慢指针实现

  */
   class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      
        if( head == nullptr || !head->next){
            return head;
        }

        int len =  0 ;
        ListNode* node = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while( node ){

            node = node->next;
            len++;

        }

        k = k % len ;

        while( k ){

            fast = fast->next;
            k--;

        }

        while( fast->next ){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;

        ListNode* newHead = slow->next;

        slow->next = nullptr;

        return newHead;

    }

};
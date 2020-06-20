#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;

/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


  class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if( head == nullptr || !head->next){
            return head;
        }

        ListNode* tail = head;
        int n = 1;
        while( tail->next != nullptr){
            tail = tail->next;
            n++;
        }
        //当k的个数大于 节点的数量时候，可以节省很多不必要的循环；
        int m = k%n;
        ListNode* p =head;

        if( m != 0 ){
            m = n -m -1;//得到正序的节点标号；
            tail->next = head;
            while( m > 0 ){
                p = p->next;
                m--;
            }
            head = p->next;
            p->next = nullptr;
        }
        return head;
    }
};
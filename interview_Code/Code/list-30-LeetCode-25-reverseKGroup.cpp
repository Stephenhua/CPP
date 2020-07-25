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
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  /*
题目：
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

  */


 class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            
            if( head == nullptr){
                return nullptr;
            }

            ListNode* a = head;
            ListNode* b = head;

            for( int i = 0 ;i < k ;i++){
                if( b == nullptr){
                    return head;
                }
                b = b->next;
            }

            ListNode* newNode = reverseOperator( a,b);
            a->next = reverseKGroup( b ,k );
            return newNode;
        }

        ListNode* reverseOperator( ListNode* n ,ListNode* b){

            ListNode* pre ,*cur ,* next;
            pre = NULL;
            cur = n ;
            next = n ;

            while( cur != b){

                next = cur->next;

                cur->next = pre;
                pre  =cur ;
                cur = next;
            }
            return pre;
        }
};

//方法二：通过求解链表的长度，然后在进行下一步的求解；

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dymmy = new ListNode(0);
        ListNode* prev = dymmy;
        ListNode* cur = head;
        ListNode* nxt ;

        dymmy->next = head;

         int length = 0 ;
        while( head != nullptr){
            head = head->next;
            length++;
        }

        for( int i = 0 ; i < length / k ; i++){
            for( int j = 0 ; j < k-1 ;j++){

                nxt = cur->next;
                cur->next = nxt->next;
                nxt->next  = prev->next;
                prev->next = nxt;

            }

            prev =cur;
            cur = prev->next;
        }
        return dymmy->next;
    }
};
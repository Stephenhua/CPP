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
148. 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

/*
采用归并排序实现；先分为若干个小段，然后在进行拼接；


*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        ListNode* dummyHead(0);

        dummyHead->next = head;

        auto p = head;
        int length = 0;
        while (p)
        {
            ++length;
            p = p->next;
        }

        for( int size = 1 ; size < length ; size = 2*size){

            auto cur = dummyHead->next ;
            auto tail = dummyHead ;

            while( cur ){
                auto left = cur;
                auto right = cut ( left ,size);
                cur = cut( right,size);

                tail->next = merge( left, right);

                while( tail->next){
                    tail = tail->next;
                }
            }
        }

        return dummyHead->next;
        
    }

    ListNode* cut(ListNode* head, int n ){
        auto p = head;

        while( --n && p){
            p = p->next ;
        }
        if( p == nullptr){
            return nullptr;
        }

        auto next = p->next ;
        p->next = nullptr;
        return next;
    }

    ListNode* merge( ListNode* l1 ,ListNode* l2){
        ListNode* dummy = new ListNode(-1);

        auto p = dummy;
        while( l1 && l2){
            if( l1->val > l2->val ){
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }else{
                p->next = l1 ;
                p = l1;
                l1 = l1->next;
            }
        }

        p->next = l1?l1:l2;
        return dummy->next ;
    }
};
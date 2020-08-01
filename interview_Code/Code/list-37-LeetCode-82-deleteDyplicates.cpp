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
82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr ){
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* dummy = new ListNode( 0 );
        dummy->next = head;
        ListNode* pre = dummy;

        while( head && head->next ){
                //head与head->next节点值不相等，pre指向head，也就是指向不重复值           
            if( head->val != head->next->val ){
                pre = head;
                head = head->next;
            }else{

                //head为重复值子链表的最后一个节点，比如1->1->1->2的最后一个1
                while( head && head->next && head->val == head->next->val ){
                    head = head->next;
                }

                //pre连接重复值子链表的之后第一个节点
                pre->next = head->next ;
                head = head->next;
            }
        }
        return dummy->next ; 

    }
};

//方法二：采用快慢指针实现，
/*
判断快指针是否与next值是否相等，相等则 q = q->next ;分下面得情况讨论：
1）快慢指针相邻： 没有重复区域出现，则两者向下一位移动；
2）快慢指针不相邻： 有重复区域出现，越过重复区域；

两种特殊得情况：
1）链表头部出现重复，申请一个头前节点，斌且更新头节点；
2）链表尾部出现：判断快慢指针是否相邻，如果不相邻，则慢指针得下一位为空；

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if( head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy->next;

        while( fast->next != nullptr ){
            if( fast->val == fast->next->val ){
                fast = fast->next;
            }else{
                if( slow->next == fast ){
                    slow = fast ;
                    fast = fast->next;
                }else{
                    slow->next = fast->next;
                    fast = fast->next ;
                }
            }
        }

        if( slow->next != fast ){
            slow->next = nullptr;
        }
        return dummy->next;
    }

};
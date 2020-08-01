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
86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5


*/
/*
方法一：将链表进行拆分，然后进行合并；
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode (-1);

        if( head == nullptr  ){
            return head;
        }

        ListNode* small = before ;
        ListNode* big = after;

        ListNode* curNode = head;
        ListNode* midNode = nullptr ;

        while( curNode != nullptr ){

            if( curNode->val < x ){
                small->next = curNode;
                small = small->next ;
            }else
            {
                big->next = curNode;
                big = big->next;
            }
            curNode = curNode->next ;
            
        }

        small->next = after->next;
        big->next = nullptr; 
        return before->next;
    }
};


//方法二：根据链表拆分进行合并
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* L1 = new ListNode(0);
        ListNode* L2 = new ListNode(0);

        ListNode* hL1 = L1 , *hL2 = L2;

        while( head != nullptr ){

            if( head->val < x ){
                L1->next = head;
                L1 = L1->next;
            }else{
                L2->next = head;
                L2 = L2->next;
            }

            head = head->next ;
        }

        L1->next = hL2->next ;
        L2->next =NULL;
        return hL1->next ;
    }
};

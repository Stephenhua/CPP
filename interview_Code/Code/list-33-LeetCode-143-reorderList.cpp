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
143. 重排链表
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

*/


/*
方法一：将数据存储到线性表中，然后从线性表然后在进行求解；

*/
class Solution {
public:
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> m;
        int num = 0 ;
        while( head ){
            m[num] = head;
            num++;
            head = head->next;
        }  
        
        num--;

        if( num < 2){
            return ;
        }
        int i = 0 ;
        while( i < num ){

            m[i]->next = m[num];
            i++;
            if( i == num){
                break;
            }
            m[num]->next = m[i];
            num--;
        }
        m[i]->next = nullptr;
    }
};

/*
解法二：采用递归的形式进行求解；

*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if( !head || !head->next || !head->next->next){
            return ;
        }

        int len = 0 ;
        ListNode* p = head;
        while(p){
            len++;
            p = p->next;
        }

        Core( head,len);
    }

    ListNode* Core( ListNode* head, int len){

        if( len == 1 ){
            ListNode* outTail = head->next;
            head->next = nullptr;
            return outTail;
        }

        if( len ==2 ){
            ListNode* outTail = head->next->next;
            head->next->next = nullptr;
            return outTail;
        }
        //得到对应的尾节点，并且将头结点和尾节点之间的链表通过递归处理
        ListNode* tail = Core( head->next , len-2);

        //中间链表（已经处理好的链表，）的头结点;
        ListNode* subHead = head->next;
        head->next = tail;
        ListNode* outTail = tail->next;// 最外层 head 对应的 tail
        tail->next = subHead;
        return outTail;
    }

};

/*
方法三：首先将链表一分两个，
2）然后将后面的链表进行反转；
3） 然后进行拼接；
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if( head ==nullptr || head->next == nullptr || head->next->next == nullptr){
            return ;
        }
        //利用快慢指针寻找中间节点；
        ListNode* slow = head;
        ListNode * fast = head;

        while( fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow ->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;

        newHead = reverseList(newHead);

        while ( newHead != nullptr)
        {
            ListNode* temp = newHead->next;
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
            newHead = temp;
        }
        

    }
    ListNode* reverseList(ListNode* head){

        if( head == nullptr ){
            return nullptr;
        }
        //ListNode* dummy  = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre =nullptr;

        while( cur){

            ListNode* nextNode = cur->next;
           /* 
            if( nextNode == nullptr ){

                dummy->next = cur;

            }*/

            cur->next = pre;

            pre= cur;
            cur = nextNode;

        }

        return pre;
    }

};
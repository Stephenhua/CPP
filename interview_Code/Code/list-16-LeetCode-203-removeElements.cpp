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
203. 移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

*/
/*
思路：在头结点前面加一个节点，这样可以只通过指针的下一个节点进行判断就可以实现；

*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if( head == nullptr){
            return nullptr;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while( prev->next){

            if( prev->next->val == val){
                ListNode* tmp = prev->next;
                prev->next = prev->next->next;
                delete tmp;
            }else{
                prev = prev->next;
            }
        }

        return dummy->next;

    }
};

//方法二：按照原来的方法进行遍历；

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //判断首部的节点值是不是与val相同；
        while(( head != nullptr)&&(head->val == val)){
            head = head->next;
        }
        //判断节点的首部；
        if( head == nullptr){
            return nullptr;
        }

        ListNode* past = head;//前面的节点；
        ListNode* cur = head->next;

        while (cur !=nullptr)
        {
            if( cur->val == val){
                past->next = cur->next;
            }else{
                past = past->next;
            }
            cur = cur->next;
        }

        return head;
        
    }
};
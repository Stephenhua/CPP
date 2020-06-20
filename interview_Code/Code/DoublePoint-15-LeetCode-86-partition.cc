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
86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//方法一：建立连个链表，然后进行合并；

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* before = new ListNode(0);
        ListNode* After = new ListNode(0);

        ListNode* small = before;
        //ListNode* smallNode = After;

        ListNode* big = After ;
       // ListNode* bigNode = pNdoe;
        //ListNode* resNode = nullptr;

        if( head == nullptr){
            return head;
        }

        ListNode* curNode = head;
        ListNode* midNode = nullptr;

        while( curNode != nullptr ){

            if( curNode->val  <  x){

                small->next = curNode;
                small = small->next;

            }else if( curNode->val >= x){

                big->next  =  curNode;
                big  = big->next;

            }
            curNode = curNode->next;
        }

        small->next =  After->next;

        big->next = nullptr;

        return before->next;
        
    }
};
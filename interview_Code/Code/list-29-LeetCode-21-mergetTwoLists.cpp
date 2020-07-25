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
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

  */


/*
方法一：递归

终止条件：两条链表分别名为 l1 和 l2，当 l1 为空或 l2 为空时结束；
返回值：每一层调用都返回排序好的链表头；
本级递归内容：如果 l1 的 val 值更小，则将 l1.next 与排序好的链表头相接，l2 同理
*/
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if( l1 == nullptr){
            return l2;
        }
        if( l2 == nullptr){
            return l1;
        }

        if( l1->val < l2->val){
            l1->next = mergeTwoLists( l1->next , l2);
            return l1;
        }

        if( l2->val < l1->val){
            l2->next = mergeTwoLists( l2->next ,l1);
            return l2;
        }
    }
};

//方法二：遍历寻找节点；

 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //dummy表示哨兵节点；当最后不用的时候应该删除；
        ListNode* dummy = new ListNode(0);
        ListNode* cur =dummy;

        while( l1 != nullptr && l2 != nullptr){
            ListNode** p = (l1->val > l2->val)?&l2:&l1;
            cur->next = *p;
            cur = cur->next;
             *p = (*p)->next;//值小的那个移动即可；
        }

        cur->next = (l1 == nullptr)?l2 : l1;
        ListNode* res  = dummy->next;

        delete dummy;
        return res;
    }
 };

 //方法三：
 //方法二：遍历寻找节点；

 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //dummy表示哨兵节点；当最后不用的时候应该删除；
        ListNode* dummy = new ListNode(0);
        ListNode* cur =dummy;

        while( l1 != nullptr && l2 != nullptr){

            if( l1->val >l2->val){
                cur->next  = l2;
                l2  = l2->next;
            }else if( l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }

            cur = cur->next;
            
        }

        cur->next = (l1 == nullptr)?l2 : l1;
        ListNode* res  = dummy->next;
        
        delete dummy;
        return res;
    }
 };
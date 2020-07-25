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
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

  */

/*
方法一:采用两两合并的形式进行求解；
时间复杂度 O(kn) ，空间复杂度 O(1)
*/
 class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if( lists.size() == 0 ){
            return nullptr;
        }  
        ListNode* head = lists[0];
        for( int i = 1 ; i<lists.size() ;i++){
            if( lists[i]){
                head = mergeTwoLists( lists[i], head);
            }
        }
        return head;
    }

    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
        //dummy表示哨兵节点；当最后不用的时候应该删除；
        ListNode* dummy = new ListNode(0);
        ListNode* cur =dummy;

        while( l1 != nullptr && l2 != nullptr){

            if( l1->val >= l2->val){
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

/*
方法二：采用分治合并的方式进行求解；
时间复杂度 O(logk * n)，空间复杂度 O(1)
*/


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if( lists.size() == 0 ){
            return nullptr;
        }  

        return merge(lists,0,lists.size()-1);
    }

    ListNode* merge( vector<ListNode*> lists, int start ,int end){
        if( start == end ){
            return lists[start];
        }

        int mid = ( start + end ) / 2;
        ListNode* l1 = merge( lists,start,mid);
        ListNode* l2 = merge( lists,mid+1 ,end);

        return mergeTwoLists( l1,l2);

    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
        //dummy表示哨兵节点；当最后不用的时候应该删除；
        ListNode* dummy = new ListNode(0);
        ListNode* cur =dummy;

        while( l1 != nullptr && l2 != nullptr){

            if( l1->val >= l2->val){
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
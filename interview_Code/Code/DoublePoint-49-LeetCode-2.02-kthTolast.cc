#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
面试题 02.02. 返回倒数第 k 个节点
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。

通过次数15,295提交次数19,482
在真实的面试中遇到过这道题？


*/


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if( head == NULL || k == 0){
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0;i < k-1 ;i++){

            if( fast->next != NULL){
                fast = fast->next; 
            }else{
                return NULL;
            }
        } 

        while( fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;       
    }
};
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
147. 对链表进行插入排序
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( head == nullptr || !head->next){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev =head;
        ListNode* cur = head->next;

        while( cur){

            if( cur->val < prev->val){
                ListNode* temp = dummy;

                while( temp->next->val < cur->val){
                    temp = temp->next;
                }

                prev->next = cur->next;
                cur->next = temp->next;//新的node直接接到大于cur->val的第一个元素；
                temp->next = cur;//插入点的前一个元素 的下一个节点为 cur;
                cur = prev->next;
            }else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
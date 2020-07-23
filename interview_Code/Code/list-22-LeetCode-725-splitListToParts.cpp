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
725. 分隔链表
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：

输入: 
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
示例 2：

输入: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 

提示:

root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].
 

*/
/*
方法一：
1）首先统计链表节点的数目；
2）统计每分节点的数目；
3）根据节点的数目进行节点的切割和划分； 

总结:在链表操作中，设置一个头结点，非常有利于解题，可以使解题的过程更加简便
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //1）统计链表节点的个数；

        ListNode* p = root;
        int sum = 0 ;
        while( p!= nullptr){
            p = p->next;
            sum++;
        }

        vector<int> num(k,sum/k);

        for( int i =0 ; i< (sum%k) ;i++){
            num[i]++;
        }

        //3）节点的个数已经确定了，然后进行切分；

        vector<ListNode*> res;
        ListNode*  head = new ListNode(0);
        head->next = root;
        ListNode* pre =head;
        ListNode* current= root;

        for(int i = 0 ; i < k ;i++){
            if(num[i] !=  0){
                while( num[i]){
                    current = current->next;//用于指向下一个列表中的节点；
                    pre = pre->next;
                    num[i]--;
                }
                pre->next = nullptr;
                res.push_back(head->next);
                head->next = current;
                pre = head;
            }else{
                res.push_back(nullptr);
            }
        }
        return res;
    }
};
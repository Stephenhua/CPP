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

/*
160. 相交链表
编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 /*
思路：主要通过找一个长的链表，然后前进n-1节点，然后进行判断；

 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if( headA == nullptr || headB == nullptr){
            return nullptr;
        }


        ListNode* pA = headA;
        ListNode* pB = headB;

        while( pA != pB ){
            pA = pA==nullptr? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }

        return pA ;
    }
};

//方法二：

class Solution {
public:

int length(ListNode* node){

    int len = 0 ;

    while( node->next != nullptr){
        len++;
        node = node->next;
    }

    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr){

            return nullptr;

        }

        int countA ,countB;

        countA = length(headA);
        countB = length(headB);
        ListNode* start = nullptr;

        if( countA > countB){
            while( countA > countB){
                headA = headA->next;
            }
        }else{
            while( countB > countA){
                headB = headB->next;
            }
        }

        while( headA !=nullptr && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

};

/*
方法二：
可以将环切分为一下几部分：
1）链表头到换入口长度---a；
2）环入口到相遇点长度为---b；
3）相遇点到环入口长度；

使用快慢指针：
快指针路程：== a+(b+c)*k，k>=1,其中b+c为环的长度，k为绕环的圈数，；
慢指针路程：==a+b；

由于快指针是慢指针的2倍；
（a+b）*2 = a+(b+c)*k;

化简后得到：
a=(k-1)(b+c)+c
意思是： 链表头到环入口的距离=相遇点到环入口的距离+（k-1）圈环长度。
其中k>=1,所以k-1>=0圈。所以两个指针分别从链表头和相遇点出发，最后一定相遇于环入口。

*/


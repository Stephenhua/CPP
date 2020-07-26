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
LeetCode-142-寻找一个环状链表的入口，
方法：采用快慢指针法进行求解；

*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
/*

https://www.nowcoder.com/discuss/428158
链表部分；

方法一：
可以将环切分为一下几部分：
1）链表头到换入口长度---a；
2）环入口到相遇点长度为---b；
3）相遇点到环入口长度-----c；

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

class Solution {
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        
        if( fast == nullptr || fast->next == nullptr){
            return nullptr;
        }

        while( fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow){
                slow = pHead;
                while( fast != slow ){
                 
                    fast = fast->next;
                    slow = slow->next;
                }
                 return fast;

            }
        }

        return nullptr;
    }
};
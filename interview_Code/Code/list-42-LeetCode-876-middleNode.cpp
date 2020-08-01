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
876. 链表的中间结点
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 

示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
  */

 class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if( head == nullptr ){
            return head;
        }

        ListNode* cur = head;

        while( cur && cur->next){
            cur = cur->next->next;
            head = head->next;
        }
        return head;
    }
};

/*
方法二：数组的形式进行求解；

*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> num = {head};
        while(num.back()->next) num.push_back(num.back()->next); //将链表存入数组
        return num[num.size() / 2];
    }
};

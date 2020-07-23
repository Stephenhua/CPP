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
1171. 从链表中删去总和值为零的连续节点
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

 

你可以返回任何满足题目要求的答案。

（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

示例 1：

输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。
示例 2：

输入：head = [1,2,3,-3,4]
输出：[1,2,4]
示例 3：

输入：head = [1,2,3,-3,-2]
输出：[1]

  */


/*
解题思路：
前缀和；
1）---需要一个辅助节点res，因为头节点也有可能被删掉
2）---将前缀和用哈希表mp存储，要将辅助节点也存存进去，即mp[0] = res。因为考虑输入为[-1,1]，假如没有把把res加入mp。会返回错误的值
3）---删除区间时也要消除区间的前缀和

将前缀和作为map中的key值；

作者：jarvis1890
链接：https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solution/qian-zhui-he-by-jarvis1890/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
 class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        //保存前缀和
        unordered_map<int,ListNode*> prefixSum;

        //因为头节点可能被消掉，所以加一个虚拟节点作为头结点；
        ListNode* dummy = new ListNode(0);
        ListNode* p =dummy;

        dummy->next = head;

        prefixSum[0] = p;

        int cur = 0 ;
        int tempCur = 0 ;

        while( p = p->next){

            cur += p->val;
            if( prefixSum.find(cur) != prefixSum.end()){
                ListNode* temp = prefixSum[cur]->next;
                prefixSum[cur]->next = p->next;
                tempCur = cur;


                //从map中消除区间的节点
                while( temp != p){

                    tempCur += temp->val;
                    prefixSum.erase(tempCur);
                    temp = temp->next;
                }

            }else{
                prefixSum[cur]= p;
            }
        }
        return dummy->next;
    }
};

//方法二：采用双循环实现整个数组

 class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = nullptr;
        ListNode* cur = nullptr;

        int sum = 0 ;

        dummy->next = head;

        for( pre = dummy; pre != nullptr && pre->next != nullptr ; pre = pre->next){

            sum = 0;

            for( cur = pre->next ; cur != nullptr; cur = cur->next){
                sum += cur->val;

                //找到和为0 的序列，直接进行删除该链条；

                if( sum == 0) {
                    pre->next = cur->next;
                }
            }
        }
        return dummy->next;
    }
 };
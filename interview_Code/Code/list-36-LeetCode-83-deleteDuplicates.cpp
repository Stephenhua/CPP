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
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( head == nullptr ){
            return head;
        }

        ListNode* ptr = head;

        while ( ptr->next != nullptr )
        {
            if( ptr->val == ptr->next->val){
                ListNode* p = ptr->next;
                ptr->next = p->next;//删除操作；
                delete p ;//释放空间；
            }else
            {
                ptr = ptr->next;//移动到后面得元素；
            }
            
        }
        return head;//返回首个节点；        
    }
};


//方法二：进行递归实现；
/*
1---找终止条件：当head指向链表只剩一个元素的时候，自然是不可能重复的，因此return
2---想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
3---每一步要做什么：宏观上考虑，此时head.next已经指向一个去重的链表了，而根据第二步，我应该返回一个去重的链表的头节点。因此这一步应该做的是判断当前的head和head.next是否相等，如果相等则说明重了，返回head.next，否则返回head

作者：chenlele
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/solution/shan-chu-pai-xu-lian-biao-zhong-de-zhong-fu-yuan-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //终止条件，当前节点为空，或者下个节点为空，那么直接就跳过；
        if( head == nullptr || head->next == nullptr ){
            return head;
        }
        //获得当前节点的下一跳节点；
        auto next = head->next ;//得到下一个节点；
        //排除空闲的节点；
        while( next && next->val == head->val){
            next = next->next;
        }
        //头节点的吓一跳时不同的节点；
        head->next = deleteDuplicates(next);
        return head;
    }
};
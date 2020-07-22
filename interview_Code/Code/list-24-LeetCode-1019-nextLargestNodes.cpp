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
1019. 链表中的下一个更大节点
给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

 

示例 1：

输入：[2,1,5]
输出：[5,5,0]
示例 2：

输入：[2,7,4,3,5]
输出：[7,0,5,5,0]
示例 3：

输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]
 

提示：

对于链表中的每个节点，1 <= node.val <= 10^9
给定列表的长度在 [0, 10000] 范围内


*/

/*
方法：设置标志位，如果为1，表明有最大值，否则没有，；



*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if( head == nullptr){
            return res;
        }

        ListNode* curNode = head;
        while( curNode->next != nullptr ){
            ListNode* nextNode = curNode->next;
            int sign = 0 ;//设置标志位；
            while(nextNode != nullptr){
                int ori = 0;
                if( nextNode->val > curNode->val){
                    ori = nextNode->val;
                    res.push_back(ori);
                    sign = 1;
                    break;
                }else{
                    nextNode = nextNode->next;
                }
            }

            if( sign = 0 ){
                res.push_back(0);
            }
            curNode = curNode->next;
        }
        res.push_back(0);
        return res;
    }
};


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if( head == nullptr){
            return res;
        }

        ListNode* curNode = head;

        while(curNode){
            ListNode* next = curNode->next;

            while( next){
                
                if( next->val > curNode->val){
                    res.push_back(next->val);
                    break;
                }

                next = next->next;
            }

            if( next == nullptr){
                res.push_back(0);
            }
            curNode = curNode->next;
        }
        return res;
    }

};
/*
方法二：采用单调栈的形式进行求解，辅助数组，时间复杂度O(N)，空间复杂度O(N)；

*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //将链表放入数组中；

        vector<int> index ;
        while (head)
        {
            index.push_back( head->val);
            head = head->next;
        }

        //使用单调递增栈，遇到比栈顶大的就要出栈；

        vector<int> res(index.size());
        stack<int> stack;

        for( int i = 0 ; i <index.size() ;i++){

            while( !stack.empty() && index.at(i) > index.at(stack.top())){

                int val = stack.top();
                stack.pop();
                res.at(val) = index.at(i);
            }
            stack.push(i);
        }

        return res;
    }

};


  //方法3：单调栈，不使用辅助数组，直接修改结果数组  时间复杂度O(N) 空间复杂度O(N)
    vector<int> nextLargerNodes(ListNode* head) {

        //将链表放入结果数组
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> stack;

        //从右往左遍历
        for (int i = (int)res.size() - 1; i >= 0; --i)
        {
            int cur = res.at(i); //先暂存当前元素

            while (!stack.empty() && cur >= stack.top()) //注意: 等于号不能少 等于时也需要出栈 这里是找严格大于的数
            {
                stack.pop();  //淘汰小的 留下更大的
            }
            
            res.at(i) = (stack.empty() ? 0 : stack.top()); //栈空 右边没有更大的

            stack.push(cur);
        }

        return res;
    }
};
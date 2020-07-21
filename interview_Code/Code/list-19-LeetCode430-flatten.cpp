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
链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
430. 扁平化多级双向链表
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

 

示例 1：

输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
解释：

输入的多级列表如下图所示：



扁平化后的链表如下图：


示例 2：

输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
示例 3：

输入：head = []
输出：[]
 

如何表示测试用例中的多级链表？

以 示例 1 为例：

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
  */


 /*
方法：迭代法，遍历链表，若发现该链表存在child节点那么就将[child,tail]这段子链表插入到当前节点的后面去（注意也就是将孩子连接改为双向连接），然后继续遍历链表。

作者：xiaoneng
链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/cdie-dai-fa-dai-ma-jian-dan-luo-ji-qing-xi-by-xiao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
 class Solution {
public:
    Node* flatten(Node* head) {
        Node* p= head;
        stack<Node*> parents;//用于保存父节点；

        while( p != nullptr || !parents.empty()){
            //case1：存在孩子节点，那么直接将父节点压入栈中；
            if( p->child != nullptr){
                parents.emplace(p);
                p = p->child;
                continue;
            }
            //case2：如果当前节点已经到了队尾，那么就需要进行合并链表；
            if( p->next == nullptr && !parents.empty()){
                Node* temp = p ;
                Node* parent = parents.top();

                //将子链表的尾和父节点的下一个节点进行相连接；
                temp->next = parent->next;

                if( parent->next !=  nullptr){
                    parent->next->prev = temp;
                }

                //将父节点和子链表的头进行相连接；

                parent->next = parent->child;
                if(parent->child != nullptr){
                     parent->child->prev = parent;
                }

                //产出孩子节点指针；

                parent->child = nullptr;//产出child指针；

                p = parent->next;

                parents.pop();
                continue;
            }
            //case3：都没有上面的情况发生；

            p = p->next;//挨个进行遍历；
        }
        return head;
    }
};

//方法二：
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        stack<Node*> S;
        Node* cur;
        Node* pre = nullptr;
        S.push(head);
        while(!S.empty())
        {
            cur = S.top();
            S.pop();
            if (cur -> next)
            {
                S.push(cur -> next);
            }
            if (cur -> child) 
            {
                S.push(cur -> child);
                cur -> child = nullptr;
            }
            if (pre)
            {
                pre -> next = cur;
                cur -> prev = pre;
            }
            pre = cur;
        }
        return head;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;

/*
19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

*/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //特殊情况；
        if( head == nullptr || n == 0 ){
            return nullptr;
        }

        ListNode* dummyHead  =  new ListNode( 0 );

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;

        //前面的节点个数应该新增建一个节点，这样标号就对齐了；不需要判断当前链表的状态；
        for(int i = 0 ; i<=n ;i++){
            p = p->next;
        }

        while( p){
            p = p->next;
            q = q->next;
        }
        //删除节点；
        ListNode* delNode = q->next;
        q->next = delNode->next;

        delete delNode;


        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};

//方法二：
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //stk存储的节点的对应的链表始终存在；

        stack<ListNode* > stk;

        ListNode* temp = head;

        while( temp != nullptr){
            stk.push(temp);
            temp = temp->next;
        }

        for( int i = 0 ; i <n ;i++){
            stk.pop();//弹出删除的那个元素；
        }
        //如果为空，表明n为长度；
        if( stk.empty()){
             head = head->next;
        }else{
            //表明n在链表的中间；
            ListNode* delNode = stk.top();
            delNode->next = delNode->next->next;
        }

        return head;
    }
};
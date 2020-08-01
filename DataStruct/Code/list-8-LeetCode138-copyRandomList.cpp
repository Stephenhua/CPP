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
138. 复制带随机指针的链表
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：

输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：

输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 
提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。

*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
解题思路：
1） 先复制链表；
2）赋值随机指针；
3）进行指针分离；

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( head == nullptr ){
            return head;
        }

        //赋值链表
        Node* node = head;
        while ( node != nullptr)
        {
            Node* temp = new Node( node->val );
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }

        //赋值随机链表接地那；
        node = head;
        while( node != nullptr ){
            if( node->random != nullptr){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        //分离链表；
        node = head;

        Node* newHead = head->next;
        Node* newNode = newHead;
        while( node != nullptr ){
            node->next = node->next->next;
            if(newNode->next != nullptr ){
                newNode->next = newNode->next->next;
            }
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;        
    }
};
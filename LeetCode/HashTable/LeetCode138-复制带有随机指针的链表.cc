#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

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

//方法一：采用哈希表进行存储当前节点，这个节点的指针为空节点，当遍历整个节点之后，每一个元素都存在，所以进行next和random指针将发生新的变化

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }
        map<Node* ,Node*> map_Node;
        Node* cur =head;
        while(cur!=nullptr){
            Node * temp_Node =new Node(cur->val);
            map_Node[cur]=temp_Node;
            cur=cur->next;            
        }

        //复制next节点和random节点
        cur= head;
        while(cur!=nullptr){
            map_Node[cur]->next=map_Node[cur->next];
            map_Node[cur]->random=map_Node[cur->random];
            cur=cur->next;
        }
        return map_Node[head];
    }
};

//采用原地复制的形式进行，
/**
 * 复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C'。
 * 设置节点random值。
 * 将复制链表从原链表分离。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 这种的时间复杂度和空间复杂度是最有效的
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }
        //将复制节点添加到原节点的后面
        Node *node=head;
        while(node!=nullptr){
            Node* temp_Node=new Node(node->val);
            temp_Node->next=node->next;
            node->next=temp_Node;
            node=temp_Node->next;
        }
        // 复制random节点
        node= head;
        while(node!=nullptr){
            if(node->random!=nullptr){
                node->next->random=node->random->next;
            }
            node =node->next->next;
        }

        //分离链表
        node=head;
        Node *newHead= head->next;
        Node *newNode= newHead;
        while(node!=nullptr){
            node->next=node->next->next;
            if(newNode->next!=nullptr){
                newNode->next=newNode->next->next;
            }
            node =node->next;
            newNode=newNode->next;
        }
        return newHead;

    }
};
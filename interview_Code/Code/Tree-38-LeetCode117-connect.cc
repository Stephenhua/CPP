#include <iostream>
#include <vector>
#include <map>
//#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//方法一：和37题采用同样的方法可以实现；

Node* connect(Node* root) {
    if(root == nullptr){
        return nullptr;
    }
    queue<Node*> temp_queue;
    temp_queue.push(root);
    root->next = nullptr;

    while(!temp_queue.empty()){
        int size = temp_queue.size();
        
        for(int i =0 ;i<size ;i++){

            Node* node = temp_queue.front();

            temp_queue.pop();
            
            if( i < size-1){
                node->next = temp_queue.front();            }

            if(node->left){
                temp_queue.push(node->left);
            }

            if(node->right){
                temp_queue.push( node->right);
            }
        }
            
    }
    return root;
}

//方法二：在方法一的基础上进行修改；

Node * connect( Node* root){
    if(!root){
        return nullptr;
    }

    queue<Node*> que;
    que.push(root);

    while(!que.empty()){

        int size = que.size();

        for(int i =0 ;i < size-1;i++){
            Node* node = que.front();
            que.pop();
            node->next = que.front();
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
        }

        auto node = que.front();
        que.pop();
        node->next = nullptr;
        if(node->left) que.push( node->left);
        if(node->right) que.push(node->right);
    }
    return root;
}

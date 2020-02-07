#include <vector>
#include <iostream>
#include <stack>
using namespace std;
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
class Solution {
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


public:
    int flag = 1; 
    Node* connect(Node* root) {
        if(!root)return nullptr;
        if(flag){  // 将根节点next置为null
            root->next = nullptr;
            flag = 0;
        } 
        if(!root->left) return root;
        root->left->next = root->right;
        if(root->next)root->right->next = root->next->left;
        else root->right->next = nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }

     Node* connect(Node* root) {
        if (! root) return root;
        queue<Node*> bfs_queue;
        bfs_queue.push(root);
        bfs_queue.push(nullptr);
        Node* prev = nullptr;
        while (bfs_queue.size() != 1) {
            Node* node = bfs_queue.front();
            bfs_queue.pop();
            if (prev) prev->next = node;
            if (! node) {
                bfs_queue.push(nullptr);
                prev = nullptr;
                continue;
            }
            if (node->left) bfs_queue.push(node->left);
            if (node->right) bfs_queue.push(node->right);
            prev = node;
        }
        return root;
    }

//解法二：在此题目中，采用广度优先的方法进行遍历，当前层的有上一层决定；从而完成整个二差数的遍历；
//https://leetcode.wang/leetcode-116-Populating-Next-Right-Pointers-in-Each-Node.html

     Node* connect2(Node* root) {

         if(root==nullptr){
             return root;
         }
         Node * pre=root;
         Node * cur=nullptr;
         Node * start=pre;
         while(!pre->left){
             if(cur==nullptr){
                 pre->left->next=pre->next;

                 pre  = start->left;
                 cur  = start->right;
                 start= pre;

             }else{
                 pre->left->next=pre->right;
                 pre->right->next=cur->left;

                 pre=pre->next;
                 cur=cur->next;
             }
         }
        return root;
     }
        //解法三：依旧采用广度优先的方法进行获得每一个层的元素；通过使用两个指针进行一个定位到最左边，一个在右边进行移动；

      Node* connect3(Node* root) {

          if(root==nullptr){
              return ;
          }

          Node *pre=root;
          Node *cur=nullptr;
          while(pre->left){
              cur=pre;
              while(cur){
                  cur->left->next=cur->right;
                  if(cur->next){
                      cur->right->next=cur->next->left;

                  }

                  cur=cur->next;
              }
              pre=pre->left;
          }

      }

      Node* connect4(Node* root) {
          if(root==nullptr){
              return root;
          }

          queue<Node*> temp_queue;
          temp_queue.push(root);
          while(!temp_queue.empty()){
              Node *cur=nullptr;
              int size=temp_queue.size();
              for(int i=0;i<size;i++){
                  Node* temp=temp_queue.front();
                  temp_queue.pop();
                  if(i>0){
                      temp->next=cur;
                  }
                  cur=pre->next;
                  if(cur->left!=nullptr){
                      temp_queue.push(cur->left);
                  }
                  if(cur->right!=nullptr){
                      temp_queue.push(cur->right);
                  }
              }
          }
          return root;
      }


};






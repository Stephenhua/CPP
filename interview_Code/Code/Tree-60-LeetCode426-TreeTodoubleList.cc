#include <iostream>
#include <vector>
#include <map>
//#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：将二叉搜索树转换为排序的双向链表；
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
  Node* first = NULL;
  Node* last = NULL;

  void DFS(Node* root){
      if( root == nullptr){
          return;
      }

      DFS(root->left);
      if(last){
          last->right = root;
          root->left =last;
      }else{
          first = root;
      }
      last = root;
      DFS(root->right);

  }
  Node* treeToDoublyList(Node* root) {
      if(root == nullptr){
          return nullptr;
      }

      DFS(root);
      last->right = first;
      first->left =last;

      return first;
  }

  //方法二：采用迭代的方法进行,需要注意第一个节点与第二个节点之间的关系
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr){
            return root;
        }   
        //设立第一个节点与其相同；
        Node* pre = new Node( 0,nullptr ,nullptr);
        Node* res = pre;
        stack<Node*> s;

        while( !s.empty()|| root){
            if(root){
                s.push(root);
                root = root->left;
            }else
            {
                root = s.top();
                s.pop();
                pre->right = root;
                root->left =pre;  
                pre =root;
                root = root->right;它

            }
        }
        //将第一个节点的右指针指向它的右侧；
        pre->right = res->right;
        res->right->left = pre;
        return res->right;
    }

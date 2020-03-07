/*
题目：填充每个节点的下一个右侧节点指针二
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;

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

//方法：采用层次遍历的方法进行求解；
/*
由于是层序遍历，每层的节点都按顺序加入 queue 中，而每当从 queue 中取出一个元素时，
将其 next 指针指向 queue 中下一个节点即可，对于每层的开头元素开始遍历之前，先统计一下该层的总个数，
用个 for 循环，这样当 for 循环结束的时候，该层就已经被遍历完了，参见代码如下：
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root ==nullptr){
            return nullptr;
        }
        queue<Node*> temp;
        temp.push(root);
        root->next=nullptr;
        while(!temp.empty()){
            int level_size=temp.size();

            //temp.pop();
            for(int i=0;i<level_size;i++){
                Node * temp_node=temp.front();
                temp.pop();
                if(i<level_size-1){
                    temp_node->next=temp.front();
                }else if(i==level_size){
                    temp_node->next=nullptr;
                }

                if(temp_node->left!=nullptr){
                    temp.push(temp_node->left);
                }

                if(temp_node->right!=nullptr){
                    temp.push(temp_node->right);
                }

            }
 

        }
        return root;
    }
};
//方法二：最快的
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            Node *pre = NULL;
            count = q.size();
            for (int i = 0; i < count; i++) {
                Node *curr = q.front();
                if (pre) pre->next = curr;//进行判断；
                pre = curr;//将指针移动到后面一个节点上面；
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;        
    }
};
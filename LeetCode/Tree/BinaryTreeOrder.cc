/*
题目：前中后遍历的三种方法；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//前序遍历
class Solutions{
    public:
     void InOrder(TreeNode* root){
         if(root!=nullptr){
             cout<<"empty"<<endl;
         }

         cout<<root->val;
         InOrder(root->left);
         InOrder(root->right);
     }
     //迭代法
     void InOrder_1(TreeNode* root){
         stack<TreeNode* > result;
         if(root!=nullptr){
             cout<<"empty"<<endl;
         }

         while(root|| result.empty()){//每一个节点都要进行左右子树的遍历；
             while(root){
                 cout<<root->val;
                 result.push(root);
                 root=root->left;//左子树；
             }
             root=result.top();//如果到了底。则左右子树都为空，那么就要进行弹出栈的操作；
             result.pop();
             root=root->right;//直接到了右子树；
         }
     }

     //迭代法，将跟压入栈中，然后右子树，最后左子树；
     void InOrder_3(TreeNode* root){
         if(root==nullptr){
             return ;
         }
         stack<TreeNode* > temp_stack;
         temp_stack.push(root);
         while(!temp_stack.empty()){
             TreeNode* node=temp_stack.top();
             temp_stack.pop();
             cout<<node->val<<endl;
             if(node->right){
                 temp_stack.push(node->right);
             }
             if(node->left){
                 temp_stack.push(node->left);
             }
         }
     }
};


//中序遍历
class Solutions2{
    public:
    void midInorder(TreeNode* root){
        if(root==nullptr){
            cout<<"empty"<<endl;
        }

        stack<TreeNode*> temp;
        while(root ||temp.empty()){
            while(root){
                temp.push(root);
                root=root->left;
            }
            root=temp.top();
            cout<<root->val<<endl;//他们放的位置不同，从而导致前序遍历和中序遍历对区别；
            temp.pop();
            root=root->right;
        }
    }

    //递归法
    void midOrder(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        midOrder(root->left);
        cout<<root->val<<endl;
        midOrder(root->right);
    }
};

//后序遍历
class Solutions3{
    void posterOreder(TreeNode* root){
        if(root==nullptr){
            return ;
        }

        posterOreder(root->left);
        posterOreder(root->right);
        cout<<root->val<<endl;
    }

    //迭代法
    void PosterOrder(TreeNode* root){
        if(root==nullptr){
            cout<<"empty"<<endl;
        }

        stack<TreeNode*> temp;
        stack<int> flag;
        while(root){
            temp.push(root);
            flag.push(0);
            root=root->left;
        }

        while(!temp.empty()){
            root=temp.top();
            while(root->right && flag.top()==0){
                flag.pop();
                flag.push(1);
                root=root->right;
                temp.push(root);
                flag.push(0);
                while(root->left){
                    temp.push(root);
                    flag.push(0);
                    root=root->left;
                }
            }
            root=temp.top();
            cout<<root->val<<endl;
            temp.pop();
            flag.pop();
        }

    }
};


//二叉树的后序非递归遍历；
class Solution {
public:
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};
//方法：由于根节点需要遍历两次，所以需要进行标志位设定，以区别其是第一此经过更结点，还是第二次经过根节点；
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }

//mirrors遍历，时间复杂为O(n)，空间复杂度为O(1);
//链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian--2/


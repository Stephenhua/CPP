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

         while(root|| result.empty()){
             while(root){
                 cout<<root->val;
                 result.push(root);
                 root=root->left;
             }
             root=result.top();
             result.pop();
             root=root->right;
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
            cout<<root->val<<endl;
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

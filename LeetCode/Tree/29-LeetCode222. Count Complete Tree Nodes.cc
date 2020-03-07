/*
题目：222. 完全二叉树的节点个数
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//采用层次遍历法进行求解；时间复杂度为O(n)；
class Solution {
public:
    int countNodes(TreeNode* root) {
        int sum=0;
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){//可以根据队列的大小判断是否结束。然后只保留一层的节点信息

            int levl_size=myQueue.size();//判断队列的大小
            sum+=levl_size;
            for(int i=0;i<levl_size;i++){
                TreeNode* node= myQueue.front();
                 myQueue.pop();

                if(node->left!=NULL){
                    myQueue.push(node->left);
                }

                if(node->right!=NULL){
                    myQueue.push(node->right);
                }

            }
        }
        return sum;  

    }
};
//方法二：采用递归的方法进行求解；
class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans ;
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            ans=1;
        }
        if(root->left!=nullptr && root->right==nullptr){
            ans=1;
        }

        if(root->left==nullptr && root->right!=nullptr){
            ans=1;
        }

        if(root->left!=nullptr && root->right!=nullptr){
            ans=1;
        }

        int ls=countNodes(root->left);
        int rs=countNodes(root->right);
        return ans+ls+rs;

    }

};

//方法三：递归
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int h1=getLeftHeight(root->left);
        int h2=getLeftHeight(root->right);
        if(h1==h2){
            return pow(2,h1)+countNodes(root->right);
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int getLeftHeight(TreeNode* root){
        int h1=0;
        TreeNode *l =root;
        while(l){
            ++h1;
            l=l->right;
        }
        return h1;
    }
};

//采用全递归的方法进行计算

class Solution{
    public:
    int  countNodes(TreeNode* root){
        int leftLength= leftHeight(root);
        int rihgtLenght=rihgtHeight(root);
        if( leftLength == rihgtLenght){
            return pow(2,leftLength)-1;
        }
        return countNodes(root->left) +countNodes(root->right)+1;

    }
    int leftHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+ leftHeight(root->left);

    }
    int rihgtHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+rihgtHeight(root->right);
    }
};
#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//广度优先的 时间复杂度 O(n)， 空间复杂度log(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
     //这个和二叉树的层序遍历区别在于,只需要保存最右边的TreeNode即可;
    vector<int > temp_Node;
    if(root==nullptr){
        return temp_Node;
    };
    int level;
    queue<TreeNode*> temp_queue;
    temp_queue.push(root);
    while(!temp_queue.empty()){

        temp_Node.push_back(temp_queue.back()->val);

        for(int i=temp_queue.size();i>0;i--){
            
            TreeNode* Node = temp_queue.front();
            temp_queue.pop();
            
            if(Node->left){
            temp_queue.push(Node->left);
            }
            if(Node->right){
                temp_queue.push(Node->right);
            }

        }

    }
    return temp_Node;

    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode*>mQ;
        vector<int> ret;
        if(!root)return ret;
        mQ.push(root);
        while(!mQ.empty()){
            ret.push_back(mQ.back()->val);
            for(int i=mQ.size();i>0;i--){
                TreeNode *tn=mQ.front();
                mQ.pop();
                if(tn->left)mQ.push(tn->left);
                if(tn->right)mQ.push(tn->right);
            }
        }
        return ret;
    }
};

//采用深度优先进行计算

class Solution {
public:
    //void  dfs(TreeNode* Node, vector<int>& value , int Nodevalue);
    void dfs(TreeNode* Node, vector<int>& value , int Nodevalue){
        if(!Node){
            return ;
        }
        if(value.size()==Nodevalue){
            value.push_back(Node->val);
         }

         if(Node->right){
             dfs(Node->right, value, Nodevalue+1);
         }
         if(Node->left){
             dfs(Node->left, value ,Nodevalue+1);
         }
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> value;
        if(root==nullptr){
            return value;
        }
        dfs(root,value, 0);
        return value;
    }
    
};
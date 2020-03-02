#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <algorithm>
using namespace std;

/*
题目：二叉树中第k个数,采用中序遍历的形式进行查找
*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution{
      public:
      int n=0;
      int result;

      void dfs(TreeNode* root,int k){
            if(!root){
                  return;
            }
            dfs(root->left,k);
            n++;
            if(n==k){
                  result=root->val;
            }
            dfs(root->right,k);
      }

      int kthSmallest(TreeNode* root, int k){
            dfs(root,k);
            return result;
      }

};

//采用迭代的方式进行求解,计算速度变得更加缓慢；

class Solutions{
      public:
      TreeNode* kThNode(TreeNode* pRoot, int k){
            if(!pRoot || k<0){
                  return nullptr;
            }
            int n=0;

            TreeNode* cur=pRoot;
            TreeNode* result=nullptr;

            stack<TreeNode*> s;
            while(cur || !s.empty()){
                  while(cur){
                        s.push(cur);
                        cur=cur->left;
                  }
                  cur=s.top();
                  n++;
                  s.pop();
                  if(k==n){
                        return cur;
                  }
                  cur=cur->right;
            }
            return result;

      }
};

//迭代法

class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        stack<TreeNode*> stk;
        priority_queue<int> pq;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                auto node = stk.top();
                stk.pop();
                pq.push(node->val);
                if (pq.size() == k) break;
                root = node->right;
            }
        }
        return pq.top();
    }
};

//方法四，进行变换；
class Solutions2{
      public:
      int kThSmallest(TreeNode* root ,int k){
            stack<TreeNode* > s;
            while(true){
                  while(root){
                        s.push(root);
                        root=root->left;
                  }

                  root=s.top();
                  s.pop();
                  if(--k==0){
                        return root->val;
                  }
                  root=root->right;
            }
      }
};
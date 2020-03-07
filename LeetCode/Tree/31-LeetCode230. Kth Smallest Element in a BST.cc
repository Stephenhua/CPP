/*
题目：230. 二叉搜索树中第K小的元素
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


//进行迭代操作
class Solution{
      public:
      int kthSmallest(TreeNode* pRoot, int k){
            if(!pRoot || k<0){
                  return 0;
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
                        return cur->val;
                  }else if(n>k){
                      break;
                  }
                  cur=cur->right;
            }
            return 0;

      }
};

//进行递归调用
class Solution{
      public:
      int res;
      int n=0;
      int kthSmallest(TreeNode* pRoot, int k){
          if(pRoot==nullptr){
              return 0;
          }
          dfs(pRoot,k);
          return res;
      }
      void dfs(TreeNode* pRoot ,int k){
          if(!pRoot){
              return ;
          }
          dfs(pRoot->left,k);
          n++;
          if(n==k){
              res=pRoot->val;
          }
          dfs(pRoot->right,k);
      }

};
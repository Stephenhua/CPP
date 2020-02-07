#include <vector>
#include <iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


//================================================
//方法一：采用递归的形式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//================================================
class Solution {
public:
    bool helper(TreeNode node, int lower,int  upper) {
        if(node==nullptr){
            return true;
        }

        int val=node.val;
        if(lower!=nullptr&& val<=lower){
            return false;
        }

        if(upper!=nullptr&& val>=upper){
            return false;
        }

        if(!helper(node ,right,val,upper)){
            return false;
        }
        if(!helper (node ,left ,lower,val)){
            return false;
        }

        return true;
    }
    bool isValidBST(TreeNode* root) {
        

        if(node)
    }
};

//================================================
//方法一：采用迭代的形式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//================================================
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST1(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST1(TreeNode *root,long mn,long mx){
        if(!root){
            return true;
        }
        if(root->val<=mn||root->val>=mx){
            return false;
        }

        return isValidBST1(root->left,mn,root->val)&&isValidBST1(root->right,root->val,mx);
    }
    
};
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
//方法二：采用迭代的形式进行；
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
//================================================
//方法三：采用迭代的形式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//================================================

bool check(TreeNode* root, long lo, long hi){
        if(!root)
            return true;
        if(root->val >= lo && root->val <= hi){
            return check(root->left, lo, long(root->val)-1) &&  check(root->right, long(root->val)+1, hi);//为何此处的值与最大值和最小值进行比较
        }
        else return false;
    }
bool isValidBST(TreeNode* root) {
        bool res = true;
        long lo = INT_MIN;
        long hi = INT_MAX;
        res = check(root, lo, hi);
        return res;
    }

//================================================
//方法四：采用深度优先的方式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//===============================================


    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* cur, TreeNode* minNode, TreeNode* maxNode) {
        if (cur == NULL) {
            return true;
        }
        if ((minNode && cur->val <= minNode->val) || (maxNode && cur->val >= maxNode->val)) {
            return false;
        }
        return helper(cur->left, minNode, cur) && helper(cur->right, cur, maxNode);
    }
//================================================
//方法五：采用深度优先的方式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//===============================================


    bool isValidTree(TreeNode* node, long min, long max)
    {
        if(!node) return true;
        
        //cout<<node->val<<" "<<min<<" "<<max<<endl;
        
        if(node->val<=min || node->val>=max) return false;
        
        return isValidTree(node->left, min, node->val) && isValidTree(node->right, node->val, max);
    }
    bool isValidBST(TreeNode* root) {
        long min=LONG_MIN;
        long max=LONG_MAX;
        return isValidTree(root, min, max);
    }

//================================================
//方法六：采用深度优先的方式进行；
//时间复杂度：时间复杂度 : O(N)O(N)。每个结点访问一次。
//           空间复杂度 : O(N)O(N)。我们跟进了整棵树。
//===============================================
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode *t = s.top(); s.pop();
            if (pre && t->val <= pre->val) return false;
            pre = t;
            p = t->right;
        }
        return true;
    }
};

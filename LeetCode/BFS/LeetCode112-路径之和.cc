#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//方法一：递归

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return false;
        }

        sum-=root->val;
        if((root->left==nullptr)&&(root->right==nullptr)){
            return (sum==0);
        }
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
        
    }
};


//方法二：采用递归的形式进行计算；
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false; 
        }
        if (root->val == sum && root->left ==  NULL && root->right == NULL) {
            return true;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val); 
    }
};
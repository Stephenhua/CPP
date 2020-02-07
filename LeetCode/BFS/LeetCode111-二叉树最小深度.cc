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

 //方法一：递归运算
class Solution {
public:
    int minDepth(TreeNode* root) {
      if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return 1;
        }

        int min_Dpth=INT_MAX;
        if(root->left){
            min_Dpth=min(minDepth(root->left),min_Dpth);
        }
        if(root->right){
            min_Dpth=min(minDepth(root->right),min_Dpth);
        }

        return min_Dpth+1;
    }
};

 //方法二：深度优先迭代
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        
    }
};
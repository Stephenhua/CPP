
#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//方法一：采用递归的形式进行遍历
class Solution {
     struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
public:
     //void mds(TreeNode * root, vector<int>result);
    void mds(TreeNode * root ,vector<int>& result){
         if(root==nullptr){
             return ;
         }
         mds(root->left,result);
         result.emplace_back(root->val);
         mds(root->right,result);
     }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        mds(root,result);
        return result;
     }

};


//方法二：采用迭代的形式进行

class Solution {
     struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
public:
     //void mds(TreeNode * root, vector<int>result);
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> result;
        TreeNode* rt=root;
        while(rt|| S.size()){
            while (rt)
            {
                S.push(rt);
                rt=rt->left;
                /* code */
            }
            rt=S.top();
            S.pop();
            result.push_back(rt->val);
            rt=re->right;
            
        }
        return result;
     }

};

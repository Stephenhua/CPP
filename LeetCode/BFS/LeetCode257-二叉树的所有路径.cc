#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> re,leftPath,rightPath;
        string path;
        //进行边界检测
        if(root==nullptr){
            return re;
        }

        if(root->left ==nullptr && root->right==nullptr){
            return re;
        }

        path= to_string(root->val);

        //不是叶子节点
        if(root->left!=nullptr){
            leftPath=binaryTreePaths(root->left);
        }
        if(root->right!=nullptr){
            rightPath=binaryTreePaths(root->right);
        }

        for(auto le:leftPath){
            string temp= path+ "->"+le;
            re.push_back(tmep);
        }
        return re;

        
    }
};


class Solution {
private:
    vector<string> ret;
    string temp;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return ret;
        
        helper(root, temp);
        
        return ret;
    }
    
    void helper(TreeNode* root, string t) {
        if (!root) return;
        
        if (t.size() != 0) t += "->";
        
        t += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL)
            ret.push_back(t);
        
        helper(root->left, t);
        helper(root->right, t);
        
    }
};
/*
题目：173. 二叉搜索树迭代器
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};//后序遍历
class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root=root->left;
        }

    }
    
    /** @return the next smallest number */
    int next() {
        
        TreeNode *curr = s.top();
        
        s.pop();
        
        int res = curr->val;
        
        curr = curr->right;
        
        while(curr != nullptr)
        {
            s.push(curr);
            
            curr = curr->left;
        }
        
        return res;

    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();

    }
};
/*
题目：145. 二叉树的后序遍历
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

//二叉树的后序非递归遍历；
class Solution {
public:
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};

//使用迭代的方法进行求解：
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        recursion(root);
        return res;
    }
    
private:
    vector<int> res;
    void recursion(TreeNode* root)
    {
        if (!root)
            return;
        recursion(root->left);
        recursion(root->right);
        res.push_back(root->val);
    }
};

//答案解析：
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        } 
        vector<int> order;
        stack<TreeNode*> s;
        TreeNode* p = root;
        
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode* tn = s.top();
            if (tn->right && (order.empty() || order.back() != tn->right->val)) {
                p = tn->right;
            }
            else {
                order.push_back(tn->val);
                s.pop();
            }
        }
        return order;
    }
};
#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

//二叉搜索树迭代器；

class BSTIterator {
    private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {

        while(root){
            s.push(root);
            root = root->left;
        }

    }
    
    /** @return the next smallest number */
    int next() {

        TreeNode* cur = s.top();
        s.pop();
        int ret = cur->val;
        cur =cur->right;
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }
};
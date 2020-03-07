/*
题目：199. 二叉树的右视图
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){//可以根据队列的大小判断是否结束。然后只保留一层的节点信息

            vector<int> temp_result;
            int levl_size=myQueue.size();//判断队列的大小
            result.push_back(myQueue.back()->val);//必须放在元素没有加入到队列之前；

            for(int i=0;i<levl_size;i++){
                TreeNode* node= myQueue.front();
                temp_result[i]=node->val;
                 myQueue.pop();

                if(node->left!=NULL){
                    myQueue.push(node->left);
                }

                if(node->right!=NULL){
                    myQueue.push(node->right);
                }

            }
        }
        return result;  
    }
};
//采用递归的形式进行求解；

void getans(vector<int> &ans, TreeNode* root, int depth){
    if(root!=NULL){
        if(depth>=ans.size()){
            ans.push_back(root->val);
        }else {
            ans[depth]=root->val;
        }
        getans(ans,root->left,depth+1);
        
        getans(ans,root->right,depth+1);
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        getans(ans, root,0);
        return ans;
    }
    };
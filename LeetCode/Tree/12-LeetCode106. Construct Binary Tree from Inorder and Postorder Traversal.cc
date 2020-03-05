/*
题目： 从中序与后序遍历序列构造二叉树；
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
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder,  0, inorder.size(),0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder,  int InStart, int InEnd, int posterStart, int posterEnd) {
        if (InStart>InEnd || posterStart>posterEnd) return NULL;
        if(posterStart==posterEnd){
            return new TreeNode(postorder[posterEnd]);
        }
        
        int root_val=postorder[posterEnd];
        //int root_pos=-1;
        int i=0;
        for (; i<InEnd; i++) 
            if (root_val==inorder[i]) {

                break;
            }
        
        TreeNode* root=new TreeNode(root_val);
        root->left=buildTree(inorder,postorder,InStart,i-1,posterStart,posterStart+i-InStart-1);
        root->right=buildTree(inorder,postorder,i+1,InEnd,posterStart+i-InStart,posterEnd-1);
        
        return root;
        
    }
};



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return fun(inorder,postorder,0, inorder.size(), 0,postorder.size()-1);
    }
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,int in_start, int in_end, int post_start, int post_end)
    {
        if(post_start==post_end) return new TreeNode(postorder[post_end]);
        if(post_start > post_end) return NULL;
        int root_value=postorder[post_end];
        TreeNode* root=new TreeNode(root_value);
        int i=0;
        for(;i<in_end;++i)
        {
            if(inorder[i]==root_value)
                break;
        }
        root->left=fun(inorder,postorder,in_start, i-1, post_start, post_start+ i-in_start-1);
        root->right=fun(inorder,postorder,i+1, in_end, post_start+i-in_start, post_end-1);
        return root;
    }
//采用map数组进行遍历，利用map数组实现中序遍历和后序遍历的key值和Value值得互换；从而实现递归，
//递归时，将位置进行互换；从起点进行计算；
class Solution {
private:
    unordered_map<int, int> mp;
    TreeNode *helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if( inStart > inEnd || postStart > postEnd ) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int mid = mp[postorder[postEnd]];
        root->left = helper(inorder, inStart, mid - 1, postorder, postStart, postStart + mid - inStart - 1);
        root->right = helper(inorder, mid + 1, inEnd, postorder, postStart + mid - inStart, postEnd - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inLen = inorder.size();
        int postLen = postorder.size();
        if( inLen == 0 || postLen == 0 || inLen != postLen ) {
            return NULL;
        }
        for(int i=0; i<inLen; i++) {
            mp[inorder[i]] = i;
        }
        return helper(inorder, 0, inLen-1, postorder, 0, postLen-1);
    }
};
/*
题目： 从前序与中序遍历序列构造二叉树；
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
//采用递归的形式，目的主要是找到根节点的位置；
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos =0;
        return buildTree(preorder,pos,inorder,0,inorder.size()-1);

    }

    TreeNode * buildTree(vector<int>& preorder,int &pos ,vector<int>& inorder, int left,int right){
        if(pos>=preorder.size()){
            return 0;
        }
        int i =left;
        for(int i=left;i<=right;++i){
            if(inorder[i]==preorder[pos]){
                break;
            }
        }

        TreeNode* node =new TreeNode(preorder[pos]);
        if(left<=i-1){
            node->left=buildTree(preorder,++pos,inorder,left,i-1);//左子树
        }
        if(i+1<=right){
            node->right=buildTree(preorder,++pos,inorder,i+1,right);//右子树
        }
        return node;
    }
};
//最快答案；
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int prestart, unordered_map<int,int>& inmap, int instart, int inend) {
        
        if (prestart < 0 || instart > inend)
            return NULL;
        
        int rootVal = preorder[prestart];
        TreeNode* root = new TreeNode(rootVal);
    
        unordered_map<int,int>::iterator it = inmap.find(rootVal);
        int rootIndx = it->second;
     
        root->left = buildTreeHelper(preorder, prestart+1, inmap, instart, rootIndx-1);
        
        root->right = buildTreeHelper(preorder, prestart+(rootIndx-instart+1), inmap, rootIndx+1, inend);
        
        return root;
    }
    
         
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int is = inorder.size();
        
        unordered_map<int,int> inmap(is);
        
        for (int i=0; i<is; i++)
            inmap[inorder[i]] = i;
        
        return buildTreeHelper(preorder,0,inmap,0,is-1);
        
    }
};

//最佳答案

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int lo1, int hi1, int lo2, int hi2) {
        if (lo1>=hi1 || lo2>=hi2) return NULL;
        
        int root_val=preorder[lo1];
        int root_pos=-1;
        for (int i=lo2; i<hi2; i++) 
            if (root_val==inorder[i]) {
                root_pos=i;
                break;
            }
        
        TreeNode* root=new TreeNode(root_val);
        root->left=buildTree(preorder,inorder,lo1+1,lo1+(root_pos-lo2)+1,lo2,root_pos);
        root->right=buildTree(preorder,inorder,lo1+(root_pos-lo2)+1,hi1,root_pos+1,hi2);
        
        return root;
        
    }
};
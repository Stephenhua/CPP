/*
题目：不同的二叉搜索树 II；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//方法一：采用递归的形式进行求解
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n<1){
            return result;
        }
        return BST2ree(1,n);
    }
    vector<TreeNode*> BST2ree(int start, int end){//该函数返回的从start开始，以end结束；
        vector<TreeNode*> result;
        if(start>end){
            result.push_back(nullptr);
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> lefts=BST2ree(start,i-1);
            vector<TreeNode*> rights=BST2ree(i+1,end);
            for(auto left:lefts){
                for(auto right:rights){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    result.push_back(root);
                }
            }
        }
        return result;

    }
};

//方法二：采用同样的方式，但是这样的速度会快不少

class Solution{
    public:
    vector<TreeNode*> generateTree(int n){
        if(n==0){
            return {};
        }
        return helper (1,n);
    } 

    vector<TreeNode*> helper(int start,int end){
        if(start<end){
            return {nullptr};
        }
        if(start==end){
            return {new TreeNode(start)};
        }

        vector<TreeNode*> result;

        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=helper(start,i-1);
            vector<TreeNode*> right=helper(i+1,end);

            for(int m=0;m<left.size();++m){
                for(int n=0;n<right.size();++n){
                    TreeNode* root=new TreeNode(i);//创建新的节点；
                    root->left=left[m];
                    root->right=right[n];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
//方法三：
class Solution3 {
public:
    vector<TreeNode*> generateHalf(int start,int end,vector<vector<vector<TreeNode*>>>& memo){
        vector<TreeNode*> ret;
        if(start>end){
            return {nullptr};
        }
        if(start==end){
            TreeNode* tmp = new TreeNode(start);
            ret.push_back(tmp);
            return ret;
        }
        for(int i=start;i<=end;i++){
            if(!memo[start-1][end-1].empty())
                return memo[start-1][end-1];
            vector<TreeNode*> lTrees = generateHalf(start,i-1,memo);
            vector<TreeNode*> rTrees = generateHalf(i+1,end,memo);
            
            for(int j=0;j<lTrees.size();j++){
                for(int k=0;k<rTrees.size();k++){
                    TreeNode* tmp =new TreeNode(i);
                    tmp->left = lTrees[j];
                    tmp->right = rTrees[k];
                    ret.push_back(tmp);
                }
            }
        }
        return memo[start-1][end-1]=ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        vector<vector<vector<TreeNode*>>> memo(n,vector<vector<TreeNode*>>(n));
        if(n==0) return {};
        ret = generateHalf(1,n,memo);
        return ret;
    }
};
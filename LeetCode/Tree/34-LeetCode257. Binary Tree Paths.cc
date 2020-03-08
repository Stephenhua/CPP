/*
题目：257. 二叉树的所有路径
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//使用递归的方式进行求解；
class Solution {
public:
    vector<string>  result;
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        findTreePath(root ,s);
        return  result;     
    }

    void findTreePath(TreeNode* root, string s){
        if(root==nullptr){
            return ;
        }
        if(!root->left && !root->right){
            s+=to_string(root->val);
            result.push_back(s);
            return ;
        }else{
            s+=to_string(root->val);
            s+="->";
            findTreePath(root->left,s);
            findTreePath(root->right,s);
        }
    }
};

//方法二：使用递归的方式：
class Solution{
    public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> result;
        if(root==nullptr){
            return result;
        }
        solution(result ,root,"");
        return result;
    }
    void solution(vector<string>& result,TreeNode* root,string ans){
        ans+=to_string(root->val);
        if(root->right==nullptr && root->left ==nullptr){
            result.push_back(ans);
            return ;
        }

        if(root->right)
        {
            solution(result,root->right,ans+"->");
        }

        if(root->left){
            solution(result,root->left,ans+"->");
        }
    }
};
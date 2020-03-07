/*
题目：129 求根到叶子节点数字之和
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

//方法一：采用递归的方式进行；
class Solution {
public:

    int sumNumbers(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int sum=0;
        int Sum=0;
        Dfs(root,sum,Sum);
        return Sum;
    }   
    void Dfs(TreeNode* root ,int value,int &res){
        if(root==NULL){
            return ;
        }
        
        value=root->val+value*10;

        if(root->left==nullptr && root->right==nullptr){
            res+=value;
            return ;
        }
        Dfs(root->left,value,res);
        Dfs(root->right,value,res);
    }
};

//方法二：方法最快
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int temp=0;
        getans(ans,temp,root);
        return ans;
    }
    void getans(int &ans, int temp, TreeNode* root){

    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            ans+=temp*10+root->val;
        }else {
            getans(ans,temp*10+root->val,root->left);
            getans(ans,temp*10+root->val,root->right);
            
        }
    }
}
};

//采用先先序遍历的方式进行求解，使用vector可以得到某一个深度的值，然后进行求和即可；
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>vec;
        int sum=0;
        getres(res,vec,root,sum);
       
        return sum;
    }
    void getres(vector<vector<int>>&res,vector<int>vec,TreeNode* root,int &sum)
    {
        if(root==NULL) return ;
        vec.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(vec);
             int f=0;
            for(int i=0;i<vec.size();i++)
            {
                f=f*10+vec[i];
            }
            sum+=f;
            return ;
        }
        getres(res,vec,root->left,sum);
        getres(res,vec,root->right,sum);
    }
};
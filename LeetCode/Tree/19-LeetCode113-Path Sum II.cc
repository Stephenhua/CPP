/*
题目：112 路径和II
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
//

class Solution {
    vector<vector<int> > temp_sum;
    vector<int> temp;
    public:
     void hasPathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ret) {

         sum-=root->val;
         curr.push_back(root->val);
         if(sum==0 && root->right==nullptr&&root->left==nullptr){
            ret.push_back(curr);//对于符合条件的进行加入vector中；
            return ;
         }
         if(root->left){
             hasPathSum(root->left,sum,curr,ret);
             curr.pop_back();//回溯；
         }

         if(root->right){
             hasPathSum(root->right,sum,curr, ret);
             curr.pop_back();
         }

     }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > temp_sum;
        vector<int> temp;
        if(root==nullptr){
            return temp_sum;
        }
        hasPathSum(root,sum,temp,temp_sum);
        return temp_sum;        
    }
};
//方法二：更符合常规做法；
class Solution1{
    public:
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        rootToLeaf(root, sum, cur, res);
        return res;
    }

    void rootToLeaf(TreeNode* root,int &sum,vector<int>& cur,vector<vector<int>>& res){
        if(root==nullptr){
            return ;
        }
        sum-=root->val;
        cur.push_back(root->val);
        //当其为叶子结点时候，进行这样的操作；
        if(root->left==nullptr && root->right==nullptr && sum==0){
            res.push_back(cur);
        }else{
            rootToLeaf(root->left,sum,cur,res);
            rootToLeaf(root->right,sum,cur,res);
        }
        //该部分使用回溯，将不满足条件的值进行取消，
        sum+=root->val;
        cur.pop_back();
    }

};

//方法三：采用深度优先得算法进行计算；
class Solution2{
    public:
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        rootToLeaf(root, sum, cur, res,0);
        return res;
    }
    void rootToLeaf(TreeNode* root,int sum,vector<int>& cur,vector<vector<int>>& res,int temp){
        if(!root){
            return ;
        }

        if(!root->left && !root->right && temp+root->val==sum){
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
        }else{
            cur.push_back(root->val);
            rootToLeaf(root->left,sum,cur,res,temp+root->val);
            rootToLeaf(root->right,sum,cur,res,temp+root->val);
            cur.pop_back();
        }
    }

};
//方法四：效率更高：
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> elm;
        
        if(!root) return res;
        
        pathSum(root, sum, res, elm);
        return res;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &elm){
        if(!root) return;
        
        sum -= root->val;//先进行计算，
        elm.push_back(root->val);//将列表进行操作；
        
        if(!root->left && !root->right) {//如果到了最底端的话，则进行比较和值
            if(sum == 0) 
                res.push_back(elm);
            elm.pop_back();
            return;
        }
        //如果没有到了最低端，则进行递归操作；
        pathSum(root->left, sum, res, elm);
        pathSum(root->right, sum, res, elm);

        
        //当节点的左右子树进行递归结束之后，需要进行回溯，pop_back()的目的就是为了回溯；
        
        elm.pop_back();
    }
};
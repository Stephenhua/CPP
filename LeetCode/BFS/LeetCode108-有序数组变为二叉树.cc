#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

/*
二叉搜索树 实质相当于 二分法
每次都将nums[0 ... length-1]从中间截断，分成两半。
取中间的nums[mid]为root.val :mid = (l+r+1)/2
root.letf 根据左半边数据按上述思想生成
root.right 根据右半边数据按上述思想生成
*/
 TreeNode * initTree(vector<int>& nums,int st, int en){
        if(st>en){
            return nullptr;
        }
        else if(st==en){
            TreeNode * temp_node = new TreeNode(nums[st]);
            return temp_node; 
        }

        int mid=(st+en+1)>>1;
        TreeNode *t =new TreeNode(nums[mid]);
        t->left=initTree(nums,st,mid-1);
        t->right= initTree(nums,mid+1,en);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return initTree(nums,0,nums.size()-1);
    }

//采用深度优先的算法进行实现；
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        return dfs(nums, l, r);
    }
    
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        } 
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = dfs(nums, l, mid - 1);
        node -> right = dfs(nums, mid + 1, r);
        return node;
    }
};


//方法三：采用深度优先搜索的方式进行计算；
TreeNode * initTree(vector<int>& nums,int st, int en){
        if(st>en){
            return nullptr;
        }

        int mid=(st+en+1)>>1;
        //将上面的一行直接改为mid =(st+en)/2时，运行速度将会加快一倍；
        TreeNode *t =new TreeNode(nums[mid]);
        if(st==en){
            return t;
        }
        t->left=initTree(nums,st,mid-1);
        t->right= initTree(nums,mid+1,en);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return initTree(nums,0,nums.size()-1);
    }

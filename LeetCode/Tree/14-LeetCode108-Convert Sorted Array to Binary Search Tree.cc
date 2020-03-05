/*
题目： 108. 将有序数组转换为二叉搜索树
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

//高度平衡二叉树采用中序遍历既可以实现；用用原有的一个性质；时间复杂度为：nlong(n);
class Solution {
public:
    TreeNode* sortedArrayToBST1(vector<int>& nums,int start,int end){
        if(start==end){
            return nullptr;
        }
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST1(nums,start,mid);
        root->right=sortedArrayToBST1(nums,mid+1,end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST1(nums,0,nums.size());
        
    }
};

//方法二：与上一个不同的地方在于加了一个if语句判断；
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (low == high) return node;
        
        if (mid != low) node->left = sortedArrayToBST(nums, low, mid -1);
        if (mid != high) node->right = sortedArrayToBST(nums, mid+1, high);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};
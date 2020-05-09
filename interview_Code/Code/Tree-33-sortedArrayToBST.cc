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

/*
题目：
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//方法一：利用二分法和递归的方法进行；
void build(TreeNode* root ,int start ,int end ,vector<int>& nums){

    if( start > end){
        return;
    }
    //二分法；
    int mid = ( start + end )/2;

    TreeNode* node = new TreeNode(nums[mid]);

    if( nums[mid] < root->val){

        root->left = node;

    }else{

        root->right = node;

    }

    build( node, start,mid-1,nums);
    build( node ,mid+1, end,nums);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

    int end = nums.size()-1;

    if(end < 0){
        return nullptr;
    }

    TreeNode* root = new TreeNode(nums[end/2]);

    //进行递归；
    build( root ,0 ,(end/2)-1,nums);
    build(root ,(end/2) +1 ,end, nums);

    return root;
}
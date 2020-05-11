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
题目：最接近的二叉搜索树值 II
给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的 k 个值。

注意：

给定的目标值 target 是一个浮点数
你可以默认 k 值永远是有效的，即 k ≤ 总结点数
题目保证该二叉搜索树中只会存在一种 k 个值集合最接近目标值
示例：

输入: root = [4,2,5,1,3]，目标值 = 3.714286，且 k = 2

    4
   / \
  2   5
 / \
1   3

输出: [4,3]
拓展：
假设该二叉搜索树是平衡的，请问您是否能在小于 O(n)（n 为总结点数）的时间复杂度内解决该问题呢？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-binary-search-tree-value-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//方法一：采用优先队列进行求解,主要利用了最大堆进行求解；

priority_queue<pair<double,int>> result;

vector<int>  closestKValues( TreeNode* root ,double target , int k){

    inorderTraversal( root ,target, k);

    vector<int> res;
    while (!result.empty())
    {
        res.push_back(result.top().second);
        result.pop();
        /* code */
    }

    return res;
}

void inorderTraversal( TreeNode* root , double target ,int k){

    if( root == nullptr){
        return;
    }
    //中序遍历
    inorderTraversal(root->left ,target,k);
    //优先队列；
    double diff = abs(root->val -target);

    if( result.size() < k){
        result.push({ diff, root->val});
    }else if( diff < result.top().first){
        result.pop();
        result.push({diff, root->val});
    }

    inorderTraversal(root->right ,target ,k);

}

//方法二：采用先将数据存到vector中，然后进行二分法查找；

vector<int> closestKValues( TreeNode* root ,double target ,int k){
    vector<int> arr;
    treeToArray(root,arr);
    return findClosestK( arr, target,k);
}

void treeToArray( TreeNode* root ,vector<int>& arr){
    if(root == nullptr){
        return ;
    }

    treeToArray(root->left ,arr);
    arr.push_back(root->val);
    treeToArray(root->right ,arr);
}

vector<int> findClosestK(vector<int>& arr, double target ,int k ){
    int n =arr.size();
    int start =0 ;
    int end = n -k ;

    while(start<end){
        int mid = start + (end- start)/2;

        if( abs(target-arr[mid])>abs(target-arr[mid+k])){
            start = mid +1;
        }else{
            end = mid;
        }
    }

    return vector<int> (arr.begin() + start , arr.end()+ start+ k);
}
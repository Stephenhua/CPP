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
题目：统计同值子树
给定一个二叉树，统计该二叉树数值相同的子树个数。

同值子树是指该子树的所有节点都拥有相同的数值。

示例：

输入: root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-univalue-subtrees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

pair<bool ,int> DFS( TreeNode* root ,int p ,int&val){

    if(root == nullptr){
        return{true,p};
    }

    auto left = DFS( root->left ,root->val ,val);
    auto right = DFS( root->right, root->val ,val);

    if( left.first && right.first && left.second == root->val && right.second == root->val){
        ++val;
        return {true, root->val};
    }

    return {false ,root->val};

}
int countUnivalSubtrees(TreeNode* root) {

    if(root == nullptr){
        return 0 ;
    }

    int res = 0;
    DFS( root ,0 ,res);
    return res;

}

//方法二：采用新的方式进行求解；

bool isUnival( TreeNode* root ,int val ,int &res){
    if( root == nullptr ){
        return true;
    }

    if( !isUnival(root->left ,root->val ,res) | !isUnival(root->right,root->val ,res)){
        return false;
    }

    ++res;
    return root->val == val;

}
int countUnivalSubtrees(TreeNode* root) {
    int res = 0;
    isUnival(root ,-1 ,res);
    return res;
}
#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

/*
题目：路径总和；
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


//方法一：采用双递归的方式

//计算root为一个固定值时，其总共的和为多少；
int Core( TreeNode* root ,int sum){
    if(root == nullptr){
        return 0;
    }

    sum -=root->val;

    return (sum == 0? 1:0) +Core(root->left,sum)+Core(root->right,sum);

}
//树种的每个节点都可以当做树，从而计算出整个树种有多少个节点；

int pathSum(TreeNode* root, int sum) {

    if(root == nullptr ){
        return 0 ;
    }
    return Core(root,sum)+pathSum(root->left,sum)+pathSum(root->right ,sum);
}

//方法二：采用从底向上的方式进行求解，判断每个节点作为根节点的情况下，是否具有和为sum的值；

int pathSum(TreeNode* root, int sum) {
    return dfs( root ,sum ,new int[1000], 0);
}

int dfs(TreeNode* root ,int sum ,int * num, int index){
    if( root == nullptr){
        return 0;
    }

    num[index] = root->val;

    int tempSum = 0, n= 0;

    for(int i =index ;i>=0 ;i--){
        tempSum += num[i];
        if( tempSum == sum){
            n++;
        }
    }

    int left = dfs( root->left ,sum ,num,index+1);
    int right = dfs(root->right ,sum ,num ,index+1);
    
    return n+ left+right;
}

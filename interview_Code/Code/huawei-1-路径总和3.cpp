#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right;
    TreeNode(int x ) :val(x),left(NULL),right(NULL){ }
};

/*

437. 路径总和 III
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

*/


class Solution {
public:
 //①先序递归遍历每个节点
  int pathSum(TreeNode* root, int sum) {
      if(  root == nullptr ){
          return  0;
      }
      Core(root,sum) ;

      pathSum(root->left,sum) ;
      pathSum(root->right,sum);
      return ans;
  }  
    int ans = 0 ;

//②以每个节点作为起始节点DFS寻找满足条件的路径

  void Core( TreeNode* root , int sum ){

      if( root == nullptr ){
          return  ;
      }

        sum -= root->val;
        if( sum == 0 ){
            ans+=1;
        }

        Core( root->left ,sum );
        Core( root->right ,sum );

  }
};
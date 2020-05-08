#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
using namespace std;

/*
题目：
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-balance-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//方法一：判断平衡二叉搜索树,采用后续遍历的方法进行；
    bool isBalanced(BinaryTreeNode* root) {

        if( root == nullptr){
            return true;
        }

        int depth = 0 ;
        return isBalancedCore( root , &depth);
    }

    bool isBalancedCore( BinaryTreeNode* pRoot ,int* depth){

        if(pRoot == nullptr){
            *depth = 0;
            return true;
        }

        int right ,left ;

        if( isBalancedCore(pRoot->m_pLeft,&left)&&isBalancedCore(pRoot->m_pRight,&right)){
            int diff = left -right ;

            if( diff>=-1 && diff<=1){
                
                *depth = 1+(left >right? left:right);
                return true;
            }
        }
        return false ;
    }

//方法二：通过高度进行判断；
    bool res= true;
    
    int height ( BinaryTreeNode* root){
        if( !root){
            return 0;
        }
        int left = height(root->m_pLeft);
        int right =height( root->m_pRight);

        if(abs(left -right)>1){
            return res= false;
        }
        return max(left ,right)+1;
    }

    bool isBalanced(BinaryTreeNode* root) {

        height(root);
        return res;
    }


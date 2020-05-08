#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/*
题目：二叉树中的最大路径和；
*/


//方法一：采用递归的形式进行
/*
返回经过root的单边分支最大和， 即Math.max(root, root+left, root+right)
*/
int dfs( BinaryTreeNode* root ,int &max){
    
    //递归调用终止条件；
    if( root == nullptr){
        return 0;
    }
    //计算左边分支最大值，左边分支如果为负数还不如不选择
    int leftMax = std::max( 0 ,dfs(root->m_pLeft , max));
    
    //计算右边分支最大值，右边分支如果为负数还不如不选择
    int rightMax = std::max( 0 ,dfs(root->m_pRight , max));
    
    //left->root->right 作为路径与历史最大值做比较
    max = std::max( max, root->m_nValue+ leftMax+rightMax);
    
    // 返回经过root的单边最大分支给上游
    return root->m_nValue + std::max( leftMax , rightMax);


}

int maxPathSum(BinaryTreeNode* root) {

    if( root == nullptr ){
        return 0;
    }
    int max =INT_MIN;
    dfs(root,max);
    return max;
}

//方法二：
int maxPathSum(BinaryTreeNode* root) {

    if( root == nullptr ){
        return 0;
    }
    int max =INT_MIN;
    int res=dfs(root,max);
    return max;
}


int maxPathCore(BinaryTreeNode* root ,int & max){

    if( root == nullptr){
        return 0 ;
    }

    int left = maxPathCore( root->m_pLeft , max);
    int right = maxPathCore( root->m_pRight ,max);
    //包含根节点
    int rootValue = root->m_nValue + std::max( left , 0)+ std::max(right ,0);
   
    //经过更结点的最大分支；
    int ret = root->m_nValue +std::max( left ,right);

    max = std::max( max, std::max(rootValue, ret));
    
    //返回最大分支；
    return ret ;

}
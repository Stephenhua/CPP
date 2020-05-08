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
题目
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：递归

vector<TreeNode*> generateTreesCore(int start ,int end){
    vector<TreeNode*> ans;
//若我们要生成的二叉搜索树起始节点与结尾节点相同，显然这棵树只有一个节点，我们生成即可。
    if(start == end){
        TreeNode* newNodes = new TreeNode(start);
        ans.push_back(newNodes);
        return ans;
    }
    else if( start > end){//若起始节点大于结尾节点，则我们返回一个具有空指针的vector。
        TreeNode * newNodes = nullptr;
        ans.push_back(newNodes);
        return ans;
    }
  //遍历每个节点做根节点的情况。

    for(int i = start ;i <= end; i++){

//生成所有左子树
        vector<TreeNode*> leftTrees = generateTreesCore( start ,i-1);

 //生成所有右子树
        vector<TreeNode*> rightTrees  = generateTreesCore( i+1, end);

//将左右子树插到根节点上。
        for(int j=0; j<leftTrees.size() ; j++){

            for(int m=0; m < rightTrees.size() ; m++ ){

                TreeNode* middle = new TreeNode(i);
                middle->left = leftTrees[j];
                middle->right = rightTrees[m];
                ans.push_back(middle);
            }
        }
    }
    return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;

        if(n == 0){
            return ans;
        }

        ans = generateTreesCore( 1 ,n);
        return ans;
    }



//方法二：更容易理解；采用动态规划的思想，n的数与前面所构成的子树有关系，所以需要进行递归；
  

TreeNode* copy_tree( TreeNode* root ,int append){

    if(root == nullptr){
        return nullptr;
    }

    TreeNode* new_root = new TreeNode( root->val +append);

    new_root->left = copy_tree(root->left,append);
    new_root->right = copy_tree(root->right , append);

    return new_root;

}
vector<TreeNode*> generateTrees(int n) {
   unordered_map<int, vector<TreeNode*>> dp;

   vector<TreeNode*> dp0 ;
   if(n==0){
       return dp0;
   }

   dp0.push_back(nullptr);

   dp[0] = dp0;

   vector<TreeNode*> dp1;
   dp1.push_back(new TreeNode(1));
   dp[1] = dp1;

    //遍历每一个数，使其成为根节点；
   for(int i=2 ;i<= n ;i++){
       //用于存储新的节点；
       vector<TreeNode*> new_trees;

       for(int j= 1;j <= i ;j++){
           //构建左子树和右子树的；采用动态规划进行求解；
           vector<TreeNode*> left_trees = dp[j-1];
           vector<TreeNode*> right_trees = dp[i-j];
            
            //遍历每一个左子树的节点；
           for(int left= 0 ;left <left_trees.size() ;left++){
                //找到左子树中的每一个节点；
               TreeNode* left_tree = left_trees[left];
               //遍历每一个右子树
               for(int right =0 ;right <right_trees.size() ; right++){
                   //遍历每一个右子树节点；
                   TreeNode* right_tree = right_trees[right];
                    //构建根节点；
                   TreeNode* new_root = new TreeNode(j);
                    //复制左子节点和右子节点；
                   new_root->left = copy_tree(left_tree,0);
                   new_root->right = copy_tree(right_tree,j);
                    //将该节点放置到new_trees中；
                   new_trees.push_back(new_root);
               }


           }
       }

       dp[i] = new_trees;

   }

   return dp[n];
}

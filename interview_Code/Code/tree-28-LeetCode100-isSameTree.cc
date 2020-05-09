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
题目：相同的数
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
  if(( p==nullptr&& q!=nullptr)||(p!=nullptr && q==nullptr)){
      return false;
  }
  if(q == nullptr && p == nullptr){
      return true;
  }

  return (p->val == q->val)&&(isSameTree(p->left ,q->left))&&isSameTree(p->right ,q->right);
}


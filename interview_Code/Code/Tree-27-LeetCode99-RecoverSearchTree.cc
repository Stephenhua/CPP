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
题目:99. 恢复二叉搜索树
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：采用中序遍历存入数组，然后交换两个顺序不同的值，则进行
//方法二：采用栈的形式进行求解；

//占用内存太大；
void recoverTree(TreeNode* root) {
    if(root == nullptr){
        return ;
    }
    stack<TreeNode*> stackNode;

    TreeNode* currNode =nullptr;
    TreeNode* firstNode = nullptr ;
    TreeNode* secondNode = nullptr;

    while( !stackNode.empty() || root!=nullptr){
        //进行左子树；
        while(root!=nullptr){
            stackNode.push(root);
            root =root->left;
        }

        root = stackNode.top();
        stackNode.pop();

        if(currNode!=nullptr && currNode->val > root->val){

            //将两个逆序对进行求解；
            firstNode = root;

            if(secondNode ==nullptr){
                secondNode = currNode;
            }else{
                break;
            }
        }

        currNode = root ;

        root =root->right;
    }
   
   int temp = firstNode->val ;
   firstNode->val = secondNode->val;
   secondNode->val = temp;

}
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/*
1367. 二叉树中的列表
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。

如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。

一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。

 

示例 1：



输入：head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
解释：树中蓝色的节点构成了与链表对应的子路径。
示例 2：



输入：head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
示例 3：

输入：head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：false
解释：二叉树中不存在一一对应链表的路径。
 

提示：

二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
链表包含的节点数目在 1 到 100 之间。
二叉树包含的节点数目在 1 到 2500 之间。

*/

/*
解题思路：
1）采用递归的形式进行求解；
2）同时找出位置；


*/

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if( head == nullptr){
            return true;
        }
        if( root == nullptr){
            return false;
        }
        //判断当前节点，如果不对 ，那么直接看左子树和右子树；
        return isSubPath(head,root->left)|| isSubPath(head , root->right) || isSub(head,root);
    }

    bool isSub( ListNode* head ,TreeNode* node){
        //链表走完了返回true；
        if(head == nullptr){
            return true;
        }

        //树节点走完了，返回false;
        if( node == nullptr){
            return false;
        }

        if( head->val != node->val){
            return false;
        }
       //如果值相同，继续看，左边和右边有一个满足即可        
        return isSub(head->next ,node->left) || isSub( head->next ,node->right);
    }

};
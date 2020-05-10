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
题目：完全二叉树的节点个数
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//采用广度优先遍历的方法进行求解；

int countNodes(TreeNode* root) {

    int res = 0;
    if(root == nullptr){
        return 0;
    }

    queue<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()){

        int size =nodes.size();
        res += size;

        for(int i =0 ;i <size; i++){
            
            TreeNode* node = nodes.front();
            nodes.pop();

            if(node->left){
                nodes.push(node->left);
            }

            if(node->right){
                nodes.push(node->right);
            }
        }
    }

    return res;
}

//方法二：递归的形式进行；

int countNodes(TreeNode* root) {
    if(root == nullptr){
        return 0 ;
    }

    return 1+ countNodes(root->left)+ countNodes(root->right);

}

//方法三：占用最小内存；

int countNodes(TreeNode* root){
    if(root == nullptr){
        return 0 ;
    }

    int count = countNodes(root->left);

    count = count + countNodes(root->right);
    return count+1;
}
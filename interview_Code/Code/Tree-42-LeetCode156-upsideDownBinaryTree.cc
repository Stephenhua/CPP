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
题目： 上下翻转二叉树
给定一个二叉树，其中所有的右节点要么是具有兄弟节点（拥有相同父节点的左节点）的叶节点，要么为空，将此二叉树上下翻转并将它变成一棵树， 原来的右节点将转换成左叶节点。返回新的根。

例子:

输入: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

输出: 返回二叉树的根 [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
说明:

对 [4,5,2,#,#,3,1] 感到困惑? 下面详细介绍请查看 二叉树是如何被序列化的。

二叉树的序列化遵循层次遍历规则，当没有节点存在时，'#' 表示路径终止符。

这里有一个例子:

   1
  / \
 2   3
    /
   4
    \
     5
上面的二叉树则被序列化为 [1,2,3,#,#,4,#,#,5].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-upside-down
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：
/*
根据题目描述，树中任何节点的右子节点若存在一定有左子节点，因此思路是向左遍历树进行转化；
规律是：左子节点变父节点；父节点变右子节点；右子节点变父节点。
    对于某节点root，修改root.left，root.right之前，需要将三者都存下来：
    root.left是下一轮递归的主节点；
    root是下一轮递归root的root.right；
    root.right是下一轮递归root的root.left。

作者：jyd
链接：https://leetcode-cn.com/problems/binary-tree-upside-down/solution/binary-tree-upside-down-top-downdie-dai-fa-by-jin4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
TreeNode* upsideDownBinaryTree(TreeNode* root) {

    if(root == nullptr || root->left == nullptr){
        return root;
    }
    auto left = root->left;
    auto right = root->right;

    root->left =nullptr ;
    root->right = nullptr;
    
    auto res =upsideDownBinaryTree(left);
    //root.right是下一轮递归root的root.left。
    left->left = right;
    //root是下一轮递归root的root.right；
    left->right = root;
    return res;

}
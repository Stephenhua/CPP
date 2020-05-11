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
题目：打家劫舍
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法1：采用递归的形式进行求解；

    pair<int, int> dfs(TreeNode* root)
    {
        if (nullptr == root)
        {
            return make_pair(0, 0);
        }

        pair<int, int> res(0, 0);
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        // 没抢，那么只有左子树和右子树的最大值相加；
        res.first = max(left.first, left.second) + max(right.first, right.second);
        // 抢了，需要将当前root的值进行相加；
        res.second = left.first + right.first + root->val;

        return res;
    }

    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        // 根节点在抢和不抢状态的值；
        return max(res.first, res.second);
    }
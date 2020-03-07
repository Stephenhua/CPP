/*
题目：236. 二叉树的最近公共祖先
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
/*递归思路:
当我们用递归去做这个题时不要被题目误导，应该要明确一点
这个函数的功能有三个：给定两个节点 pp 和 qq

1)如果 pp 和 qq 都存在，则返回它们的公共祖先；
2)如果只存在一个，则返回存在的一个；
3)如果 pp 和 qq 都不存在，则返回NULL
本题说给定的两个节点都存在，那自然还是能用上面的函数来解决

具体思路：
（1） 如果当前结点 root等于NULL，则直接返回NULL
（2） 如果 root 等于 pp 或者 qq ，那这棵树一定返回 pp 或者 qq
（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 left 和 right 表示
（4） 此时若left为空，那最终结果只要看 right;若 right 为空，那最终结果只要看 left
（5） 如果 left 和 right 都非空，因为只给了 pp 和 qq 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先
（6） 如果 left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）

时间复杂度是O(n)O(n)：每个结点最多遍历一次或用主定理，空间复杂度是O(n)O(n)：需要系统栈空间
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr;
        }
        if(root==p || q==root){
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left==NULL){
            return right;
        }

        if(right==nullptr){
            return left;
        }
        if(left&&right){//q或p存在值；
            return root;
        }
        return nullptr;//返回值

        
    }
};
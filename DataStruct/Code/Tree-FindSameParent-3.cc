#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "BinaryTreeNode.h"
using namespace std;

/*
该二叉树为一般二叉树，有二叉树节点中没有指向父节点的指针
*/

/*
方法一：
1) 找到从根到node1的路径，并存储在一个向量或数组中。
2)找到从根到node2的路径，并存储在一个向量或数组中。
3) 遍历这两条路径，直到遇到一个不同的节点，则前面的那个即为最低公共祖先.

*/

/*
方法二:
从根节点开始遍历，如果node1和node2中的任一个和root匹配，
那么root就是最低公共祖先。 如果都不匹配，则分别递归左、右子树，
如果有一个 节点出现在左子树，并且另一个节点出现在右子树，则root就是最低公共祖先.  
如果两个节点都出现在左子树，则说明最低公共祖先在左子树中，否则在右子树。

边界条件：

1）root 为空；
2）node1 和node2 ，其中一个为另一个的更结点，那额直接返回就可以了；
递归的四种情况：归，即
1）左子树和右子树均找没有p结点或者q结点；
（这里特别需要注意，虽然题目上说了p结点和q结点必定都存在，
但是递归的时候必须把所有情况都考虑进去，因为题目给的条件是针对于整棵树，
而递归会到局部，不一定都满足整体条件）
2） 左子树上能找到，但是右子树上找不到，此时就应当直接返回左子树的查找结果；

3）右子树上能找到，但是左子树上找不到，此时就应当直接返回右子树的查找结果；

4）左右子树上均能找到，说明此时的p结点和q结点分居root结点两侧，此时就应当直接返回root结点了。
*/

BinaryTreeNode* lowestCommonAncstor( BinaryTreeNode* root ,BinaryTreeNode* n1 , BinaryTreeNode* n2){
    if(root ==nullptr || root==n1 || root==n2){
        return root;
    }

    BinaryTreeNode* left=lowestCommonAncstor(root->m_pLeft,n1,n2);
    BinaryTreeNode* right= lowestCommonAncstor( root->m_pRight,n1,n2);

    //case1：都没找到
    if(!left && !right){
        return nullptr;
    }else if(left && !right){//case2：左子树找到，直接返回左子树；
        return left;
    }else if(!lfet && right){//case3：右子树找到，直接返回右子树；
        return right;
    }
    //case4：一个在左，一个在右，那么直接返回root；
    return root;
}
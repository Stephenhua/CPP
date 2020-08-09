/*
题目：统计二叉树满节点的个数；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include "BinaryTreeNode.h"
using  namespace std;

/*
解题思路：
1)当树为空时，满节点个数为0

2)当树中只有一个节点时，满节点个数为0

3)当某节点只有左子树时，需要进一步判断左子树中是否存在满节点

4)当某节点只有右子树时，需要进一步判断右子树中是否存在满节点

5)当某节点即有左子树，又有右子树时，说明它是满结点。但是由于它的左子树或者右子树中可能还存在满结点，
因此满结点个数等于该节点加上该节点的左子树中满结点的个数 再加上 右子树中满结点的个数。


*/
int numberOfFull(BinaryTreeNode* root){
    int nums=0;
    
    if(root == nullptr){
        return 0;
    }else if(root->m_pLeft ==nullptr && root->m_pRight==nullptr){
        return 0;
    }else if(root->m_pLeft!=nullptr && root->m_pRight == nullptr){
        nums=numberOfFull(root->m_pLeft);
    }else if(root->m_pRight != nullptr && root->m_pLeft == nullptr){
        nums = numberOfFull(root->m_pRight);
    }else{
        nums=1+numberOfFull(root->m_pLeft)+numberOfFull(root->m_pRight);
    }
    return nums;

}
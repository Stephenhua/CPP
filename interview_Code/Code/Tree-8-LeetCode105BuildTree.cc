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
题目：更具前序和中序重建二叉树
*/

unordered_map<int,int>in;

TreeNode* dfs(vector<int> &preorder ,vector<int>& inorder, int pl ,int pr ,int il ,int ir){

    if(pl >pr){
        return nullptr;
    }
    //找到前序的第一个元素即为根节点；
    int val = preorder[pl];

    //找到中序中对应的元素；以及中序前面的节点的长度；
    int k = in[val],len = k - il ;

    //数的根节点；
    auto root = new TreeNode( val);
    
    //根节点的左子树和右子树；
    root->left = dfs(preorder ,inorder ,pl+1, pl+len, il,k-1);
    root->right = dfs(preorder ,inorder ,pl+len+1, pr,k+1, ir);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();

    //遍历中序的元素，将中序中的元素和序列号进行相关联；
    for(int i=0;i<n;i++){
        in[inorder[i]]=i;
    }
    return dfs(preorder,inorder,0,n-1,0,n-1);
}
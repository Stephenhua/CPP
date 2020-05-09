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
题目：已知后序和中序遍历，建立二叉树
*/

unordered_map<int,int> in ;

TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il ,int ir,int pl ,int pr){

    if(pl >pr){
        return nullptr;
    }
    
    int val = postorder[pr];
    int k = in[val], len =ir-k;

    auto root= new TreeNode(val);

    root->left = dfs(inorder, postorder,il,k-1,pl,pr-len-1);
    root->right = dfs(inorder ,postorder,k+1,ir, pr-len,pr-1);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();

    for(int i= 0;i <size;i++){
        in[inorder[i]] = i;
    }
    int il= 0, ir= inorder.size()-1;
    int pl = 0 ,pr =postorder.size()-1;

    return dfs(inorder,postorder, il,ir,pl,pr);
}
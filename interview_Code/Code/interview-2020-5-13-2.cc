#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//计算最小深度
int getLowestDepth(TreeNode* root ){
    int left =0;
    int right = 0;
    
    if( root == nullptr){
        return 0;
    }
    
    left = getLowestDepth(root->left);
    right = getLowestDepth(root->right);

    return left>right ?right+1 :left+1;
}

int sumOfShallowestLeaves(TreeNode * root)
{
    int res = 0;
    if(root == nullptr){
        return 0;
    }
    int lowestDpeth = getLowestDepth(root);

    queue<TreeNode*> stack_node;
    stack_node.push(root);
    int curDepth = 0 ;

    while( !stack_node.empty()){

        curDepth++;

        int size = stack_node.size();
        //当遍历到最小深度时，进行求和比较；
        if(curDepth == lowestDpeth){

            for(int i= 0 ;i<size;i++){

                TreeNode* cur = stack_node.front();
                stack_node.pop();
                if(cur->right == nullptr && cur->left==nullptr){

                    res += cur->val;
                }


            }
            return res;
        }
        for(int i = 0; i<size ;i++){

                TreeNode* cur = stack_node.front();
                stack_node.pop();


                if( cur->left != nullptr){
                    stack_node.push(cur->left);
                }

                if(cur->right !=nullptr){
                    stack_node.push(cur->right);
                }
        }
        
    }
    return res;
}

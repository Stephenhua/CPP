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
题目：270. 最接近的二叉搜索树值
给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。

注意：

给定的目标值 target 是一个浮点数
题目保证在该二叉搜索树中只会存在一个最接近目标值的数
示例：

输入: root = [4,2,5,1,3]，目标值 target = 3.714286

    4
   / \
  2   5
 / \
1   3

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-binary-search-tree-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//方法一：递归的形式

int closestValue(TreeNode* root, double target) {

    if( root->left == nullptr && root->right == nullptr){
        return root->val;
    }

    if( root->val >target && root->left ){
        
        return (abs(root->val -target) < abs( closestValue(root->left,target)-target) ? root->val : closestValue(root->left,target));

    }else if( root->val < target && root->right ){

        return (abs(root->val- target) < abs(closestValue(root->right ,target) -target) ? root->val: closestValue(root->right,target) );
    }else{
        return root->val;
    }
}

int closetValue( TreeNode* root ,double target){

    if( root->left == nullptr && root->right == nullptr){
        return root->val;
    }

    if(root->val == target){
        return root->val;
    }
    if(root->val >target){
        if( root->left != nullptr){
        int temp =closestValue(root->left ,target);
            if( abs(temp-target) < abs(root->val -target)){
                return temp;
            }else{
                return root->val;
            }
        }

    }else{

        if( root->right != nullptr){

            int temp = closestValue(root->right ,target);

            if( abs(temp -target) < abs(root->val - target)){
                return temp;
            }else{
                return root->val;
            }

        }
    }

}

//方法三：采用前序遍历的方式进行
int res;
double dist = LONG_MAX;
unordered_map<double ,int> result;

void closetValueCore( TreeNode* root ,double target){

    if(root== nullptr){
        return;
    }

    double cur_dist = abs( root->val -target);
    if( cur_dist < dist){
        dist = cur_dist;
        res = root->val;
    }

    if( root->val >target){
        closetValueCore(root->left ,target);
    }else{
        closetValueCore(root->right ,target);
    }
}
int closestValue( TreeNode* root ,double target){
    closetValueCore( root,target);

    return res;
}
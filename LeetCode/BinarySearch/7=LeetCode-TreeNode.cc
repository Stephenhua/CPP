#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：计算完全二叉树的节点个数


*/

//方法一：采用递归的方法一个一个的计算节点；

class Solution {
public:
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
    int countNodes(TreeNode* root) {
        return root!=nullptr ?1+countNodes(root->right)+countNodes(root->left):0;

    }
};

//方法二：采用二分法的形式进行计算；
/*
分为两种情况进行讨论：
1）如果二叉树的最大深度和右子树的最大深度是相同的话，那么根节点的左子树一定是一颗满二叉树
利用公式既可以求出根基诶单的左子树的节点加上根节点的节点数量；
2）如果二叉树的最大深度和右子树的深度不同的话，则右子树一定是深度为二叉数深度-2的满二叉树；

*/
class Solution {
public:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    int height(TreeNode* root){
        if(root==nullptr){
            return -1;
        }

        while(root!=nullptr){
            return height(root->left)+1;
        }
    }
    int countNodes(TreeNode* root) {
        int h=height(root);
        int nums=0;
        while(root!=nullptr){
            if(h-1 ==height(root->right)){
                nums+=1<<h;//表示pos(2,h-1),第i层；
                root=root->right;
            }else{
                nums+=1<<h-1;
                root=root->left;
            }

            h--;
        }
        return nums;


        
    }
};

class Solution {

   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
public:
    int countNodes(TreeNode* root) {
    int h = height(root);
    if (h == -1) return 0;
    return height(root->right) == h - 1 ? (1 << h) + countNodes(root->right) : (1 << (h - 1)) + countNodes(root->left);
}
int height(TreeNode* root) {
    return (root == nullptr) ? -1 : 1 + height(root->left);
}

};
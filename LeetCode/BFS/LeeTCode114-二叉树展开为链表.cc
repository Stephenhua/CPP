#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


public:
    void flatten(TreeNode* root) {

        while(root !=nullptr){
            //如果左子树为null，直接考虑下一个节点；
            if(root->left==nullptr){
                root=root->right;
            }
            else{
                TreeNode *preNode=root->left;
                while(preNode->right!=nullptr){
                    preNode =preNode->right;//找到右子树最下册的节点；
                }
                //将左子树插入到右子树的地方；
                preNode->right=root->right;
                //将当前节点的左子树变为右子树；
                root->right=root->left;
                //将当前左子树的节点设置为空指针；
                root->left=nullptr;
                //考虑下一个节点；
                root=root->right;
            }
        }
    }
    //解法二：递归
    //空间复杂度O（1）；
    // 通过后序遍历的方法可以有效减少右指针的丢失；
     void flatten(TreeNode* root) {

         stack<TreeNode *> toVisit;
            TreeNode *cur=root;
            TreeNode *pre=nullptr;
        
        while(cur!=nullptr||!toVisit.empty()){
            while(cur!=nullptr){
                toVisit.push(cur);// 添加根节点
                cur=cur->right;// 递归添加右节点
            }

            cur =toVisit.top(); // 已经访问到最右的节点了
           // 在不存在左节点或者右节点已经访问过的情况下，访问根节点
            if(cur->left==nullptr ||cur->right==pre){
                toVisit.pop();

                cur->right=pre;
                cur->left=nullptr;
                pre=cur;
                cur=nullptr;
            }
            else{
                cur=cur->left;// 左节点还没有访问过就先访问左节点
            }

        }
     }


    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
    
    TreeNode* flattenHelper(TreeNode* root) {
        if (not root) {
            return root;
        }
        TreeNode* temp = root;
        TreeNode* hold = flattenHelper(temp->right);
        temp->right = flattenHelper(temp->left);
        temp->left = nullptr;
        while (temp->right) {
            temp = temp->right;
        }
        temp->right = hold;
        return root;
    }

    public void flatten(TreeNode root) {
        if(root==null){
            return ;
        }
        //先将二叉树转换成左展开链表
        flattenHelper(root);
        //再将左展开转换成右展开链表
        TreeNode tempNode =root;
        while(tempNode.left!=null){
            tempNode.right = tempNode.left;
            tempNode.left = null;
            tempNode= tempNode.right;
        }
    }
    private TreeNode flattenHelper(TreeNode root){
        //如果左右节点都为空则返回当前节点，也就是最后的左边的节点；
        if(root.left==null&&root.right==null){
            return root;
        }
        //如果左为空右不为空，则把右边的移到左边，然后继续递归左边的；
        if(root.left==null&&root.right!=null){
            root.left=root.right;
            root.right=null;
            return flattenHelper(root.left);
        }
        //如果左不为空右为空则直接递归左边的；
        if(root.left!=null&&root.right==null){
            return flattenHelper(root.left);
        }
        //如果左右都不为空则把左边归过来的末节点的左节点赋值为当前节点的右节点，然后继续递归；
            TreeNode nullLeftNode= flattenHelper(root.left);
            nullLeftNode.left = root.right;
            root.right=null;
            return flattenHelper(nullLeftNode.left);
    }

    //解法三：
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return ;
        }
        //先将二叉树转换成左展开链表
        flattenHelper(root);
        //再将左展开转换成右展开链表
        TreeNode* tempNode =root;
        while(tempNode->left!=nullptr){
            tempNode->right = tempNode->left;
            tempNode->left = nullptr;
            tempNode= tempNode->right;
        }
    }
        TreeNode* flattenHelper(TreeNode* root){
        //如果左右节点都为空则返回当前节点，也就是最后的左边的节点；
        if(root->left==nullptr&&root->right==nullptr){
            return root;
        }
        //如果左为空右不为空，则把右边的移到左边，然后继续递归左边的；
        if(root->left==nullptr&&root->right!=nullptr){
            root->left=root->right;
            root->right=nullptr;
            return flattenHelper(root->left);
        }
        //如果左不为空右为空则直接递归左边的；
        if(root->left!=nullptr&&root->right==nullptr){
            return flattenHelper(root->left);
        }
        //如果左右都不为空则把左边归过来的末节点的左节点赋值为当前节点的右节点，然后继续递归；
            TreeNode *nullLeftNode= flattenHelper(root->left);
            nullLeftNode->left = root->right;
            root->right=nullptr;
            return flattenHelper(nullLeftNode->left);
    }
};
/*
题目：二叉树展开为链表
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>

using  namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//解法一：
/*
可以发现展开的顺序其实就是二叉树的先序遍历。算法和 94 题中序遍历的 Morris 算法有些神似，我们需要两步完成这道题。

将左子树插入到右子树的地方
将原来的右子树接到左子树的最右边节点
考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root!=nullptr){
            //左子树为null,直接考虑下一个节点；
            if(root->left==nullptr){
                root=root->right;
            }
            else{
                TreeNode* pre=root->left;
                while(pre->right!=nullptr){
                    pre=pre->right;
                }

                //将原来的右子树接到左子树的最右边节点；
                pre->right=root->right;
                //将左子树插入到右子树的地方；
                root->right=root->left;
                root->left=nullptr;
                root=root->right;
            }
        }

    }
};

//方法二：
class Solutions{
    public:
    void flatten(TreeNode* root){
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                TreeNode* p=cur->left;
                while(p->left){
                    p=p->right;
                }
                p->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
            }
            cur=cur->left;
        }
    }
};

//方法三：采用后续遍历的方式进行求解；依旧用到了递归，链表的只改变指针的方向就可以，而无需改变其实际顺序；
class Solution {
	public :
    void flatten(TreeNode* root) {
		helper(root);
	}
    TreeNode * pre=nullptr;
    void helper(TreeNode *root){
        if(root==nullptr){
            return ;
        }

        helper(root->right);
        helper(root->left);
        root->left=nullptr;
        root->right=pre;
        pre=root;

    }

}；
#include <vector>
#include <iostream>
using namespace std;

//=============================================
//方法一：采用这样的方式运行速度较慢
/*
所以构建二叉树的问题本质上就是：
1)找到各个子树的根节点 root
2)构建该根节点的左子树
3)构建该根节点的右子树
*/
//=============================================
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//==============================================
class Solution {
public:
     public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.empty()){
            return nullptr;
        }

        return hell(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    private:
     TreeNode*hell(vector<int>& preorder, int pStart, int pEnd ,vector<int>& inorder ,int inStart ,int inEnd){
            //递归第一步，避免死循环，加入终止条件；
            if(pStart>pEnd||inStart>inEnd){
                return nullptr;
            }
            // 重建根节点；
            TreeNode* treeNode=new TreeNode(preorder[pStart]);

            int index=0;
            while(inorder[inStart+index]!=preorder[pStart]){
                index++;
            }

            treeNode->left=hell(preorder,pStart+1,pStart+index,inorder,inStart,inStart+index-1);
            treeNode->right=hell(preorder,pStart+index+1,pEnd,inorder,inStart+index+1,inEnd);
            return treeNode;

        }
};
//=============================================
//方法二：采用这样的方式运行速度快
//==============================================
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* cur = root;
        //对前序进行遍历
        for (auto p = 1, i = 0; p < preorder.size(); ++p) {
            if (cur->val != inorder[i]) {
                s.push(cur);
                cur->left = new TreeNode(preorder[p]);
                cur = cur->left;
            }
            else {
                ++i;
                
                while (!s.empty() && s.top()->val == inorder[i]) {
                    cur = s.top();
                    s.pop();
                    
                    ++i;
                }
                
                cur->right = new TreeNode(preorder[p]);
                cur = cur->right;
            }
        }
        
        return root;
    }
    
private:
    stack<TreeNode*> s;
}

//=============================================
//方法三：采用这样的方式运行速度快
//==============================================
   vector<int>inorder;
    vector<int>preorder;
    int pre=0; 
    map<int,int>m;
    
    TreeNode* func(int l_eft,int r_ight)
    {
        
       if(l_eft==r_ight)return NULL;
        
        int r_val=preorder[pre];
        TreeNode *a=new TreeNode(r_val);
        int ind=m[r_val];
        pre++;
        a->left=func(l_eft,ind);
        a->right=func(ind+1,r_ight);
        return a;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    this->inorder=inorder;
    this->preorder=preorder;
  
    for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]]=i;
    }
     return func(0,inorder.size());   
        
    }
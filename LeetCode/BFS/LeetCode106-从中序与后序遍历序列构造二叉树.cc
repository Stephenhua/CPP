#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//======================================
//方法一:采用最简单的方式就行，利用递归的思想
class Solution {
public:
    map<int,int> memo;
    vector<int> post;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++){
            memo.insert(make_pair(inorder[i],i));
        }
        post=postorder;
        TreeNode* root= buildTree1(0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }

    TreeNode *buildTree1(int is, int ie ,int ps ,int pe){
        //递归的终止条件
        if(is>ie ||ps>pe){
            return nullptr;
        }
        //在后续中找出根节点；
        int root=post[pe];
        int ri= memo[root];
        TreeNode* node=new TreeNode(root);
        //再次递归
        node->left=buildTree1(is,ri-1,ps,ps+ri-is-1);
        node->right=buildTree1(ri+1,ie,ps+ri-is,pe-1);
        return node;
    }
};

//======================================
//方法二:采用最简单的方式就行，利用递归的思想，速度较快

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder);
    }
    TreeNode *solve(vector<int>&in ,vector<int>&post){
        int n=in.size();//中序的大小
        int pind=n-1;
        return sloveutil(in ,post ,0,n-1,&pind);
    }

    TreeNode *solvutil(vector<int>& in ,vector<int& post ,int st, int en, int *pind){

        //递归截止的判别条件
        if(st>en){
            return nullptr;
        }

        TreeNode *res= new TreeNode (post[*pind]);
        (*pind)--;
        if(st==en){
            return res;//res表示中间节点；
        }
        int ind= search(in ,st,en, res->val);
        //找到根节点的位置，然后根据节点的位置，前后可以分为两部分，前面为左子树，后面为右子树；

        //进行递归调用函数；
        res->right=solvutil(in,post,ind+1,en,pind);
        res->left=solvutil(in,post,st,ind-1,pind);
        return res;
    }
    //该函数为了在中序中找到根节点
    searhch(vector<int>& in,int st,int en,int target){
        //利用map函数将其先储存起来；
        for(int i=st;i<en;i++){
            if(v[i]==target){
                break;
            }
        }
        return i;
    }

//方法三：依旧采用同样的形式进行求解；
class Solution {
private:
    //设置全局变量；
    vector<int> postorder;
    vector<int> inorder;
    map<int, int> mymap;
    int post_idx;
    TreeNode* helper(int in_left, int in_right) {
        // if no elements then subtree is null
        if (in_left > in_right)
            return NULL;
        
        // the last element is considered as a root
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        
        // split inoder and postorder in left and right subtree
        int index = mymap[root_val];
        
        //decrement index
        post_idx--;
        root->right=helper(index+1,in_right);
        root->left=helper(in_left,index-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        this->inorder = inorder;
        
        //index of last element of postorder is our root
        post_idx = postorder.size() -1;
        
        int idx = 0;
        // build a map value, index
        for(std::vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            mymap[*it] = idx++;
        }
        return helper(0, inorder.size()-1);
    }
};
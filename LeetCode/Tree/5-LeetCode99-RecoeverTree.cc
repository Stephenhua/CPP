/*
题目：恢复二叉搜索树；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//采用之间遍历的方法进行求解，时间复杂度为O(n)；
/*
用中序遍历树，并将所有节点存到一个一维向量中，把所有节点值存到另一个一维向量中，
然后对存节点值的一维向量排序，再将排好的数组按顺序赋给节点。

*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> temp;
        vector<int> values;
        inOrder(root,temp,values);
        sort(values.begin(),values.end());
        for(int i=0;i<temp.size();i++){
            temp[i]->val=values[i];
        }

    }

    void inOrder(TreeNode* root,vector<TreeNode*>& temp,vector<int>& vals){
        if(!root){
            return ;
        }

        inOrder(root->left,temp,vals);
        temp.push_back(root);
        vals.push_back(root->val);
        inOrder(root->right,temp,vals);
    }
};

//方法二：采用双指针代替一维向量，但是这种方法用到了递归的方法，需要三个指针；
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* temp=nullptr;
        TreeNode* cur=root;
        TreeNode* pre=new TreeNode(INT_MIN);
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;

        while(cur!=nullptr){
            if(cur->left == nullptr){
                if(first ==nullptr && pre->val >cur->val){
                    first=pre;
                }
                if(first!=nullptr && pre->val> cur->val){
                    second=cur;
                }
                pre=cur;
                cur=cur->right;
            }else{
                temp=cur->left;
                while(temp->right!=nullptr && temp->right !=cur){
                    temp=temp->right;
                }
                if(temp->right==nullptr){
                    temp->right=cur;
                    cur=cur->left;
                }else{
                    temp->right=nullptr;
                    if(first==nullptr && pre->val > cur->val){//第一个数应该是较大的那个数；
                        first=pre;
                    }
                    if(first!=nullptr && pre->val >cur->val){//第二个数应该是小的那个数
                        second =cur;
                    }
                    pre=cur;
                    cur=cur->right;

                    }


            }

        }
        int t=first->val;
        first->val =second->val;
        second->val =t;

    }

}

//方法三：采用双指针代替一维向量，但是这种方法用到了递归的方法，需要三个指针；
class Solution3{
public:
    void recoverTree(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        //Because we need to compare the neighbor two nodes, we need to use a Pre NULL record the last element when we do traversal in order.
        TreeNode* pre = NULL;
        while (node != NULL) {
            if (node->left == NULL) {
                // check the val in the place of outputing the val in original algorithm
                if (pre != NULL && pre->val > node->val) {
                    if (first == NULL) {
                        first = pre;
                        second = node;
                    } else {
                        second = node;
                    }
                }
                // update pre to node and node to next pos;
                pre = node;
                node = node->right;
            } else {
                TreeNode* temp = node->left;
                // The condition should be && Not or!!!
                while (temp->right != NULL && temp->right != node) {
                    temp = temp->right;
                }
                if (temp->right == NULL) {
                    temp->right = node;
                    node = node->left;
                } else {
                    temp->right = NULL;
                    // check the val in the place of outputing the val in original algorithm
                    if (pre != NULL && pre->val > node->val) {
                        if (first == NULL) {
                            first = pre;
                            second = node;
                        } else {
                            second = node;
                        }
                    }
                    pre = node;
                    node = node->right;
                }
            }
        }
        swap(first->val, second->val);

    }

};

//方法四：
class Solution4 {
private:
    vector<int> numbers;
public:
    void recoverTree(TreeNode* root) {
        search(root);
        sort(numbers.begin(), numbers.end());
        fill(root, 0);
    }
    int search(TreeNode* root){
        if(root == NULL) return 0;
        numbers.push_back(root->val);
        int left = search(root->left);
        int right = search(root->right);
        root->val = left;
        return (left + right + 1);
    }
    void fill(TreeNode* root, int front){
        if(root == NULL) return;
        int tmp = root->val;
        root->val = numbers[front+tmp];
        fill(root->left, front);
        fill(root->right, front+tmp+1);
    }
};
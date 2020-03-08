/*
题目:437 路径总和 III
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//采用了双层递归的形式进行求解；
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return 0;
        }
        int res=0;
        if(root->val ==sum){
            res++;
        }
        //// 以 root 为起始节点的, 从 root 开始计算和为 sum 的路径个数
        res+=includePathSum(root->left,sum-root->val);
        res+=includePathSum(root->right,sum-root->val);
        // 继续将每个节点当作根节点， 求从根节点开始和为 sum 的路径条数
        res+=pathSum(root->left,sum);
        res+=pathSum(root->right,sum);
        return res;
    }

     // 寻找以 root 为起始节点的， 从 root 开始计算并且路径上的节点和为 sum 的路径条数
    int  includePathSum(TreeNode* root ,int sum){
        if(root ==NULL){// 不需要是叶子节点， 所以此处是直接是 root == NULL 就直接返回 0
            return 0;
        }
        int ret=0;
        if(root->val==sum){
            ret++;
        }
        // 此处就不能直接返回， 需要一直遍历到叶子节点， 如果后续还存在 0 或者 负数(如 -5， 5, 那么再加上后两个元素， 也是满满足题意的)， 
        ret+=includePathSum(root->left,sum-root->val);
        ret+=includePathSum(root->right,sum-root->val);
        return ret;
    }
};


class Solution {
 private:
 void pathSumFromNode(TreeNode* root ,int sum, int &count){//从某一点开始进行计算，将该节点当为根节点，然后进行求解；
     if(root==nullptr){
         return;
     }

     if(sum==root->val){
         count++;
     }

     pathSumFromNode(root->left,sum-root->val,count);
     pathSumFromNode(root->right,sum-root->val,count);
 }

public:
    int pathSum(TreeNode* root, int sum) {
        //采用前序遍历来遍历整个节点，而每个节点都当做一个根，在根的基础上进行遍历；
       int count= 0;
       pathSumFromNode(root,sum,count);//相当于前序遍历的操作；
       if(root){
           count+=pathSum(root->left,sum);
           count+=pathSum(root->right,sum);
       }
       return count;
    }

};


//采用迭代的形式进行计算；
class Solutions2{
    private:
    int sum;
    vector<int> sums;
    int path_num;
    void tra(TreeNode* cur){
        sums.push_back(cur->val);
        int temp=0;
        for(int i=sums.size()-1;i>=0;i--){
            temp+=sums[i];
            if(temp==sum){
                path_num++;
            }

        }

        if(cur->left){
            tra(cur->left);
        }

        if(cur->right){
            tra(cur->right);
        }
        sums.pop_back();
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        this->sum = sum;
        sums.clear();
        path_num = 0;
        tra(root);
        return path_num;
    }

};

/*
题目： 二叉树的锯齿形层次遍历
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//双端队列；可以在队列的入口和出口进行相关的插入与删除
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        deque<TreeNode*> que;
        que.push_back(root);
        bool zigz=true;
        TreeNode* temp;
        while(!que.empty()){
            int Size=que.size();
            vector<int> temp_result;
            while(Size){
                if(zigz){//前面取值，后面插入；
                    temp=que.front();
                    que.pop_front();
                    if(temp->left){
                        que.push_back(temp->left);
                    }
                    if(temp->right){
                        que.push_back(temp->right);
                    }
                }else{//后面取值，前面插入；
                    temp=que.back();
                    que.pop_back();
                    if(temp->right){
                        que.push_front(temp->right);
                    }
                    if(temp->left){
                        que.push_front(temp->left);
                    }
                }
                temp_result.push_back(temp->val);
                --Size;

            }
            zigz=!zigz;
            result.push_back(temp_result);
        }
        return result;
    }

};
//方法二在方法一上面的优化主体现在如何存储值；

class Solutions2{
    public:
     vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
         if(root==nullptr){
             return vector<vector<int>> ();
         }

         vector<vector<int>> result;
         queue<TreeNode*> nodeQueue;
         nodeQueue.push(root);
         bool leftToRight=true;

         while(!nodeQueue.empty()){
             int Size=nodeQueue.size();
             vector<int> temp_result;//需要进行初始化；
             for(int i=0;i<Size;i++){
                 TreeNode* node=nodeQueue.front();
                 nodeQueue.pop();
                 int index=(leftToRight)?i:(Size-i-1);
                 temp_result[index]=node->val;

                 if(node->left){
                     nodeQueue.push(node->left);
                 }

                 if(node->right){
                     nodeQueue.push(node->right);
                 }

             }
             leftToRight=!leftToRight;
             result.push_back(temp_result);
         }
         return result;

     }

}；
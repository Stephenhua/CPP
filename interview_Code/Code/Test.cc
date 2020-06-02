#include <iostream>
#include <vector>
#include <queue>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode * left;
      TreeNode * right;
      TreeNode(int x): val(x), left(NULL), right(NULL) {}
 };
 

vector<int> walkTree(TreeNode * root) {

    vector<int > res;

    if( root == nullptr){
        return res;
    }

    queue<TreeNode*> queueTree;
    queueTree.push(root);

    while( !queueTree.empty()){

        int size = queueTree.size();

        while( size--){
            
            TreeNode* Node = queueTree.front();
            queueTree.pop();

            res.push_back(Node->val);

            if( Node->left != nullptr){

                queueTree.push(Node->left);
            }

            if( Node->right != nullptr){

                queueTree.push( Node->right);

            }

        }
    }
    return res;
}

void getSubSetCore( vector<int>& nums, int start , int end){

    if( start == end){
        for( int i=0 ;i<=end ;i++){
            cout <<nums[i];
        }
        cout<<endl;
    }else{

        for( int i = start ;i<=end; i++){

            swap( nums[i] ,nums[start]);
            getSubSetCore( nums, start+1 ,end);
            swap( nums[i] ,nums[start]);

        }
    }
}
void getSubSet( vector<int>& nums ){
    if( nums.size() == 0){
        return ;
    }
    int size = nums.size();
    getSubSetCore( nums,0 ,size);
}



void merge(vector<vector<int>>  & data_sorted, vector<int> * result) {


}

void MergeSort( vector<int>& nums){

    if( nums.size() == 0){
        return ;
    }


}

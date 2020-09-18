#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right;
    TreeNode(int x ) :val(x),left(NULL),right(NULL){ }
};

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return result;
        }

        vector<int> value ;
        Core( root,value,sum);
        return result;

    }

    void Core(TreeNode* root , vector<int>& value ,int sum ){

        if( root == nullptr ){
            return ;
        }

        value.push_back(root->val);
        if( root->val == sum && root->left == nullptr && root->right == nullptr ){
            result.push_back(value);
        }

        Core(root->left ,value , sum-root->val);
        Core(root->right , value ,sum -root->val);

        value.pop_back();
    }
};
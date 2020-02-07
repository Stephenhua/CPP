#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


/*前序遍历:采用栈的思想进行
*递归思想：先树根，然后左子树，然后右子树，每颗子树递归
*在迭代算法中，思路演变成，每到一个节点 A，就应该立即访问它。
*因为，每棵子树都先访问其根节点。对节点的左右子树来说，也一定是先访问根。
*在 A 的两棵子树中，遍历完左子树后，再遍历右子树。
*因此，在访问完根节点后，遍历左子树前，要将右子树压入栈。
*思路：
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的右子树入S;
        p = p的左子树;
    }
    p = S栈顶弹出;
}

*/
class Solution {
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > S;
        vector<int> result;
        TreeNode* rt=root;
        while(rt||S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt-val);
                rt=rt->left;
            }
            rt=S.top();
            S.pop();
        }
        return result;
    }


};


/*后序遍历:采用栈的思想进行
*递归思想：先树根，然后左子树，然后右子树，每颗子树递归
*在迭代算法中，思路演变成，每到一个节点 A，就应该立即访问它。
*因为，每棵子树都先访问其根节点。对节点的左右子树来说，也一定最后先访问根。
*每到一个节点 A，就应该立即访问它。 然后将左子树压入栈，再次遍历右子树。
*因此，在访问完根节点后，遍历左子树前，要将右子树压入栈。
*思路：
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的左子树入S;
        p = p的右子树;
    }
    p = S栈顶弹出;
}
结果序列逆序;

*/
class Solution {
    vector<int> postorderTraversal(TreeNode* root) {

        stack<TreeNode*> S ;
        vector<int> result;
        TreeNode* rt=root;
        while(rt||S.size()){
            while(rt){
                S.push(rt->left);
                result.push_back(rt->val);
                rt=rt->val;
            }

            rt=S.top();
            S.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
 
};


/*中序遍历:采用栈的思想进行
*递归思想：每到一个节点 A，因为根的访问在中间，将 A 入栈。然后遍历左子树，接着访问 A，最后遍历右子树。
*在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
*思路：
栈S;
p= root;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    p = S.top 出栈;
    访问p;
    p = p的右子树;
}

*/

class Solution {
    vector<int> postorderTraversal(TreeNode* root) {

        stack<TreeNode *> S ;
        vector<int> result;
        TreeNode* rt=root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }

            rt=S.top();
            S.pop();
            result.push_back(rt->val);
            rt=rt->val;
        }
        return result;
    }
};


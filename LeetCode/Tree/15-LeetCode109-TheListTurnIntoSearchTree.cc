/*
题目： 109. 有序链表转换二叉搜索树
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

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    TreeNode* sortedListedBST(ListNode* head,ListNode* end){
        auto mid=get_MIdList(head,end);
        auto rt=new TreeNode(mid->val);
        if(head==mid){
            return rt;
        }
        rt->left=sortedListedBST(head,mid);
        rt->right=sortedListedBST(mid->next,end);
        

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return NULL;
        }

        while(head!=nullptr && head->next!=nullptr){
            head=head->next;
        }
        ListNode* end=head;
        return sortedListedBST(head,end);

    }
    ListNode* get_MIdList(ListNode* head,ListNode* stop){
        auto f=head;
        auto s=head;
        while(f!=stop && f->next!=stop){
            f=f->next->next;
            s=s->next;
        }
    }
};
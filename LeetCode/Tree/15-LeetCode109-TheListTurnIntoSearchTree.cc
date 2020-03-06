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
    TreeNode* sortedListToBST(ListNode* head){
        return sortedListToBST(head,NULL);
    }

    private:
    TreeNode* sortedListToBST(ListNode* head,ListNode* tail){
        if(head==tail){
            return NULL;
        }

        if(head->next == tail){
            TreeNode* root= new TreeNode(head->val);
            return root;
        }

        ListNode* temp=head;
        ListNode* mid=head;
        
        while(temp!=tail && temp->next!=tail){
            mid=mid->next;
            temp=temp->next->next;
        }

        TreeNode* root=new TreeNode(mid->val);
        root->left= sortedListToBST(head ,mid);
        root->right =sortedListToBST(head->next,tail);
        return root;
    }
};

//最优解
class Solution {
    // DFS: the mid of the sorted linkedlist is the root of the subtree
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return (new TreeNode(head->val));
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        ListNode* mid = head;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // break the list into two parts
        // part 1 is before mid, next points to NULL
        // part 2 is after mid, next pionts to original end        
        mid = slow->next;//将mid中下一个指向为中间指针；
        prev->next = NULL;//下一跳为空指针；
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid);
        return root;
    }
};
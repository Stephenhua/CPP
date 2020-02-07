#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//===============================================
//方法一：采用递归的形式进行求解；运行时间较短，但是占用内存较多
/*
1、由于我们得到的是一个有序链表而不是数组，我们不能直接使用下标来访问元素。我们需要知道链表中的中间元素。
2、我们可以利用两个指针来访问链表中的中间元素。假设我们有两个指针 slow_ptr 和 fast_ptr。slow_ptr 每次向后移动一个节点而 fast_ptr 每次移动两个节点。当 fast_ptr 到链表的末尾时 slow_ptr 就访问到链表的中间元素。对于一个偶数长度的数组，中间两个元素都可用来作二叉搜索树的根。
3、当找到链表中的中间元素后，我们将链表从中间元素的左侧断开，做法是使用一个 prev_ptr 的指针记录 slow_ptr 之前的元素，也就是满足 prev_ptr.next = slow_ptr。断开左侧部分就是让 prev_ptr.next = None。
4、我们只需要将链表的头指针传递给转换函数，进行高度平衡二叉搜索树的转换。所以递归调用的时候，左半部分我们传递原始的头指针；右半部分传递 slow_ptr.next 作为头指针。

时间复杂度：
时间复杂度：O(N\log N)O(NlogN)。假设链表包含 NN 个元素，对于传入递归函数的每个列表，我们需要计算它的中间元素。对于一个大小为 NN 的列表，需要 N/2N/2 步找到中间元素，也就是花费 O(N)O(N) 的时间。我们对于原始数组的每一半都要同样的操作，看上去这是一个 O(N^2)O(N 
空间的复杂度：
O(logN)。因为使用递归的方法，所以需要考虑递归栈的空间复杂度。对于一棵费平衡二叉树，可能需要 O(N)O(N) 的空间，但是问题描述中要求维护一棵平衡二叉树，所以保证树的高度上界为 O(\log N)O(logN)，因此空间复杂度为 O(\log N)O(logN)。
*/

class Solution {
    public:
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

public:
TreeNode* sortedListToBST(ListNode* head) {
      //递归终止条件
    if(head==nullptr){
        return nullptr;
    }else if(head->next==nullptr){
        return new TreeNode (head->val);
    }
   
    ListNode*  slowPtr =head;
    ListNode*  fastPtr =head;
     ListNode*  prevPtr=slowPtr;

    //寻找根节点
    while(fastPtr->next &&fastPtr->next->next){
        prevPtr = slowPtr;
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
    }

    fastPtr=slowPtr->next;
    prevPtr->next=nullptr;

    //找到节点列表；
    TreeNode * node =new TreeNode(slowPtr->val);
    if(head!=slowPtr){
       node->left=sortedListToBST(head);
    }
         node->right=sortedListToBST(fastPtr);
    return node;
}

};



//===============================================
//方法二：采用递归+数组,速度和内存均比较慢
/*
1、将给定链表转成数组，将数组的头和尾记成 left 和 right 。
2、找到中间元素 (left + right) / 2，记为 mid。这需要 O(1)O(1) 时间开销，也是与上面算法主要改进的地方。
3、将中间元素作为二叉搜索树的根。
4、递归构造二叉搜索树的左右两棵子树，两个子数组分别是 (left, mid - 1) 和 (mid + 1, right)。
*/

    vector<int > values;
    void maplistToValues(ListNode *head){
        while(head!=nullpter){
            values.push_back(head->val);
            head=head->next;
        }
    }

    TreeNode * initTree(vector<int>& nums,int st, int en){
        if(st>en){
            return nullptr;
        }

        int mid=(st+en+1)/2;
        //将上面的一行直接改为mid =(st+en)/2时，运行速度将会加快一倍；
        TreeNode *t =new TreeNode(nums[mid]);
        if(st==en){
            return t;
        }
        t->left=initTree(nums,st,mid-1);
        t->right= initTree(nums,mid+1,en);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return initTree(nums,0,nums.size()-1);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        maplistToValues(head);
        return initTree(values,0,values.size()-1);
    }

//===============================================
//方法三：通过编写递归函数进行求解
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return helper(head, NULL);
    }
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *cur = new TreeNode(slow->val);
        cur->left = helper(head, slow);
        cur->right = helper(slow->next, tail);
        return cur;
    }
};
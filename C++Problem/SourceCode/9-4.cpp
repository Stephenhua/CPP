#include <iostream>
#include <stack>

struct TreeNode
{
    int value;
    TreeNode* nLeft ;
    TreeNode* nRight;

    TreeNode(int val):value(val),nLeft(nullptr),nRight(nullptr){}
};

void preOrder(TreeNoe* pRoot){

    if(pRoot == nullptr){
        return;
    }

    stack<TreeNode*> sta;
    TreeNode* cur = pRoot;
    sta.push(cur);

    while(!sta.empty() || cur != nullptr){

        while( cur != nullptr){
            sta.push(cur);
            cur = cur->nLeft;
        }
        TreeNode* temp = sta.top();
        sta.pop();
        if(temp->nRight != nullptr){
            sta.push(temp->nRight);
        }


    }

}

struct ListNode{
    int val;
    ListNode* next ;

    ListNode(int val )：val(val),next(nullptr);
};

ListNode* (ListNode* l1 ,ListNode* l2){
        if( l1 == nullptr ){
            return l2;
        }
        if( l2 == nullptr){
            return l1 ;
        }
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }

        ListNode* sumNode = new ListNode(-1);
        ListNode* cur =nullptr;
        sumNode->next = cur;

        int jinwei = 0 ;
        int sum = 0 ;
        //两个都
        while( l1 != nullptr ||  l2 != nullptr || jinwei){
            sum = 0 ;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 ){
                sum += l2->val;
                l2 = l2->next;
            }

            sum +=jinwei;
            jinwei = sum /10 ;
            int yushu = sum%10;

            ListNode* curNode  = new ListNode(yushu);

            cur->next = curNode；
            cur = cur->next;
        }

        return sumNode->next; 
}
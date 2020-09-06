#include<iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val ;
    ListNode* next;
    //ListNode(int value):val(value),next(nullptr){}
};

void sortList(ListNode* l1 ,ListNode* l2 ){
    while ( l1 && l2)
    {
        if(l1->val > l2->val){
            l1 = l1->next;
        }else if( l1->val < l2->val ){
            l2 = l2->next;
        }else{
            cout << l1->val;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    
}
int main(int argc,char*argv[]){
    int n ,m;
    cin >> n ;
    //创建链表；
    ListNode* pHead = new ListNode();
    ListNode* node = pHead;
    //pHead->next = node;

    for(int i = 0 ;i < n ;i++){
        int temp ;
        cin>>temp;
        if(i==0){
            node->val = temp;
            node->next = nullptr;
        }else{
            ListNode* newNode = new ListNode();
            newNode->next = nullptr;
            newNode->val = temp;
            node->next = newNode;
            node = newNode;
        }
    }

    cin >> m ;
    ListNode* pHead2 = new ListNode();
    ListNode* node2 = pHead2;
    //pHead2->next= node2;
    for(int i = 0 ;i < m ;i++){
        int temp ;
        cin>>temp;
        if(i==0){
            node2->val = temp;
            node2->next = nullptr;
        }else{
            ListNode* newNode = new ListNode();
            newNode->val = temp;
            newNode->next = nullptr;
            node2->next = newNode;
            node2 = newNode;
        }
    }

    sortList(pHead,pHead2);
    system("pause");
    return 0;

}
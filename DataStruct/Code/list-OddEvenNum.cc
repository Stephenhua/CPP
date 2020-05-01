#include <iostream>
#include "list.h"

using namespace std;

/*
题目：给定一个链表，对每个链表中的元素值进行求区分，使链表中的奇数放在偶数前面；

*/

//方法一：链表的最开始还有一个指针，比平时的链表要长一个节点；
void split( ListNode* L ){
    ListNode* p = L;
    ListNode* B ;
    B->m_pNext = nullptr;

    ListNode* q = B ;
    ListNode* r ;

    while( p->m_pNext !=nullptr){

        if( p->m_pNext->m_nValue  %2  == 0){
            //说明元素时偶函数，然后进行操作；
            r = p->m_pNext;
            //原始链表节点进行向后移一位；
            p->m_pNext = p->m_pNext->m_pNext;

            //将偶数的链表向右移一位；
            q->m_pNext = r; 
            r->m_pNext  = nullptr;

            q = q->m_pNext;
        }else{
            p = p->m_pNext;
        }
    }

    p->m_pNext = q;//将两个链表进行相连；

    //输出链表元素；

    while( p->m_pNext != nullptr){
        cout<<" value" <<p->m_pNext->m_nValue ;
        p = p->m_pNext ;
    }

    cout <<endl;


}




//方法二：对每一个元素进行奇偶判断；
ListNode* split_2( ListNode* list){
    if(list == nullptr){
        return nullptr;
    }

    if( list->m_pNext == nullptr){
        return list;
    }

    ListNode* p= list ;
    ListNode* oddHead  = (ListNode*) malloc( sizeof(ListNode)) ;
    ListNode* evenHead = (ListNode*) malloc( sizeof(ListNode)) ;

    ListNode* odd = oddHead ;//偶数元素；
    ListNode* even = evenHead;

    while( p ){
        cout <<"hello "<< endl;

        if( p->m_nValue%2 == 1){
            even->m_pNext = p ;
            even = even->m_pNext;
        }else if(p->m_nValue%2 == 0){

            odd->m_pNext = p ;
            odd = odd->m_pNext;
        }
        cout <<"hello "<< endl;
        p = p->m_pNext;
    }
    odd->m_pNext = nullptr;
    even->m_pNext = oddHead->m_pNext;
    return evenHead->m_pNext;

}


void Test(ListNode* pHead){
    printf("The original list is:\n");
    PrintList(pHead);

     ListNode * result = split_2(pHead);

    PrintList(result);
}
void Test1(){
    ListNode* pNode1=CreateListNode(8);
    ListNode* pNode2 =CreateListNode(2);
    ListNode* pNode3=CreateListNode(3);
    ListNode* pNode4=CreateListNode(4);
    ListNode* pNode5=CreateListNode(5);
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);

    //PrintList(pNode1);
     Test(pNode1);
    //DestroyList(pReverseHead);
}

int main(int argc, char* argv[]){

    Test1();

    system("pause");
    return 0 ;
}
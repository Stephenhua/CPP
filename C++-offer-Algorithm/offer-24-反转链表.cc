#include"Lsit.h"
#include<cstdio>
#include <iostream>
using namespace std;

ListNode * ReverseList(ListNode* pHead){
    ListNode* pReversedHead =nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev= nullptr;

    while(pNode!=nullptr){
        ListNode * pNext=pNode->m_pNext;
        if(pNode==nullptr){
            pReversedHead=pNode;
        }

        pNode->m_pNext =pPrev;
        pPrev=pNode;
        pNode=pNext;
    }
    return pReversedHead;
}

ListNode* Test(ListNode* pHead){
    printf("The original list is:\n");
    PrintList(pHead);

    ListNode* pReversedHead=ReverseList(pHead);
    PrintList(pReversedHead);
    return pReversedHead;
}

//输入的链表有多个节点
void Test1(){
    ListNode* pNode1=CreateListNode(1);
    ListNode* pNode2 =CreateListNode(2);
    ListNode* pNode3=CreateListNode(3);
    ListNode* pNode4=CreateListNode(4);
    ListNode* pNode5=CreateListNode(5);
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);

    ListNode* pReverseHead=Test(pNode1);
    DestroyList(pReverseHead);
}

//输入的链表只有一个节点
void Test2(){
    ListNode* pNode1=CreateListNode(1);
    ListNode* pReverseHead=Test(pNode1);
    DestroyList(pReverseHead);
}

void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

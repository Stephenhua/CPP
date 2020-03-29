#include <iostream>
#include<algorithm>
#include <cstdlib>
#include "list.h"

using namespace std;


void DeleteNode(ListNode** pRoot, ListNode* PDeleteNode){
    if(!pRoot || !PDeleteNode){
        return;
    }

    //删除的节点不是尾结点；
    if(PDeleteNode->m_pNext!=nullptr){
        ListNode* pNext=PDeleteNode->m_pNext;
        PDeleteNode->m_nValue=pNext->m_nValue;
        PDeleteNode->m_pNext=pNext->m_pNext;

        delete pNext;
        pNext=nullptr;
    }//删除头结点
    else if(*pRoot==PDeleteNode){
        delete PDeleteNode;
        PDeleteNode=nullptr;
        *pRoot=nullptr;
    }else{//删除尾结点；
        ListNode* pNode=*pRoot;
        while(pNode->m_pNext!=PDeleteNode){
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=nullptr;
        delete PDeleteNode;
        PDeleteNode=nullptr;
    }
}


// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    
    Test2();

    Test3();
    Test4();
    Test5();

    system("pause");
    return 0;
}

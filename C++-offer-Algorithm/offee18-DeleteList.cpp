#include "Lsit.h"
#include <cstdio>

void DeleteNode(ListNode ** pListHead,ListNode * pToBeDeleted){
    if(!pListHead || !pToBeDeleted){
        return ;
    }
    //如果删除不是尾节点；
    if(pToBeDeleted->m_pNext!=nullptr){
        ListNode * pNext= pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue=pNext->m_nValue;
        pToBeDeleted->m_pNext=pNext->m_pNext;
        
        delete pNext;
        pNext==nullptr;
    }//链表中只有一个节点，删除头节点（也是尾节点）
    else if(pToBeDeleted->m_pNext==pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted==nullptr;
        *pListHead=nullptr;
    }else{
        //链表中，有多个节点，删除尾节点
        ListNode *pNode =*pListHead;
        while(pNode->m_pNext!=pToBeDeleted){
            pNode=pNode->m_pNext;
        }

        pNode->m_pNext=nullptr;
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
    }
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

    return 0;
}

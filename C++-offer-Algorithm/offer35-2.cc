#include "LetCode35.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode * ReconnectNodes(ComplexListNode* pHead);

ComplexListNode * Clone(ComplexListNode* pHead){
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
     return ReconnectNodes(pHead);
}
//根据原始链表的每一个节点N创建对应的N';
void CloneNodes(ComplexListNode* pHead){
    ComplexListNode *pNode =pHead;
    while(pNode!=nullptr){
        ComplexListNode* pCloned=new ComplexListNode();
        pCloned->m_nValue=pNode->m_nValue;
        pCloned->m_pNext=pNode->m_pNext;
        pCloned->m_pSibling=nullptr;

        pNode->m_pNext=pCloned;
        pNode=pCloned->m_pNext;
    }
}

//复制出来的节点m_PSibling指针
void ConnectSiblingNodes(ComplexListNode* pHead){
    ComplexListNode* pNode  =pHead;

    while(pNode!=nullptr){

        ComplexListNode* pCloned =pNode->m_pNext;

        if(pNode->m_pSibling!=nullptr){

            pCloned->m_pSibling=pNode->m_pSibling->m_pNext;

        }
        pNode=pCloned->m_pNext;
    }
}

//将复制后的节点进行摘取；

ComplexListNode* ReconnectNodes( ComplexListNode* pHead){
    ComplexListNode* pNode =pHead;
    ComplexListNode* pClonedHead=nullptr;
    ComplexListNode* pClonedNode=nullptr;

    if(pNode!=nullptr){

        pClonedHead=pNode->m_pNext;
        pClonedNode=pNode->m_pNext;
        pNode->m_pNext=pClonedNode->m_pNext;
        pNode=pNode->m_pNext;
    }

    if(pNode!=nullptr){

        pClonedNode->m_pNext=pNode->m_pNext;
        pClonedNode=pClonedHead->m_pNext;
        pNode->m_pNext=pClonedNode->m_pNext;
        pNode=pNode->m_pNext;

    }

    return pClonedHead;
}


// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
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

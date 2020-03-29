#include "list.h"
#include <cstdio>
using namespace std;

void DeleteDuplication(ListNode ** pHead){
    if(pHead == nullptr ||*pHead ==nullptr){
        return;
    }

    ListNode * preNode=nullptr;//初始化前一个节点
    ListNode *pNode=*pHead;//初始化第二个节点；
    while (pNode!=nullptr)
    {
        /* code */
        ListNode* pNext=pNode->m_pNext;
        bool NeedDeelete =false;
        if(pNext!=nullptr &&pNext->m_nValue==pNode->m_nValue){//判断节点的值与下一个节点的值相同，
            NeedDeelete=true;
        }

        if(!NeedDeelete){//如果不相同，那么需要进行遍历
            preNode=pNode;
            pNode=pNode->m_pNext;
        }
        else{//处理连续循环的指针，相等的话进行删除操作
            int value =pNode->m_nValue;//记录第一个相同的节点的值；
            ListNode* pToBeDel=pNode;//记录当前节点与下一个节点相等时，保存其值然后进行删除
            while (pToBeDel!=nullptr&&pToBeDel->m_nValue==value)
            {
                pNext=pToBeDel->m_pNext;//将下一个相同节点进行遍历；
                
                delete pToBeDel;
                pToBeDel=nullptr;
                pToBeDel=pNext;                
                /* code */
            }

            if(preNode==nullptr){//如果前一个节点为空，那么头结点指针直接指向它；
                *pHead=pNext;
            }
            else{//否则将前一个节点指向不相同的节点；
                preNode->m_pNext=pNext;
            }
            pNode=pNext;//记录查找下一个节点是否相同，
        }
    }
    
}

//测试代码
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 某些结点是重复的
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 没有重复的结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 所有结点的值都相同
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 所有结点都成对出现
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有一个结点
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 空链表
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    
    system("pause");
    return 0;
}
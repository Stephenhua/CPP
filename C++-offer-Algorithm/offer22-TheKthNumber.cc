#include<cstdio>
#include"list.h"

ListNode *FindKthTotail(ListNode* pListHead, unsigned int k){
    if(pListHead==nullptr ||k==0){
        return nullptr;
    }

    ListNode* pAhead= pListHead;
    ListNode *pBehind=nullptr;

    for(int i=0;i<k-1;i++){
        if(pAhead->m_pNext==nullptr){
            return nullptr;
        }else{
            pAhead=pAhead->m_pNext;
        }
    }
    pBehind=pListHead;
    while (pAhead->m_pNext!=nullptr)
    {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
        /* code */
    }
    return pBehind;
    
}


//测试节点为中间节点；
void Test1(){
    printf("========Test1 starts:============");
    ListNode* pNode1=CreateListNode(1);
    ListNode* nNode2=CreateListNode(2);
    ListNode* nNode3=CreateListNode(3);
    ListNode* nNode4=CreateListNode(4);
    ListNode* nNode5=CreateListNode(5);
    ConnectListNodes(pNode1,nNode2);
    ConnectListNodes(nNode2,nNode3);
    ConnectListNodes(nNode3,nNode4);
    ConnectListNodes(nNode4,nNode5);

    printf("expected reslut:5\n");
    ListNode* pNode=FindKthTotail(pNode1,3);
    PrintListNode(pNode);
    DestroyList(pNode1);
}

//测试节点为尾节点；
void Test2(){
    printf("========Test1 starts:============");
    ListNode* pNode1=CreateListNode(1);
    ListNode* nNode2=CreateListNode(2);
    ListNode* nNode3=CreateListNode(3);
    ListNode* nNode4=CreateListNode(4);
    ListNode* nNode5=CreateListNode(5);
    ConnectListNodes(pNode1,nNode2);
    ConnectListNodes(nNode2,nNode3);
    ConnectListNodes(nNode3,nNode4);
    ConnectListNodes(nNode4,nNode5);

    printf("expected reslut:5\n");
    ListNode* pNode=FindKthTotail(pNode1,5);
    PrintListNode(pNode);
    DestroyList(pNode1);
}

//测试节点为头节点；
void Test3(){
    printf("========Test1 starts:============");
    ListNode* pNode1=CreateListNode(1);
    ListNode* nNode2=CreateListNode(2);
    ListNode* nNode3=CreateListNode(3);
    ListNode* nNode4=CreateListNode(4);
    ListNode* nNode5=CreateListNode(5);
    ConnectListNodes(pNode1,nNode2);
    ConnectListNodes(nNode2,nNode3);
    ConnectListNodes(nNode3,nNode4);
    ConnectListNodes(nNode4,nNode5);

    printf("expected reslut:5\n");
    ListNode* pNode=FindKthTotail(pNode1,1);
    PrintListNode(pNode);
    DestroyList(pNode1);
}

//测试节点大于总结点的数量；
void Test4(){
    printf("========Test1 starts:============");
    ListNode* pNode1=CreateListNode(1);
    ListNode* nNode2=CreateListNode(2);
    ListNode* nNode3=CreateListNode(3);
    ListNode* nNode4=CreateListNode(4);
    ListNode* nNode5=CreateListNode(5);
    ConnectListNodes(pNode1,nNode2);
    ConnectListNodes(nNode2,nNode3);
    ConnectListNodes(nNode3,nNode4);
    ConnectListNodes(nNode4,nNode5);

    printf("expected reslut:5\n");
    ListNode* pNode=FindKthTotail(pNode1,6);
    PrintListNode(pNode);
    DestroyList(pNode1);
}


// 测试空链表
void Test5()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthTotail(nullptr, 100);
    PrintListNode(pNode);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    //Test6();
    system("pause");

    return 0;
}
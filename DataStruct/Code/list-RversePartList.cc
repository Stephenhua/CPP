#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include "string.h"
#include "list.h"
using namespace std;

/*
题目：反转列表m-n位置上的节点列表；

*/

ListNode* ReverstPartNode(ListNode* pHead, int m ,int n){

    if(pHead == nullptr || m<0 || n<0){
        return pHead;
    }

    int length=0;//计算列表的长度：
    ListNode* pPre=nullptr;//m前一个节点
    ListNode* pPost=nullptr;// nh后一个节点
    ListNode* pCurrNode=pHead;//当前节点；

   while(pCurrNode!=nullptr){

        length++;

        pPre=(length==m-1)?pCurrNode:pPre;

        pPost=(length == n+1)?pCurrNode:pPost;
        pCurrNode = pCurrNode->m_pNext;
    }
   // cout<<"Hello"<<endl;
    //进行边界条件检测
    if(m>length ||n<m ||n>length){
        return pHead;
    }

    pCurrNode = ((pPre == nullptr)?pHead:pPre->m_pNext);//找到反转的起始节点；
   
    ListNode* ReverseNode=pCurrNode->m_pNext;//反转的的第二个节点；
   
    pCurrNode->m_pNext = pPost;//反转的第一个节点可以与n后的一个节点进行相连；


    ListNode* nextNode= nullptr;

    while(ReverseNode!= pPost){
        
        nextNode = ReverseNode->m_pNext;

        ReverseNode->m_pNext=pCurrNode;

        pCurrNode = ReverseNode;

        ReverseNode = nextNode;

    }

    if(pPre !=nullptr){

        pPre->m_pNext = pCurrNode;//将m的前一个节点与下一个节点进行连接；
        return pHead;
    }

    return pCurrNode;
}



ListNode* Test(ListNode* pHead){
    printf("The original list is:\n");
    PrintList(pHead);

    ListNode* pReversedHead=ReverstPartNode(pHead,2,3);

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

    //PrintList(pNode1);
    ListNode* pReverseHead=Test(pNode1);
    DestroyList(pReverseHead);
}
/*
//输入的链表只有一个节点
void Test2(){
    ListNode* pNode1=CreateListNode(1);

    PrintList(pNode1);
    ListNode* pReverseHead=Test(pNode1);
    DestroyList(pReverseHead);
}

void Test3()
{
    Test(nullptr);
    
    ListNode* pReverseHead=Test(nullptr);
    DestroyList(pReverseHead);
}
*/
int main(int argc, char* argv[])
{
    Test1();
   //Test2();
    //Test3();
    system("pause");
    return 0;
}

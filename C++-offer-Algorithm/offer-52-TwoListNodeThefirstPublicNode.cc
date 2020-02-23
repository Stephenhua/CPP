#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include "Lsit.h"

using namespace std;
/*
struct ListNode{
    int m_nKey;
    ListNode *m_pNext;
};

//方法一：采用蛮力法


//方法二：新加两个辅助栈用于链表，从后开始寻找节点，如果向前遍历的时候需要看不同的节点即可,创建额外的一个内存空间进行存储数据；

ListNode FindFirstCommonNode(ListNode pHead1,ListNode pHead2){
    if(pHead1==nullptr ||pHead2==nullptr){
        return nullptr;
    }

    stack<ListNode> pStack1=new stack<ListNode>();
    stack<ListNode> pStack2= new stack<ListNode>();

    while(pHead1!=nullptr){
        pStack1.push(pHead1.m_nKey);
        pHead1=pHead1.m_pNext;
    }

    while(pHead2!=nullptr){
        pStack2.push(pHead2.m_nKey);
        pHead2=pHead2.m_pNext;
    }

    ListNode temp=nullptr;

    while(!pStack2.empty()&&!pStack1.empty()){
        ListNode temp1=pStack1.pop();
        ListNode temp2=pStack2.pop();

        if(temp1.m_nKey==temp2.m_nKey){
            temp=temp1;
        }
        else{
            break;
        }
    }

    return temp;

}
*/
//方法三:首先获得两个链表的长度，对于长链表要先走若干部，然后两个链表一起走，找到的第一个相同的节点就是他们的的第一个公共节点


class Solutons{
    private:
    struct ListNode{
        int val;
        struct ListNode *next;
    };

    int GetListLength(ListNode *pHead){
        if(pHead==nullptr)
        return 0;
        
        int length=1;
        while(pHead->next!=nullptr){
            pHead=pHead->next;
            length++;
        }
        return length;        
    }

    public:
        ListNode* FindFirstCommonNode1(ListNode* pHead1,ListNode* pHead2){
            if(pHead2==nullptr||pHead1==nullptr){
                return nullptr;
            }
            int lengthDif;
            ListNode* PheadLong=pHead1;
            ListNode* PheadShort=pHead2;
            int length1=GetListLength(pHead1);
            int length2=GetListLength(pHead2);
            if(length1<length2){
                 PheadLong=pHead1;
                 PheadShort=pHead2;                 
                 lengthDif=length1-length2;
            }else{
                 PheadLong=pHead2;
                 PheadShort=pHead1;
                 lengthDif=length2-length1;
            }

            for(int i=0;i<lengthDif;i++){
                PheadLong=PheadLong->next;
            }

            while(PheadLong!=nullptr && PheadShort!=nullptr && PheadLong!=PheadShort){

                PheadShort=PheadShort->next;
                PheadLong = PheadLong->next;
            }

            return PheadLong;
        }

        void Test(char * testName ,ListNode *pHead1,ListNode *pHead2, ListNode * pExpected){
            if(testName!=nullptr){
                cout<<testName<<endl;
            }

            ListNode*pResult = FindFirstCommonNode1(pHead1,pHead2);

            if(pResult==pExpected){
                cout<<"passed"<<endl;
            }else{
                cout<<"failed"<<endl;
            }

        }
};


void Test1()
{
    
    Solutons temp;
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    temp.Test("Test1", pNode1, pNode4, pNode6);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
    Solutons temp;
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
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    temp.Test("Test2",pNode1,pNode5,nullptr);

    //temp.Test("Test2", pNode1, pNode5, nullptr);

     DestroyNode(pNode1);
     DestroyNode(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
        Solutons temp;
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
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    temp.Test("Test3", pNode1, pNode5, pNode7);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合   
void Test4()
{
        Solutons temp;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    temp.Test("Test4", pNode1, pNode1, pNode1);

     DestroyNode(pNode1);
}

// 输入的两个链表有一个空链表
void Test5()
{
        Solutons temp;
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    temp.Test("Test5", nullptr, pNode1, nullptr);

     DestroyNode(pNode1);
}

// 输入的两个链表有一个空链表
void Test6()
{
        Solutons temp;
    temp.Test("Test6", nullptr, nullptr, nullptr);
}

void DestroyNode(ListNode* pNode)
{
    delete pNode;
    pNode = nullptr;
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    system("pause");
    return 0;
}
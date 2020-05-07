#include <iostream>
#include <vector>
#include <map>
//#include "BianryTreeNode.h"
using namespace std;
struct BianryTreeNode{
    int  m_nValue;
    BianryTreeNode * m_pLeft;
    BianryTreeNode * m_pRight;
    BianryTreeNode * m_pParent;
};
BianryTreeNode* GetNext( BianryTreeNode* node){

    if(node == nullptr){
        return nullptr;
    }

    BianryTreeNode* NextNode = nullptr ;

    if(node->m_pRight !=nullptr){
        BianryTreeNode* leftNode = node->m_pRight;

        while(leftNode->m_pLeft != nullptr){
            leftNode = leftNode->m_pLeft;
        }

        NextNode = leftNode;
    }else if( node->m_pParent !=nullptr){
        BianryTreeNode* pCurrentNode = node ;
        BianryTreeNode* parentNode =pCurrentNode->m_pParent;

        while( parentNode!= nullptr && pCurrentNode == parentNode->m_pRight ){

            pCurrentNode = parentNode ;
            parentNode = pCurrentNode->m_pParent;

        }

        NextNode = parentNode;
    }
    return NextNode ;
}


BianryTreeNode* CreateBianryTreeNode(int value){
    BianryTreeNode *pNode= new BianryTreeNode();
    pNode->m_pLeft=nullptr;
    pNode->m_pParent=nullptr;
    pNode->m_pRight =nullptr;
    pNode->m_nValue = value;
    return pNode;
}


void ConnectTreeNode(BianryTreeNode *pParent,BianryTreeNode * pLeft, BianryTreeNode* pRight){
    if(pParent!=nullptr){
        pParent->m_pLeft=pLeft;
        pParent->m_pRight=pRight;

        if(pLeft!=nullptr){
            pLeft->m_pParent =pParent;
        }
        if(pRight != nullptr){
            pRight->m_pParent=pParent;
        }
    }
}


void RrintTreeNode (BianryTreeNode *pNode ){
    if(pNode != nullptr){
        printf("value of this node is :%d\n",pNode->m_nValue);
        if(pNode->m_pLeft!=nullptr){
            printf("Value of the right node is :%d\n",pNode->m_pLeft->m_nValue);
        }else{
            printf("left childe is null \n");
        }
        if(pNode->m_pRight!=nullptr){
            printf("Value of the left node is :%d\n",pNode->m_pRight->m_nValue);
        }else
        {
            
            printf("right child us null \n");
        }
        

    }
    else{
        printf("This node is null .\n");
    }
}

void DestoryTree(BianryTreeNode *pRoot){
    if(pRoot !=nullptr){
        BianryTreeNode * pLeft = pRoot->m_pLeft;
        BianryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot =nullptr;
        DestoryTree(pLeft);
        DestoryTree(pRight);
    }
}

void Test(char* testName, BianryTreeNode* pNode,BianryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BianryTreeNode* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1_7()
{
   BianryTreeNode* pNode8 = CreateBianryTreeNode(8);
    BianryTreeNode* pNode6 = CreateBianryTreeNode(6);
    BianryTreeNode* pNode10 = CreateBianryTreeNode(10);
    BianryTreeNode* pNode5 = CreateBianryTreeNode(5);
    BianryTreeNode* pNode7 = CreateBianryTreeNode(7);
    BianryTreeNode* pNode9 = CreateBianryTreeNode(9);
    BianryTreeNode* pNode11 = CreateBianryTreeNode(11);

    ConnectTreeNode(pNode8, pNode6, pNode10);
    ConnectTreeNode(pNode6, pNode5, pNode7);
    ConnectTreeNode(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

     DestoryTree(pNode8);
}

void Test8_11()
{
    BianryTreeNode* pNode5 = CreateBianryTreeNode(5);
    BianryTreeNode* pNode4 = CreateBianryTreeNode(4);
    BianryTreeNode* pNode3 = CreateBianryTreeNode(3);
    BianryTreeNode* pNode2 = CreateBianryTreeNode(2);

    ConnectTreeNode(pNode5, pNode4, nullptr);
    ConnectTreeNode(pNode4, pNode3, nullptr);
    ConnectTreeNode(pNode3, pNode2, nullptr);

    Test("Test8", pNode5, nullptr);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

   DestoryTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BianryTreeNode* pNode2 = CreateBianryTreeNode(2);
    BianryTreeNode* pNode3 = CreateBianryTreeNode(3);
    BianryTreeNode* pNode4 = CreateBianryTreeNode(4);
    BianryTreeNode* pNode5 = CreateBianryTreeNode(5);

    ConnectTreeNode(pNode2, nullptr, pNode3);
    ConnectTreeNode(pNode3, nullptr, pNode4);
    ConnectTreeNode(pNode4, nullptr, pNode5);

    Test("Test12", pNode5, nullptr);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

   DestoryTree(pNode2);
}

void Test16()
{
    BianryTreeNode* pNode5 = CreateBianryTreeNode(5);

    Test("Test16", pNode5, nullptr);

   DestoryTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
    system("pause");
    return 0;
}
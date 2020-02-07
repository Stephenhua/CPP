#include <cstdio>
#include "BinaryTreeNode.h"
#include <queue>

void print(BinaryTreeNode*pNode){
    if(pNode==nullptr){
        return ;
    }

    std::queue<BinaryTreeNode*> nodes;
    nodes.push_back(pNode);
    while(nodes.size()){

        BinaryTreeNode *Node= nodes.top();
        nodes.pop();
        printf("%d",Node->m_nValue);

        if(pNode->m_pLeft){
            nodes.push(pNode->m_pLeft);
        }else if(pNode->m_pRight){
            nodes.push(pNode->m_pRight);
        }
    }
}

void Test(char *testName, BinaryTreeNode* pRoot){
    if(testName!=nullptr){
        printf("%s begins:\n",testName);
    }

    print(pRoot);
    printf("The nodes from top to bottom ,from left to right are:\n");
    PrintTree(pRoot);
    printf("\n\n");
}


void Test1(){

    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);

}

void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}


void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
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

   return 0;
}

// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。
void Prin2(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr){
        return ;
    }

    std::queue<BinaryTreeNode*>nodes;
    nodes.push(pRoot);
    int nextLevel=0;
    int toNeprinted=1;
    while(nodes.size()){
        BinaryTreeNode* Node=nodes.front();
        printf("%d",Node->m_nValue);
        if(Node->m_pLeft){
            Node.push_back(Node->m_pLeft);
            ++nextLevel;
        }
        if(Node->m_pRight){
            Node.push_back(Node->m_pRight);
            ++nextLevel;
        }
        nodes.pop();
        --toNeprinted;
        if(toNeprinted==0){
            printf("\n");
            toNeprinted=nextLevel;
            nextLevel=0;
        }
    }
}


void Test1(){
    BinaryTreeNode* pNode8 =CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode9= CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode10=CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode11=CreateBinaryTreeNode(11);
    BinaryTreeNode* pNode12=CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode13=CreateBinaryTreeNode(13);
    BinaryTreeNode* pNode14=CreateBinaryTreeNode(14);
    ConnectTreeNodes(pNode8,pNode9,pNode10);
    ConnectTreeNodes(pNode9,pNode11,pNode12);
    ConnectTreeNodes(pNode10,pNode13,pNode14);
    printf("====Test1 Begins: ====\n");d
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("910 \n");
    printf("11 12 13 14 \n\n");

    printf("Actual Result is: \n");
    Print(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    Print(nullptr);
    printf("\n");
}

//        100
//        /
//       50   
//         \
//         150
void Test6()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    Print(pNode100);
    printf("\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}


void Print3(BinaryTreeNode* pNode1){

    if(pNode1==nullptr){
        return ;
    }

    std::stack<BinaryTreeNode*> level[2];
    int current=0;
    int next=1;
    level[current].push(pNode1);
    
    while(!level[current]||!level[next]){
        BinaryTreeNode* pNode = level[current].top();
        level[current].pop();
        printf("d",node->m_nValue);

        if(current==0){
            if(pNode->m_pLeft){
                level[next].push_back(pNode->m_pLeft);
            }
            else if(pNode->m_pRight){
                level[next].push_back(pNode->m_pRight);
            }
        }else{
            if(pNode->m_pRight!=nullptr){
                level[next].push_back(pNode->m_pRight);
            }else{
                level[next].push_back(pNode->m_pLeft);
            }
        }

        if(level[current].empty()){
            printf("\n");
            current=1-current;
            next=1-next;
        }
    }
}
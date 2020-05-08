#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
using namespace std;

/*
题目：二叉树的深度
*/
//采用递归的形式进行求解；
int TreeDepth( BinaryTreeNode* pRoot){

    if( pRoot == nullptr){
        return 0 ;
    }

    int left = TreeDepth( pRoot->m_pLeft);

    int right = TreeDepth( pRoot->m_pRight);

    return (left>right)?(left+1):(right+1);

}

int TreeDepth1( BinaryTreeNode* pRoot){
    if(pRoot == nullptr){
        return 0 ;
    }

    queue<BinaryTreeNode*> TreeStack;
    int depth = 0 ;
    TreeStack.push(pRoot);
    while( !TreeStack.empty()){

        depth++;
        int size = TreeStack.size();
        
        while( size--){
            BinaryTreeNode* pRoot = TreeStack.front();
            TreeStack.pop();
            if( pRoot->m_pLeft !=nullptr){
                TreeStack.push( pRoot->m_pLeft);
            }

            if(pRoot->m_pRight != nullptr ){
                TreeStack.push( pRoot->m_pRight);
            }
        }
    }

    return depth;

}


// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot, int expected)
{
    int result = TreeDepth1(pRoot);
    if(expected == result)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, nullptr, pNode6);
    ConnectTreeNodes(pNode5, pNode7, nullptr);

    Test("Test1", pNode1, 4);

    DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);

    Test("Test2", pNode1, 5);

    DestroyTree(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
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

    Test("Test3", pNode1, 5);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr, 0);
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

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

//采用递归的形式，后序遍历的形式进行求解；
bool ifBalanceTreeCore(const BinaryTreeNode* pRoot, int *depth){

    if( pRoot == nullptr){

        *depth = 0;
        return true;

    }

    int left ,right ;

    if( ifBalanceTreeCore(pRoot->m_pLeft ,&left) && ifBalanceTreeCore(pRoot->m_pRight, &right)){

        int diff = left- right;

        if( diff>=-1 && diff<=1){

            *depth =1+(left >right ? left:right);

            return true;
        }
    }
    return false;

}
bool ifBalanceTree(const BinaryTreeNode * pRoot){

    if(pRoot == nullptr){
        return true;
    }

    int depth = 0 ;

    return ifBalanceTreeCore( pRoot ,&depth);    
}




//方法二：

int TreeDepth(const BinaryTreeNode * pRoot){
    if(pRoot == nullptr){
        return 0;
    }

    int nLeft=TreeDepth(pRoot->m_pLeft);
    int nRight= TreeDepth(pRoot->m_pRight);

    return (nLeft>nRight)?(nLeft+1):(nRight+1);
}

bool IsBalanceTree2(const BinaryTreeNode* pRoot){
    if(pRoot==nullptr){
        return true;
    }

    int left=TreeDepth(pRoot->m_pLeft);
    int right=TreeDepth(pRoot->m_pRight);
    int diff =left-right;
    if(diff>1 ||diff< -1){

        return false;

    }

    return IsBalanceTree2(pRoot->m_pLeft)&& IsBalanceTree2(pRoot->m_pRight);
}


//方法三:递归的形式

bool isBalanced3( BinaryTreeNode *root){
    return height(root)!=-1;
}


int height( BinaryTreeNode* root){
    if(root == nullptr){
        return 0;
    }

    int left = height(root->m_pLeft);
    int right = height(root->m_pRight);

    if( left == -1 || right == -1 ||abs(left-right)>1){
        return -1;
    }
    return 1+max(left,right);
}
// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if(ifBalanceTree(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if(IsBalanceTree2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
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
    ConnectTreeNodes(pNode3, pNode6, pNode7);

    Test("Test1", pNode1, true);

    DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
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

    Test("Test2", pNode1, true);

    DestroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         
//      4  5        
//        /
//       6
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, pNode6, nullptr);

    Test("Test3", pNode1, false);

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
void Test4()
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

    Test("Test4", pNode1, false);

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
void Test5()
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

    Test("Test5", pNode1, false);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test6", pNode1, true);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test7()
{
    Test("Test7", nullptr, true);
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

    system("pause");
    return 0;
}
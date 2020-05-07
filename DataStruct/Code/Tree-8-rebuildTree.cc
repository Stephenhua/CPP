#include "BinaryTreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

/*
题目：已知前序和中序的数组，求二叉树
*/
BinaryTreeNode* ConstructCore(int* startPreorder ,int * endPreorder ,int * startInorder, int* endInorder ){

    //前序遍历第一个是根节点；
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue ;
    root->m_pLeft = root->m_pRight = nullptr ;

    if( startPreorder == endPreorder){

        if( startInorder == endInorder && *startPreorder == *startInorder){
            return root;
        }else{
            cout <<"invaild Input"<<endl;
        }
    }

    //在中序中寻找根节点；

    int* rootInorder = startInorder;

    while( rootInorder <= endInorder && *rootInorder !=rootValue){
        ++rootInorder;
    } 

    if(rootInorder == endInorder && *rootInorder !=rootValue){
        cout<<"Invalid Input"<<endl;
    }

    int leftLength = rootInorder - startInorder;
    int*leftPreoferEnd = startPreorder +leftLength;

    if(leftLength >0){
        root->m_pLeft = ConstructCore( startPreorder+1, leftPreoferEnd, startInorder,rootInorder-1);
    }

    if( leftLength < endPreorder - startPreorder){

        root->m_pRight = ConstructCore( leftPreoferEnd+1 ,endPreorder , rootInorder+1, endInorder);
    }

    return root;

}
BinaryTreeNode* Construct( int* perorder ,int * Inorder ,int length){

    if( perorder ==nullptr || Inorder == nullptr || length <0 ){
        return nullptr;
    }

    return ConstructCore( perorder,perorder+length-1 ,Inorder,Inorder+length-1);
}

// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, const int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

#include "BinaryTreeNode.h"
#include <exception>
#include <cstdio>
#include <iostream>
using namespace std;

BinaryTreeNode* ContructCore(int * startPreorder, int *endPreorder, int * startInorder ,int *endInorder);

BinaryTreeNode * Construct(int *preorder ,int * inorder , int length){
    if(preorder==nullptr || inorder == nullptr|| length<0){
        return nullptr;
    }
    return ContructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode*  ContructCore(int* startPreorder, int * endPreorder,int * startInorder ,int *endInorder){
    //前序便利的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode *root =new BinaryTreeNode();
    root->m_pLeft=root->m_pRight=nullptr;
    root->m_nValue=rootValue;
    if(startPreorder==endPreorder){
        if(startInorder==endInorder&&*startPreorder==*endPreorder){
            return root;
        }else{
            throw std::exception("Invalid input");
        }
    }


    //中序找到根节点的值
    int * rootInorder =startInorder;
    while(rootInorder <=endInorder&& *rootInorder!=rootValue){
        ++rootInorder;
    }
    if(rootInorder==endInorder && *rootInorder !=rootValue){
        throw std::exception("Invalid input");
    }

    int leftLength=rootInorder-startInorder;
    int *leftPreorder = startPreorder+leftLength;
    if(leftLength>0){
        root->m_pLeft=ContructCore(startPreorder+1,leftPreorder,startInorder,rootInorder-1);
    }
    if(leftLength<endPreorder-startPreorder){
        root->m_pRight=ContructCore(leftPreorder+1,endPreorder,rootInorder+1,endInorder);
    }

    root;

}

void Test(char* testName, int* preorder, int* inorder, int length)
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
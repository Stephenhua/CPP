#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "BinaryTreeNode.h"
using namespace std;
/*
题目：在二叉搜索树中，查找距离两个节点最近的父节点；

*/

int leastParentNode1(BinaryTreeNode* root,int n1,int n2){
    
    if(root==nullptr || root->m_nValue==n1 || root->m_nValue==n2){
        return -1;
    }
    if(root->m_pLeft !=nullptr &&(root->m_pLeft->m_nValue==n1 || root->m_pLeft->m_nValue==n2)){
        return root->m_nValue;
    }

    if(root->m_pRight !=nullptr &&(root->m_pRight->m_nValue==n1 || root->m_pRight->m_nValue==n2)){
        return root->m_nValue;
    }

    if(root->m_nValue >n1 && root->m_nValue<n2){
        return root->m_nValue;
    }
    if(root->m_pLeft!=nullptr){
        return leastParentNode1(root->m_pLeft,n1,n2);
    }

    if(root->m_pRight!=nullptr){
        return leastParentNode1(root->m_pRight,n1,n2);
    }

}

//方法二：
    BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode* q) {
        
        while(root){
            if( root->m_nValue > p->m_nValue && root->m_nValue > q->m_nValue){
                root = root->m_pLeft;
            }else if( root->m_nValue < p->m_nValue && root->m_nValue <q->m_nValue){
                root = root->m_pRight;
            }else{
                return root;
            }
        }
        return NULL;
    }

//采用迭代的方法进行求解

int leastParentNode(BinaryTreeNode* root,int n1,int n2){
    if(root==nullptr){
        return -1;
    }

    int min,max;
    if(n1>n2){
        min=n2;
        max=n1;
    }else{
        max=n2;
        min=n1;
    }

    while(root){
        if(root->m_nValue >=min && root->m_nValue<=max){
            return root->m_nValue;
        }else if(root->m_nValue>=min && root->m_nValue >=max){
            
             root = root->m_pLeft;

        }else{

            root=root->m_pRight;

        }
    }

}


//==============测试代码======================

void Test(char* testName ,int cur ,int expected){
    if(testName!=nullptr){
        cout<<testName<<endl;
    }

       cout<<"Result"<<cur<<endl;

    if (cur == expected){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22

void test1(){
    BinaryTreeNode* pNode10=CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12=CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7=CreateBinaryTreeNode(7);

    int result=leastParentNode1(pNode10,4,12);

    printf("Two path should be found in Test1.\n");
    Test("Test1",result,10);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void test2(){

    BinaryTreeNode* pNode10=CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12=CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7=CreateBinaryTreeNode(7);

    int result=leastParentNode1( pNode10,4,5);
 

    printf("Two path should be found in Test1.\n");
    Test("Test1",result,5);

    DestroyTree(pNode10);


}


//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// 有一条路径上面的结点和为15

void test3(){

    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3=CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2=CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1=CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5,pNode4,nullptr);
    ConnectTreeNodes(pNode4,pNode3,nullptr);
    ConnectTreeNodes(pNode3,pNode2,nullptr);
    ConnectTreeNodes(pNode2,pNode1,nullptr);

    int result=leastParentNode1(pNode5,1,2);

    printf("Two path should be found in Test1.\n");
    Test("Test1",result,3);

     DestroyTree(pNode5);
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
// 没有路径上面的结点和为16
// 树中只有1个结点


void test5(){

    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);


    ConnectTreeNodes(pNode5,nullptr,nullptr);

    int result=leastParentNode1(pNode5,1,2);

    printf("Two path should be found in Test1.\n");
    Test("Test1",result,-1);

     DestroyTree(pNode5);
}

int main (int argc ,char *argv[]){
    test1();
    test2();
    test3();
    //test4();
    test5();
    //test6();
    system("pause");
    return 0;
}

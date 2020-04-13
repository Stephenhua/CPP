#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

/*
题目：判断是否为搜索二叉树

*/

BinaryTreeNode* IsSearchTree(BinaryTreeNode* pRoot){
    if(pRoot == nullptr){
        return true;
    }

    return IsSearchTreeCore( root ,LONG_MIN,LONG_MIN);
}

bool IsSearchTreeCore(BinaryTreeNode* pRoot ,long max, log min){

    if(root == nullptr){
         return  true;
    }

    if( pRoot->m_pLeft <= min ||pRoot->m_pRight >= max){
        
        return false;
    }

    return IsSearchTreeCore(pRoot->m_pLeft, min , pRoot->m_nValue) && IsSearchTreeCore(pRoot->m_pRight,pRoot->m_nValue, max);
}


//方法二：中序遍历，存入数组中，那么空间复杂度由O(1)变为O(n)

bool isVaildBST(BinaryTreeNode* pRoot){
    if(!pRoot){
        return true;
    }

    vector<int> vals;
    inorder(pRoot,vals);

    for(int i=0;i<vals.size()-1;i++){

        if(vals[i]>vals[i+1]){
            return false ;
        }
    }
    return true;
}

void inorder(BinaryTreeNode* pRoot,vector<int>& vals){
    if(!pRoot){
        return ;
    }

    inorder(pRoot->m_pLeft);

    vals.push_back(pRoot->m_nValue);

    inorder(pRoot->m_pRight);
}

//方法三：每当遍历到一个新节点时和其上一个节点比较，如果不大于上一个节点那么则返回 false，
//全部遍历完成后返回 true。


bool isVaildBST_3(BinaryTreeNode* pRoot){l
    BinaryTreeNode* pre =nullptr;

    return isVaildBST_3Core(pRoot,pre);
}

bool isVailedBST_3Core(BinaryTreeNode* pRoot ,BinaryTreeNode* pre){
    if(!pRoot){
        return true;
    }

    bool left = isVailedBST_3Core(pRoot->m_pLeft, pre);

    if(!left ){
        return false;
    }

    if(pre){
        if(pRoot->m_pRight <= pre->m_nValue){
            return false;
        }
    }
    pre = pRoot;
    
    return isVailedBST_3Core(pRoot->m_pRight, pre);
}

//方法四：采用非递归的形式进行求解；

bool isValidBST_Core4(BinaryTreeNode* root){

    stack<BinaryTreeNode*> s = new stack<BinaryTreeNode*>();

    BinaryTreeNode* p=root;
    BinaryTreeNode* pre = nullptr;

    while( p!=nullptr || !s.empty){
        while(p!=nullptr){
            s.push(p);
            p=p->m_pLeft;
        }

        p= s.top();
        if(pre!=nullptr && p->m_nValue <= pre->m_nValue){
            return false;
        }

        pre = p;//将前一个节点标注为当前节点；

        p = p->m_pRight;

    }

    return true；
    
}

//方法四：采用递归的形式进行判断

bool isVaild_Core5(BinaryTreeNode* root){

    if(root == nullptr){
        return true;
    }

    if(!isVaild_Core5(root->m_pLeft)){
        return false;
    }

    if(!isVaild_Core5(root->m_pRight)){
        return false; 
    }

    BinaryTreeNode* cur = root->m_pLeft;

    if(cur != nullptr){
        
        while( cur->m_pRight != nullptr){
            cur = cur->m_pRight;
        }

        if(root->m_nValue < cur->m_nValue){
            return false;
        }
    }


    BinaryTreeNode* cur = root->m_pRight;

    if(cur != nullptr){
        
        while(cur->m_pLeft != nullptr ){
            cur = cur->m_pLeft;
        }

        if( root->m_pLeft > cur->m_nValue ){
            return false;
        }
    }

    return true;
}

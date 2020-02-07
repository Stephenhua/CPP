#include <cstdio>

struct BinaryTreeNode{
    double m_value;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pLeft;
};

bool equal(double num1,double num2);
bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
    bool result=false;
    if(pRoot1!=nullptr && pRoot2!=nullptr){
        if(equal(pRoot1->m_value,pRoot2->m_value)){
            result= DoesTreeHaveTree(pRoot1,pRoot2);
        }
        if(!result){
            result= HasSubtree(pRoot1->m_pLeft,pRoot2);
        }
        if(!result){
            result= HasSubtree(pRoot1->m_pRight,pRoot2);
        }
    }

    return result;
}
bool DoesTreeHaveTree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
    if(pRoot2==nullptr){
        return true;
    }
    if(pRoot1==nullptr){
        return false;
    }

    if(!equal(pRoot1->m_value,pRoot2->m_value)){
        return false;
    }
    return DoesTreeHaveTree(pRoot1->m_pLeft,pRoot2->m_pLeft)&&DoesTreeHaveTree(pRoot1->m_pRight,pRoot2->m_pRight);
}

bool equal(double num1,double num2){
    if((num1-num2>-0.00000001)&&(num1-num2<0.000000001))
    {
        return true;
    }else{
        return false;
    }
}

BinaryTreeNode* CreateBinaryTreeNode(double dbValue){
    BinaryTreeNode* pNode =new BinaryTreeNode();
    pNode->m_value=dbValue;
    pNode->m_pLeft=nullptr;
    pNode->m_pRight=nullptr;
    return pNode;
}
void ConnectTreeNodes(BinaryTreeNode*pParent,BinaryTreeNode*pLeft,BinaryTreeNode *pRight){
    if(pParent!=nullptr){
        pParent->m_pLeft=pLeft;
        pParent->m_pRight=pRight;
    }
}

void DestoryTree(BinaryTreeNode* pRoot){
    if(pRoot!=nullptr){
        BinaryTreeNode*pLeft =pRoot->m_pLeft;
        BinaryTreeNode*pRight=pRoot->m_pRight;
        delete pRoot;
        pRoot=nullptr;
        DestoryTree(pLeft);
        DestoryTree(pRight);
    }
}

void Test(char *testName , BinaryTreeNode *pRoot1, BinaryTreeNode* pRoot2, bool expected){
    if(HasSubtree(pRoot1,pRoot2)==expected){
        printf("%s passed .\n",testName);
    }else{
        printf("%s failed.\n",testName);
    }
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7


// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7



// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5


// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5


// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                   \
//           9                   2
//            \      
//             2        
//              \
//               5


// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                 / \
//           9               3   2
//            \      
//             2        
//              \
//               5


// 树A为空树

// 树B为空树

// 树A和树B都为空
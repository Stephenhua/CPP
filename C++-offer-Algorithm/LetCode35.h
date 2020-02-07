
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include "BinaryTreeNode.h"

using namespace std;
struct ComplexListNode
    {
         int                 m_nValue;
         ComplexListNode*    m_pNext;
         ComplexListNode*    m_pSibling;
    };

class ComplexList{
    public :

    ComplexListNode* CreateNode(int nValue);
    void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
    void PrintList(ComplexListNode* pHead);

};
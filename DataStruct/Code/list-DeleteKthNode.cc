#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <stack>
#include <cmath>
#include "string.h"
#include "list.h"
using namespace std;


/*
题目描述
在单链表中删除倒数第 K 个节点

要求
如果链表的长度为 N, 时间复杂度达到 O(N), 额外空间复杂度达到 O(1)

解答
删除的时候会出现三种情况：

1、不存在倒数第 K 个节点，此时不用删除

2、倒数第 K 个节点就是第一个节点

3、倒数第 K 个节点在第一个节点之后

所以我们可以用一个变量 sum 记录链表一共有多少个节点。

如果 num < K，则属于第一种情况。

如果 num == K，则属于第二中情况。

如果 num > K, 则属于第三种情况，此时删除倒数第 K 个节点等价于删除第 (num - k + 1) 个节点。

*/

ListNode* FindKthNode(ListNode* pHead,int k){
    if( pHead==nullptr || k<0){
        return nullptr;
    }

    ListNode* currNode = pHead;
    ListNode* pBehind = nullptr;

    for(int i=0;i<k;i++){
        if(currNode->m_pNext!=nullptr){
            currNode = currNode->m_pNext;
        }else{
            return nullptr;
        }
    }

    pBehind = pHead;

    while(pBehind!=nullptr && currNode!=nullptr){

        pBehind = pBehind->m_pNext;
        currNode = currNode->m_pNext;

    }
    
    return pBehind;
}
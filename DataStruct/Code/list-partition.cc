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

【题目描述】
给定一个单向链表的头结点head,节点的值类型是整型，再给定一个整数privot。
实现一个调整链表的函数，将链表调整为左部分都是值小于privot的节点，
中间部分都是值等于privot的节点，右部分都是大于privot的节点。且对某部分内部节点的顺序不做要求

例如:链表9-0-4-5-1，pivot=3。

调整后是1-0-4-9-5，

也可以是0-1-9-5-4

【要求】
如果链表的长度为 N, 时间复杂度达到 O(N)。

【解答】
这道题在思路上还是比较简单的，但是在实现上还是有一些细节需要主要的。

本题对某部分的内部节点不做要求，一种很简单的方法就是用一个数组来存链表的节点，
然后像类似于快速排序的分割函数那样，按照某个值把他们进行划分。

不过这样做的话，空间复杂度为 O(N)。我们也可以采取使用3个指针，
把原链表依次划分成三个部分的链表，然后再把他们合并起来，这种做法不但空间复杂度为 O(1), 
而且内部节点的顺序也是和原链表一样的。虽然思路简单，但在代码实现上也是有很多细节需要注意的，
有时间的话希望大家动手打下码。

*/

ListNode* listPartition(ListNode* head, int pivot){
    ListNode* sB =nullptr;
    ListNode* sE = nullptr;

    ListNode* eB = nullptr;
    ListNode* eE = nullptr;

    ListNode* bB = nullptr;
    ListNode* bE = nullptr;

    ListNode* next = nullptr;//保存下一个节点；

    while(head != nullptr){
        next= head->m_pNext;

        head->m_pNext = nullptr;

        if(head->m_nValue < pivot){
            
            if( sB == nullptr){
                sB =head;
                sE =head;
            }else{
                sE->m_pNext = head;
                sE = sE->m_pNext;
            }
        }
        else if( head->m_nValue == pivot){
            if( eB ==nullptr){
                eB = head;
                eE = head;
            }else{
                eE->m_pNext = head;
                eE =eE->m_pNext;
            }
        }
        else{
            if( bB == nullptr ){
                bB = head;
                bE = head;
            }else{
                bE->m_pNext = head;
                bE->m_pNext = bE ;
            }
        }

        //把三部分串连起来，串联的时候细节还是挺多的，
        //串联的过程下面代码的精简程度是最学习的部分了

        if(sB != nullptr ){
            sE->m_pNext = eB;
            eE=eE==nullptr? sE :eE;
        }

        if( eB != nullptr){
            eE->m_pNext = bB;
        }

        return sB !=nullptr ? sB:eB!=nullptr ? eB :bB;

    }
}
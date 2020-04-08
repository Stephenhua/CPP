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
问题拓展
题目：删除链表中 a / b 处的节点

【题目描述】
给定链表的头节点 head、整数 a 和 b，实现删除位于 a/b 处节点的函数。

例如：

链表：1->2->3->4->5，假设 a/b 的值为 r。

如果 r = 0，不删除任何节点；

如果 r 在区间 (0,1/5] 上，删除节点 1；

如果 r 在区间 (1/5,2/5] 上，删除节点 2；

如果 r 在区间 (2/5,3/5] 上，删除节点 3；

如果 r 在区间 (3/5,4/5] 上，删除节点 4；

如果 r 在区间 (4/5,1] 上，删除节点 5；

如果 r 大于 1，不删除任何节点。

【要求】
如果链表的长度为 N, 时间复杂度达到 O(N), 额外空间复杂度达到 O(1)


思路：
    这道题可以转换为删除第 K = (a * n / b)个节点。其中n表示链表节点
    的个数，但由于(a * n / b)有可能出现小数，所以我们取 K的上限。
    所谓上限就是大于等于K的最小整数。
*/

ListNode* removeByRatio(ListNode* head, int a, int b){
    if(a<1 || a>b){
        return head;
    }
    int count =0 ;
    ListNode* currNode = head;

    while(currNode!=nullptr){
        count++;
    }

    int k=ceil((double)(a*n)/(double)b);

    if(k==1){
        return head->m_pNext;
    }else{
        currNode= head;
        while(--k!=1){
            currNode = currNode->m_pNext;
        }
        currNode->m_pNext = currNode->m_pNext->m_pNext;
    }
    return head;
}

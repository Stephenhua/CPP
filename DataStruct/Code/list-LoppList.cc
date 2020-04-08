#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include "string.h"
#include "list.h"
using namespace std;

/*
输入：一个环形单向链表的头节点 head 和报数 m.

返回：最后生存下来的节点，且这个节点自己组成环形单向链表，其他节点都删除掉。

*/

//方法一：直接使用循环的形式，时间复杂度为O（n*m）

ListNode* JoseSkiplist(ListNode* pHead, int m){
    if(pHead == nullptr || m<0){
        return pHead;
    }

    ListNode* last =pHead;

    while(pHead->m_pNext != last){
        pHead=pHead->m_pNext;
    }

    int count =0 ;
    while(pHead->m_pNext!=pHead){
        if(++count == m){
            pHead->m_pNext=pHead->m_pNext->m_pNext;
            count = 0;
        }else{
            pHead = pHead->m_pNext;
        }
    }
    return pHead;
}

//方法二：采用迭代的方式求解，时间复复杂度为O(n)；直接利用递归求解出编号即可；
/*
我们可以给环形链表的节点编号，如果链表的节点数为 n, 则从头节点开始，依次给节点编号，即头节点为 1， 下一个节点为2， 最后一个节点为 n.

我们用 f(n) 表示当环形链表的长度为n时，生存下来的人的编号为 f(n)，显然当 n = 1 时，f(n) = 1。假如我们能够找出 f(n) 和 f(n-1) 之间的关系的话，我们我们就可以用递归的方式来解决了。我们假设 人员数为 n, 报数到 m 的人就自杀。则刚开始的编号为

…

m - 2

m - 1

m

m + 1

m + 2

…

进行了一次删除之后，删除了编号为m的节点。删除之后，就只剩下 n - 1 个节点了，删除前和删除之后的编号转换关系为：

删除前     ---     删除后

…   ---   …

m - 2     ---     n - 2

m - 1    ---      n - 1

m         ----    无(因为编号被删除了)

m + 1     ---     1(因为下次就从这里报数了)

m + 2     ----     2

…         ----         …

新的环中只有 n - 1 个节点。且编号为 m + 1, m + 2, m + 3 的节点成了新环中编号为 1， 2， 3 的节点。

假设 old 为删除之前的节点编号， new 为删除了一个节点之后的编号，则 old 与 new 之间的关系为 old = (new + m - 1) % n + 1。

注：有些人可能会疑惑为什么不是 old = (new + m ) % n 呢？主要是因为编号是从 1 开始的，而不是从 0 开始的。如果 new + m == n的话，会导致最后的计算结果为 old = 0。所以 old = (new + m - 1) % n + 1.

这样，我们就得出 f(n) 与 f(n - 1)之间的关系了，而 f(1) = 1.所以我们可以采用递归的方式来做。


*/

ListNode* JoseSkiplist2(ListNode* head, int m){
    if(head==nullptr || m<1){
        return head;
    }

    //统计一共有多少个节点；
    int n=1;
    ListNode* last=head;

    while(last->m_pNext!= head){
        n++;
        last=last->m_pNext;
    }

    //直接递归进行计算编号；
    int des = f(n,m);

    //把目的节点取出来
    while(--des!=0){
        head=head->m_pNext;
    }

    head->m_pNext= head;
    return head; 
}

int f(int n,int m){
    if(n==1){
        return 1;
    }
    return (f(n-1,m)+m-1)%n+1;
}
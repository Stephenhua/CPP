#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(nullptr){}
};

/*
92. 反转链表 II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

*/
/*
链表反转递归解释：https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/

反转整个链表：
*/
ListNode* reverseNode( ListNode* head){
    if( head->next == nullptr ){
        return head;
    }

    ListNode* last = reverseNode(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}


//反转链表前n个节点：
ListNode* successor = nullptr; // 后驱节点
ListNode* reverseN(ListNode* head, int n){

    if( n == 1){
        successor = head->next;//记录后驱节点；
        return head;
    }

    ListNode* last = reverseN( head->next,n-1);
    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
}


class Solution {
public:

    ListNode* successor = nullptr; // 后驱节点
    ListNode* reverseN(ListNode* head, int n){

        if( n == 1){
            successor = head->next;//记录后驱节点；
            return head;
        }

        ListNode* last = reverseN( head->next,n-1);
        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if( m == 1 ){
            return reverseN(head,n);
        }
        head->next = reverseBetween(head->next , m-1 ,n-1);
        return head;
    }
};

//迭代法进行求解；

/*
1）首先找到第m个节点，然后找到pre_node;
2)进行反转链表，然后知道节点n时，结束，此时反转节点得列表；
3）然后进行补齐即可；
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if( head == nullptr ){
            return head;
        }

        if( n-m == 0 ){
            return head;
        }

        int count = 1 ;

        ListNode* pre = m == 1? nullptr: head;
        ListNode* prev_befrore_reverse = nullptr ;

        while( count < m ){
            prev_befrore_reverse = head;
            head = head->next ;
            count++;
        }

        //翻转链表；
        ListNode* prev = head;
        ListNode* revse_head = nullptr;
        ListNode* tail = head;

        int reverse_node_num = n - m ;

        while( reverse_node_num >= 0 ){

            ListNode* temp = prev ;
            prev = prev->next;
            temp->next = revse_head;
            revse_head = temp ;
            reverse_node_num--;
        }
        //翻转之后，的链表进行相连；
        if( tail != prev ){
            tail->next = prev;
        }
        //考虑末尾的情况，需要考虑两种；
        if( pre != nullptr ){
            prev_befrore_reverse->next = revse_head;
        }else{
            pre = revse_head;//此时表示整个链表都进行翻转，将头结点赋值给pre;
        }
        return pre;

    }

};
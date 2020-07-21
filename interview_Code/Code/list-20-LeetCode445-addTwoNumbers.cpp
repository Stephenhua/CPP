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
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  /*
445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7


  */

/*
头插法创建链表：
1）----设立一个链表节点dummy->next;
2)-----每次新增的节点都喝dummy->next进行相互连接；
3）-----然后更新dummy的next节点，

最后dummy->next之后的节点就是更新后的节点；

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if( !l1 || !l2 ){
            return l1==NULL?l2:l1;//处理存在NULL的情况；
        }

        //根据链表构建两个栈；

        stack<int>s1,s2;
        while( l1 != nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while( l2 != nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }

        //根据两个栈计算数值并建表；

        int carry = 0 ;
        int n1 = 0;
        int n2 = 0 ;
        int sum = 0 ;

        ListNode* newNode = new ListNode(-1);//创建头结点；
        ListNode* temp = nullptr;

        while( !s1.empty() || !s2.empty() ||carry){

            if( s1.empty()){
                n1 = 0;
            }else{
                n1 = s1.top();
                s1.pop();
            }

            if( s2.empty()){
                n2 = 0 ;
            }else{
                n2 = s2.top();
                s2.pop();
            }

            sum = n1+n2+carry;

            //头插法创建链表；
            temp = new ListNode(sum%10);
            temp->next = newNode->next;
            newNode->next = temp;

            carry = sum/10;
        }

        ListNode* res = newNode->next;
        delete newNode;
        return res;
    }
};
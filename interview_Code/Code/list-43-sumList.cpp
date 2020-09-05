#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
面试题 02.05. 链表求和
给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。

 

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：假设这些数位是正向存放的，请再做一遍。

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
通过次数12,763提交次数27,890
https://leetcode-cn.com/problems/sum-lists-lcci/
*/


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    if(l1 == nullptr || l2== nullptr){
        return l1==nullptr?l2:l1;
    }

    queue<int> s1,s2;

    while(l1 != nullptr){
        s1.push(l1->val);
        l1 = l1->next;
    }

    while(l2 != nullptr){
        s2.push(l2->val);
        l2 = l2->next;
    }

    //进行求和；
    int carr = 0 ;
    int n1 = 0 ;
    int n2 = 0;
    int sum = 0;

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = nullptr;
    ListNode* p =dummy;

    while( !s1.empty() || !s2.empty() || carr){

        if(s1.empty() == 0 ){
            n1 = 0 ;
        }else{
            n1 = s1.front();
            s1.pop();
        }

        if(s2.empty() == 0){
            n2 = 0 ;
        }else{
            n2 =s2.front();
            s2.pop();
        }


        sum = n1+n2+carr;
        temp = new ListNode(sum%10);
        p->next = temp;
        p = p->next;
        carr = sum/10;
    }
    return dummy->next;


}


//方法二：
ListNode* addTwoNUm(ListNode* l1 ,ListNode* l2){
        if( l1 == nullptr ){
            return l2;
        }
        if( l2 == nullptr){
            return l1 ;
        }
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }

        ListNode* sumNode = new ListNode(-1);
        ListNode* cur =nullptr;
        sumNode->next = cur;

        int jinwei = 0 ;
        int sum = 0 ;
        //两个都
        while( l1 != nullptr ||  l2 != nullptr || jinwei){
            sum = 0 ;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 ){
                sum += l2->val;
                l2 = l2->next;
            }

            sum +=jinwei;
            jinwei = sum /10 ;
            int yushu = sum%10;

            ListNode* curNode  = new ListNode(yushu);

            cur->next = curNode;
            cur = cur->next;
        }

        return sumNode->next; 
}
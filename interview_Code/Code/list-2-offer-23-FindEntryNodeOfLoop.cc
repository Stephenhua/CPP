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

/*
链表中环的节点入口；
*/

/*
思路：
1）通过快慢指针确定是否存在环；
2）找过快慢指针找出节点入口；

*/

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//确定是否有环；
  ListNode* ListLoop( ListNode* head){
      if( head == nullptr){
          return nullptr;
      }

      if( head->next == nullptr){
          return nullptr;
      }
      ListNode* pSlow = head->next;
      ListNode* pFast = pSlow->next;

      while (pSlow !=nullptr && pFast!= nullptr)
      {

          if( pSlow == pFast){
              return pSlow;
          }

          pSlow = pSlow->next;
          pFast = pFast->next;

          if( pFast->next != nullptr){
              pFast = pFast->next;
          }
          
      }

      return nullptr;      
  }


//找出节点的入口；

ListNode* EntryNodeOfLoop( ListNode* pHead){
    ListNode* meetingNode = ListLoop(pHead);

    if( meetingNode == nullptr ){
        return nullptr;
    }

    ListNode* temp = meetingNode;
    int node= 1 ;
    while( temp->next != meetingNode){

        temp = temp->next;
        node++;
    }

    temp = pHead;

    while (node > 0)
    {
        temp = temp->next;
        /* code */
    }

    //向前移动到node个节点；
    ListNode* Node2 = pHead;

    while( Node2 != temp){
        temp =temp->next;
        Node2 = Node2->next;
    }

    return  temp;;    
}

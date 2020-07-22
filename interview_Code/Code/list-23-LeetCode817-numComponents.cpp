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
817. 链表组件
给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

 

示例 1：

输入: 
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释: 
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
示例 2：

输入: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
输出: 2
解释: 
链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
 

提示：

如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000
G 是链表中所有结点的值的一个子集.
  */

/*
方法一：
1）通过map统计G中的数值；
2）遍历节点链表，然后通过map进行查找，并用flag作为前面的节点的标志位，如果前面的节点在列表中，那么表明节点是连续的；
否则，节点是不相互连续的；
3）判断组件个个数，就是判断链表中连续的节点的个数；

*/
class Solution {
    public:
        int numComponents(ListNode* head, vector<int>& G) {
            unordered_map<int,int> umap;
            for(int i = 0 ;i < G.size() ;i++){
                umap[G[i]] =1;
            }

            int flag = 0;
            int num = 0 ;
            ListNode* iter = head;
            while( iter){
                if( umap.find(iter->val) != umap.end() && flag == 0){
                    flag = 1;
                    num++;
                }else if( umap.find(iter->val) == umap.end() && flag == 1){
                    flag = 0 ;
                }
                iter = iter->next;
            }
            return num;
        }
};
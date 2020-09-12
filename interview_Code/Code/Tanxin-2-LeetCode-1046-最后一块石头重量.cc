#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*

1046. 最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000

*/


/*
比较好理解的一种方法,排序,始终用第一个减去第二个,然后第二个变为0
假如 2 6 4 9
排序后 9 6 4 2
第一次循环(-6) 0 3 4 2,然后排序4 3 2 0
第二次循环 (-3) 1 0 2 0,排序 2 1 0 0
第三次循环(-1) 1 0 0 0,然后第一个就是了

作者：lkk19891020
链接：https://leetcode-cn.com/problems/last-stone-weight/solution/zui-jian-dan-de-li-jie-fang-fa-by-lkk19891020/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        if(stones.size() <= 1 ){
            return stones[0];
        }

        sort(stones.begin(),stones.end(),greater<int>());

        int len = stones.size();

        while( len-- ){
            stones[0] = stones[0]- stones[1];
            stones[0] = 0;

            sort(stones.begin(),stones.end(),greater<int>());
        }

        return stones[0];
    }
};

//采用优先队列进行求解；
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        if(stones.empty() ){
            return 0;
        }
        //最大堆，堆顶大于两个子孩子；
        priority_queue<int ,vector<int>,less<int>> queue;

        for( auto & stone : stones){
            queue.push(stone);
        }

        while( queue.size() >= 2){

            int s1 = queue.top();
            queue.pop();
            int s2 = queue.top();
            queue.pop();
            int val = s1 -s2;
            if( val > 0 ){
                queue.push(val);
            }
        }

        if(queue.empty()){
            return 0 ;
        }
        return queue.top();

    }
};
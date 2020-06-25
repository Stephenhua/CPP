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
128. 最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


*/

/*
采用hash表进行求解，
1）找到一个可以作为期待你的数字，计算在它开头的最长连续子序列，如果比记录的子序列还要长，那么久更新当前的子序列；

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>  st;

        for( int n : nums){
            st.insert(n);
        }

        int res = 0 ;

        for( int  i : st){
            //判断当前状态是不是第一个连续数字，如果依旧存在比他小的数，那么需要直接跳过；
            if( i != INT_MIN && st.count(i-1)){
                continue;
            }

            int cnt = 1 ;
            //从最小的开始遍历，知道不连续的时候直接停止；
            while( i != INT_MIN && st.count(i+1)){
                cnt++;
                i++;
            }
            res = max( res, cnt);

        }

        return res;

    }
};

//方法二：采用并查集的方式进行
/*
1)-将连续的数字作为一个集合
2)-那么扫描到一个数字，只要将它和它的下一个数字（假如存在）merge在一个集合即可。同时更新这个集合的元素个数
3)-如果当前经过merge的集合的元素个数比当前记录的最长序列的长度都长，则更新当前最长记录
https://blog.csdn.net/The_best_man/article/details/62418823?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
*/

class Solution {
public:
    unordered_map<int,int> uf ,cnt ;//uf用于存储当前状态的根节点；，cnt表示其的子节点个数；

    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ){
            return 0;
        }

        for( int num :nums){
            uf[num] = num;
            cnt[num] = 1;
        }

        int res = 1 ;

        for( int num : nums){
            if( num != INT_MAX && uf.count(num+1)){

                res = max( res, merge( num ,num+1));
            }
        }
        return res;
    }

    int merge( int num ,int next_num){
        int x = find( num);
        int y = find(next_num );

        if( x == y ){
            return cnt[x];
        }

        uf[next_num] = x;

        cnt[x] += cnt[y];
        
        return cnt[x];
    }

    int find( int num){
        return num == uf[num] ? num : uf[num] = find(uf[num]);//找到根节点；
    }

};
//方法三：
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 0) return res;
        unordered_set<int> allnum(nums.begin(), nums.end());
        for(auto n:nums)
        {
            //判断是不是最小的值；不是得话直接跳出去；
            if(allnum.find(n-1) != allnum.end()) continue;
            int cur = 0;
            //此时已经是最小值，用于查找下一个连续值；

            for(int i=n; i<INT_MAX; i++)
            {
                if(allnum.find(i)==allnum.end()) break;
                cur++;
            }
            //找到的话，那么直接进行返回操作；
            
            res = max(res, cur);
        }
        return res;
    }
};
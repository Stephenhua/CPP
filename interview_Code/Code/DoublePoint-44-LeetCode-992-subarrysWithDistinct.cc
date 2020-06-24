#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
992. K 个不同整数的子数组
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

 

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
通过次数4,103提交次数14,317

*/

/*
思想：滑动窗口进行解决；


*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        if( n== 0 ||  K== 0){
            return 0;
        }

        int left = 0 ;
        int right = 0;
        int res =0 ;


        unordered_map<int,int> windows;

        while( right < n){
            windows[A[right++]]++;
            //窗口溢出，需缩小窗口
            while( windows.size() > K ){
                if( windows[A[left]] > 1){
                    windows[A[left]]--;
                }else{
                    windows.erase(A[left]);
                }

                left++;
            }

            //当window的size等于k时，也就是window内有k个不同的整数，
            int temp = left;
            //用来求必须以A[right]结尾的子数组满足题目条件的个数，对left不会产生影响。
            while( windows.size() == K){
                res++;
                if( windows[A[temp]]> 1){
                    windows[A[temp]]--;
                }else{
                    windows.erase(A[temp]);
                }
                temp++;
            }
            //还原子数组
            while( temp > left){
                windows[A[temp-1]]++;
                temp--;
            }
        }
        return res;
    }
};
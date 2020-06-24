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
1248. 统计「优美子数组」
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

 

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16
 

提示：

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

*/
//方法二：

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> count(nums.size()+1, 0);
        count[0] = 1;
        int rs = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] & 1);
            if (sum >= k) {
                rs += count[sum-k];
            }

            count[sum] ++;
        }
        return rs;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int  size= nums.size();
        if( size == 0){
            return 0 ;
        }

        int left = 0 ;
        int right = 0 ;
        int res = 0 ;
        int oddcount = 0;

        while( right < size){
         // 右指针先走，每遇到一个奇数则 oddCnt++。
            if( (nums[right] & 1) == 1){
                oddcount++;
            }

            //  若当前滑动窗口 [left, right) 中有 k 个奇数了，进入此分支统计当前滑动窗口中的优美子数组个数。

            if( oddcount == k){
                // 先将滑动窗口的右边界向右拓展，直到遇到下一个奇数（或出界）
                // rightEvenCnt 即为第 k 个奇数右边的偶数的个数

                int temp = right;

                while( right < nums.size() &&(nums[right] &1) == 0){
                    right++;
                }
                // leftEvenCnt 即为第 1 个奇数左边的偶数的个数
                int rightEvent = right -temp;
                int leftEvent = 0;
                // 第 1 个奇数左边的 leftEvenCnt 个偶数都可以作为优美子数组的起点
                // (因为第1个奇数左边可以1个偶数都不取，所以起点的选择有 leftEvenCnt + 1 种）
                // 第 k 个奇数右边的 rightEvenCnt 个偶数都可以作为优美子数组的终点
                // (因为第k个奇数右边可以1个偶数都不取，所以终点的选择有 rightEvenCnt + 1 种）
                // 所以该滑动窗口中，优美子数组左右起点的选择组合数为 (leftEvenCnt + 1) * (rightEvenCnt + 1)

                while( (nums[left]&1) == 0){
                    leftEvent++;
                    left++;
                }
                // 此时 left 指向的是第 1 个奇数，因为该区间已经统计完了，因此 left 右移一位，oddCnt--
                res += (leftEvent +1)*(rightEvent+1);
                left++;
                oddcount--;
            }
        }
        return res;
    }
};
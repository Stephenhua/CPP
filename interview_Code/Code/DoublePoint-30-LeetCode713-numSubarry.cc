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
713. 乘积小于K的子数组
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:

0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6

*/
/*
滑动窗口：
1）何时缩小窗口，sum 》k 的时候；
2）数组内乘积小于 k 的连续的子数组的个数=上一个窗口的子数组个数+包含新元素的子数组个数f（n）=n+f（n-1）
其中f（n）是当前满足要求的滑动窗口；f（n-1）是上一个满足要求的滑动窗口；
n是包含在f（n）的新增的元素下，新增的子数组 n=r-l+1；
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0 ;

        int size = nums.size();
        int res = 0 ;
        int temp = 1;

        while( right < size){
            temp *=nums[right];//如果变为right++，那么后面就不需要加一；
            while( temp >= k && right > left){
                temp /= nums[left++];
            }
            res +=right- left+1;
            right++;
        }
        return res;
    }
};

//方法二：
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int sum = 1;
        int res = 0;
        while(j<nums.size()){
            sum*=nums[j++];//进行乘积相乘；
            if(sum < k){//如果sum < k ，则直接当进行相加；窗口不变化；
                res+=(j-i);
            }else{//窗口发生变化；需要缩小窗口，然后继续进行相加；
                while(i<j && sum>=k){
                    sum/=nums[i++];
                }
                res+=(j-i);
            }
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;

/*
作者：星__尘
链接：https://www.nowcoder.com/discuss/428158
来源：牛客网

排序数组，平方后，数组当中有多少不同的数字（相同算一个）。
如果不是排序数组，可以使用hashset来保存数字的平方，重复就存不进去，那么最后就可以直接返回set的大小size即可。时间空间复杂度都是O（n)。
双指针遍历：这里是排序数组，既然有重复，肯定是有负数，0,1这些数字。平方后两头大，中间小，可以用首尾指针共同向中间扫描，扫描时去掉重复元素，同时用一个sum来记录有多少个不同数字。
时间复杂度O(N)，空间复杂度O(1)。

*/


 class Solution {
     int diffSquareNum(vector<int> nums) {
         int res = 0 ;
        int size = nums.size();
        int left = 0 ;
        int right = size -1 ;

        while( left <= right){
            if( nums[left] + nums[right] ==0){
                res++ ;
                int temp =nums[left];
                
                while( left <= right && nums[left] == temp){
                    left++;
                }

                while( left <= right && nums[right] == temp){
                    right--;
                }

            }else if( nums[left] + nums[right] < 0 ){
                res++;
                int temp =nums[left];
                while( left <= right &&  nums[left] == temp){
                    left++;
                }
            }else {
                res++;
                int temp = nums[right];
                while( left <= right && nums[right] == temp){
                    right--;
                }
            }
        }

        return res;
    }

};
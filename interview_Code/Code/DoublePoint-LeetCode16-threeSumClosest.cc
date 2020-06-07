#include  <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;


/*16. 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

//方法：采用双指针法进行求解；

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort( nums.begin() ,nums.end());

        int size = nums.size();

        int res  = nums[0] + nums[1] +nums[2];

        for( int i= 0 ;i < size ;i++){
            int start = i+1 ;
            int end = size -1 ;

            while( start <end){

                int sum = nums[i] + nums[start] +nums[end];
                if( abs(res-target) > abs(sum -target)){
                    res = sum ;
                }
                
                if( sum < target){
                    start++;
                }else if( sum > target){
                    end--;
                }else{
                     return sum ;
                }
            }
        }
        return res;
    }
};
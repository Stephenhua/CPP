#include  <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

/*
标签：数组遍历
首先对数组进行排序，排序后固定一个数 nums[i]nums[i]，再使用左右指针指向 nums[i]nums[i]后面的两端，数字分别为 nums[L]nums[L] 和 nums[R]nums[R]，计算三个数的和 sumsum 判断是否满足为 00，满足则添加进结果集
如果 nums[i]nums[i]大于 00，则三数之和必然无法等于 00，结束循环
如果 nums[i]nums[i] == nums[i-1]nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
当 sumsum == 00 时，nums[L]nums[L] == nums[L+1]nums[L+1] 则会导致结果重复，应该跳过，L++L++
当 sumsum == 00 时，nums[R]nums[R] == nums[R-1]nums[R−1] 则会导致结果重复，应该跳过，R--R−−
时间复杂度：O(n^2)O(n 
2
 )，nn 为数组长度

作者：guanpengchn
链接：https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp;

        int size = nums.size();

        if( size < 3){
            return res;
        }

        sort(nums.begin() ,nums.end());

        for( int i = 0 ;i <size ;i++){

            if( nums[i] > 0){
                break;
            }
             
            if( i>0 && nums[i] == nums[i-1])//去重；
            {
                continue;
            }

            int start = i + 1;
            int end = size -1 ;

            while( start < end){
                
                int sum = nums[i] +nums[start] +nums[end];
                
                if( sum == 0){
                    
                    temp = {nums[i],nums[start],nums[end]};

                    res.push_back( temp);

                    //进行去重；
                    while( start < end && nums[start] == nums[start+1]){
                        start++;
                    }
                    while( start < end && nums[end] == nums[end-1]){
                        end--;
                    }
                    start++;
                    end--;

                }else if( sum < 0 ){

                    start++;

                }else if( sum > 0 ){

                    end--;
                }

            }
        }

        return res;
    }
};
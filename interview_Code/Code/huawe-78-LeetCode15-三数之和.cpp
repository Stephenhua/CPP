#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp;

        int size = nums.size();

        if( size < 3 ){
            return res;
        }

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < size; i++ ){
            if( nums[i] > 0 ){
                break;
            }

            if( i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int start = i + 1;
            int end = size - 1 ;

            while( start  <  end ){
                int sum = nums[i] + nums[start] + nums[end];

                if( sum > 0 ){
                    end--;
                }else if( sum < 0 ){
                    start++;
                }else{
                    temp = { nums[i], nums[start] , nums[end] };
                    res.push_back(temp);
                    //去重；
                    while( start < end && nums[start] == nums[start+1] ){
                        start++;
                    }

                    while( start < end && nums[end] == nums[end-1] ){
                        end--;
                    }
                    start++;
                    end--;
                }
            }
        }

    }

};
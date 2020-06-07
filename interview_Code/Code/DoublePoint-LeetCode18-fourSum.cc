#include  <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

/*
18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/


//方法：双指针 +减枝运算；

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res ;

        int size = nums.size();

        if( size < 4){
            return res;
        }

        sort( nums.begin() ,nums.end());

        for( int a = 0 ;a < size-3 ;a++){

            if( target <= 0 && nums[a] > 0){
                break;
            }
            if( nums[a]+nums[a+1]+nums[a+2]+nums[a+3] >target){
                break;
            }

            if( nums[a] +nums[size-1]+nums[size-2]+nums[size-3] < target){
                continue;
            }

            if( a > 0 && nums[a] == nums[a-1]){
                continue;
            }

            for( int b = a+1 ; b < size- 2 ;b++){

                if( nums[a]+nums[b]+nums[b+2]+nums[b+1] >target){
                    break;
                }

                if( nums[a] +nums[size-1]+nums[size-2]+nums[b] < target){
                    continue;
                }  

                if( b > a+1 && nums[b] == nums[b-1]){
                    continue;
                }

                int c = b+1 , d = size -1;

                while( c < d ){

                    int  sum = nums[a] + nums[b] + nums[c] +nums[d];

                    if( sum == target){

                        res.push_back({ nums[a],nums[b],nums[c],nums[d]});

                        while( c < d && nums[c] == nums[c+1]){
                            c++;
                        }

                        while( c < d && nums[d] == nums[d-1]){
                            d--;
                        }
                        c++;
                        d--;

                    }else if( sum > target){

                        d--;

                    }else if(sum < target ){

                        c++;
                    }
                }
            }
        }

        return res;
    }
};
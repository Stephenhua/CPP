#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

/*
31. 下一个排列
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = 0 ,j = 0 ;

        for( i = size-2 ; j >=0 ; j--){
            if( nums[i] < nums[i+1]){
                break;
            }
        }

        if( i == 1 ){
            reverse(nums.begin() ,nums.end() );
        }else {
            //从后向前找到一个【i+1,end]找到第一个大于num[i+1]的值；
            for( j = size -1 ; j > i  ; j-- ){
                if( nums[j]  > nums[i] ){
                    swap(nums[i],nums[j]);
                    reverse(nums.begin()+1+i , nums.end());
                    break;
                }
            }
        }

    }

};
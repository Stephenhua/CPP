#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：寻找峰值；只要返回一个就可以

时间复杂度：O(longn)
首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，
那么沿着它一定可以找到一个峰值
根据上述结论，我们就可以使用二分查找找到峰值
查找时，左指针 l，右指针 r，以其保持左右顺序为循环条件
根据左右指针计算中间位置 m，并比较 m 与 m+1 的值，如果 m 较大，则左侧存在峰值，r = m，
如果 m + 1 较大，则右侧存在峰值，l = m + 1
*/

//方法一：
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(right+left)/2;
            if(nums[mid]>nums[mid+1]){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;       
        
    }
};

//方法二进行求解；
/*
1.如果数组是严格递增或者严格递减，峰值在len(nums)-1或者0处；如果nums[0]比nums[1]大，nums[0]即是峰值;如果nums[len(nums)-1]比nums[len(nums)-2]大，nums[len(nums)-1]即是峰值
2.排除1的情况，数组中间一定存在一个峰值，采用二分法判断峰值在那一边一定存在
3.如果mid对应的数值比mid-1和mid+1处的数值都大，mid即使要找的结果
4.如果mid对应的数值比mid-1小，那么区间[l,mid]一定有峰值
5.如果mid对应的数值比mid+1小，那么区间[mid,r]一定有峰值
*/

class Solutions2{

    public:
        int findPeakValue(vector<int>&nums){
            int lenght=nums.size();
            if(nums.size()==1){
                return 0;
            }
            if(nums[0]>nums[1){
                return 0;
            }

            if(nums[lenght-1]>nums[lenght-2]){
                return lenght-1;
            }

            int left=0,right=lenght-1;
            return find(nums,left,right);
        }

        int find(vector<int>& nums, int left ,int right,){
            int mid=(left+right)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]>nums[mid]){
                return mid;
            }
            if(nums[mid-1]>nums[mid]){
                return find(nums,left,mid);
            }else{
                return find(nums,mid,right);
            }
        }

};
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
/*
题目：假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

解题思路：
二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，
我们观察上面红色加粗的数字都是升序的，由此我们可以观察出规律，
如果中间的数小于最右边的数，则右半段是有序的，
若中间数大于最右边数，则左半段是有序的，
我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了

时间复杂度：o(log n);

如果采用遍历的话，时间复杂度为O(n)
*/
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return false;
        }

        int length=nums.size();
        int left=0,right=length-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]<nums[right]){
                if(nums[mid]<target && nums[right]>=target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else{
                if(nums[left]<=target && nums[mid]>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
        }

        return false;        
    }
};
//上述算法的缺点在于不能够排除重复数字，如果遇到重复输的话，则就无法进行判断；


//方法二：采用二分搜索进行判断，考虑遇到重复的数字该如何进行处理；

using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return false;
        }

        int length=nums.size();
        int left=0,right=length-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[left]==nums[mid]){
                left++;
                continue;
            }

            //前部分有序
            if(nums[left]<nums[mid]){
                //target在前半部分；
                if(nums[mid]>target && nums[left]<=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                //后半部分有序，target在后半部分；
                if(nums[mid]<target && nums[right]>=target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
                    
            }
        }

        return false;        
    }
};

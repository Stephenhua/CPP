#include <vector>
#include <iostream>
#include <string>

using namespace std;

int left_bound(vector<int>& arr ,int target){
    
    int left  = 0;
    int right = arr.size()-1;

    while (left <= right)
    {
        int mid = left + (right - left)/2;

        if( nums[mid] < target){
            left = mid+1;
        }else if( nums[mid] > target){
            right = mid -1 ;
        }else if( nums[mid] == target){
            right = mid -1 ;
        }
        /* code */
    }

    //检查出界情况
    if( left >= nums.size() || nums[left] != target){
        return -1;
    }

    return left ;    
}

int right_bound( vector<int>& nums, int target){

    int left = 0 ;
    int right  = arr.size();

    while (left <right)
    {
        int mid = left +(right-left)/2;

        if( nums[mid] >target){
            right = mid;
        }else if( nums[mid] < target){
            left =mid+1;
        }else if(nums[mid] ==target){
            left =mid + 1;
        }
    }

    if( right == 0 ){
        return -1;
    }

    return nums[right -1] == target ?(left -1):(-1);
}

vector<int> FindBound(vector<int>& nums,int target){
    int left = left_bound(nums,target);
    int right = right_bound( nums,target);

    return {left,right};
}

#include <vector>
#include <iostream>
#include <algorithm>


//寻找右侧边界的二分查找

int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {

        int mid = (left + right) / 2;

        if (nums[mid] == target) {

            left = mid + 1; // 注意

        } else if (nums[mid] < target) {

            left = mid + 1;

        } else if (nums[mid] > target) {

            right = mid;

        }
    }
    if( right == 0 ){
        return -1;
    }

    return nums[right -1] == target ?(left -1):(-1);
}

//方法二：有等号的时候应该这么做；

int right_bound2( vector<int>& nums ,int target){

    if( nums.size() == 0){
        return -1;
    }

    int left = 0 ;
    int right = nums.size()-1;

    while( left <=right){

        int mid = left + (mid- left)/2;
        if(nums[mid] < target){
            left =mid+ 1;
        }else if( nums[mid] > target){
            right = mid -1 ;
        }else if( nums[mid] == target){
            left = mid+1;
        }

    }

    if( right < 0 || nums[right] != target){
        return -1;
    }

    return right;
}
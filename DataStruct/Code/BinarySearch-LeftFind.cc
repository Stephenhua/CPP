#include <vector>
#include <iostream>
#include <string>

using namespace std;

//二分查找框架

int binarySearch（int[] nums, int target){
    int lfet=0,right=nums.length();
    while(...){
        int mid =left+(right-left)/2;

        if(nums[mid]==target){
            ...
        }else if(nums[mid]<target){
            lfet=..;
        }else if(nums[mid]>target)
        {
            right=...;
            /* code */
        }
        
    }
    return ...;
}

//二分查找非递归查找

int binarySearch_Solutions(int [] nums,int target){
    int low =0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }

        if(nums[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

//二分查找递归版本

int binarySearch_Solutions2(int nums[],int target,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(a[mid]==target){
        return mid;
    }else if(target>a[mid]){
        start=mid+1;
    }else if(target<a[mid]){
        end=mid-1;
    }
    return binarySearch_Solutions2(nums,target,start,end);
}

//https://www.cnblogs.com/kyoner/p/11080078.html
//寻找左侧边界的二分查找

int left_Search(int nums[],int target){

    if(nums.length()==0){
        return -1;
    }

    int left=0;

    int right=nums.size()-1;

    while(left<right){

        int mid=(left+mid)/2;

        if(nums[mid]==target){

            right=mid;

        }else if(nums[mid]<target){

            left=mid+1;

        }else if(nums[mid]>target){

            right = mid;

        }
    }

    if( left == nums.length){
        return -1 ;//表示没有找到；
    }

    return nums[left]== target ? left :-1;

}

//寻找左侧边界，方法二：

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


/*

第一个，最基本的二分查找算法：

因为我们初始化 right = nums.length - 1
所以决定了我们的「搜索区间」是 [left, right]
所以决定了 while (left <= right)
同时也决定了 left = mid+1 和 right = mid-1

因为我们只需找到一个 target 的索引即可
所以当 nums[mid] == target 时可以立即返回


第二个，寻找左侧边界的二分查找：

因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid+1 和 right = mid

因为我们需找到 target 的最左侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧右侧边界以锁定左侧边界



第三个，寻找右侧边界的二分查找：

因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid+1 和 right = mid

因为我们需找到 target 的最右侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧左侧边界以锁定右侧边界

又因为收紧左侧边界时必须 left = mid + 1
所以最后无论返回 left 还是 right，必须减一


*/
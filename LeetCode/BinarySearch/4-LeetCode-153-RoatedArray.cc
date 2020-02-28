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
题目：寻找旋转排列数组中的最小值；
解题思路：
采用二分法的形式进行求解；

1）找到元素中间的点；
2）如果中间元素》数组第一个元素；需要在mid中右边搜索变化点；
3）如果中间元素《数组的第一个元素；需要在mid的左边进行搜索变化点；
4）当找到变化点时，则停止搜索，
a———num[mid]>nums[mid+1];
b---num[mid-1]>nums[mid];
mid是最小值；
https://www.cnblogs.com/Osea/p/11182221.html

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }

        int left=0,right=nums.size()-1;

        if(nums[right]>nums[0]){
            return nums[0];
        }

        while(right>=left){
            int mid =left+(right-left)/2;

            if(nums[mid]>nums[mid+1]){
                return mid+1;
            }
            if(nums[mid-1]>nums[mid]){
                return mid;
            }

            if(nums[mid]>nums[0]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;

        
    }
};

//方法二：采用图示法更容易理解；
class Solution {
public:
    int findMin(vector<int>& nums) {
        if ( nums[0] < nums.back() ) return nums[0] ;
        int L = 0 , R = nums.size() -1 , Mid , ans = 0 ; 
        while ( L < R ){
            Mid = L+R >> 1 ; 
            if( nums[0] <= nums[Mid] ){
                ans = Mid ;
                L = Mid + 1 ;
            }else {
                R = Mid  ;
            }
        }
        return nums[L] ;
        
    }
};
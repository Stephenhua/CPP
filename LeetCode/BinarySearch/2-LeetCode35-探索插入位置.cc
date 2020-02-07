#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


//方法一：采用二分法的形式进行求解
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int Len=nums.size();
		if(Len==0){
			return 0;
		}

		//进行特别判断
		if(nums[Len-1]<target){
			return Len;
		}

		int left=0;
		int right=Len-1;
		while(left<right){
			int mid=left+(right-left)>>1;
			//严格小于target的元素不一定是解
			if(nums[mid]>target){
				left=mid+1;
			}else{
				right=mid;
			}
		}
		return left;
    }
};
/*
题目：两个数组的交集；
*/
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <algorithm>
using namespace std;


//采用排序加双指针的方法进行求解；
/*
时间复杂度：O(min(len1,len2))，
空间复杂度：O(2*min(num1,nums2))；
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int length=nums1.size();
        int length2=nums2.size();
        int p1=0;
        int p2=0;
        vector<int> temp;
        
        sort(nums1.begin(),nums2.end());
        sort(nums2.begin(),nums2.end());

        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<nums2[p2]){
                p1++;
            }else if(nums1[p1]>nums2[p2]){
                p2++;
            }else{
                temp.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        vector<int>::iterator new_end = unique(temp.begin(), temp.end());//只是将重复的数字放在了队尾，并没有进行删除
        temp.erase(new_end, temp.end());//直接将数字删除掉；
        return temp;
    }
};

//采用哈希表的形式进行进行求解；需要额外的存储空间；采用二分法去查找一个元素；
/*
时间复杂度：O(N * log N)O(N∗logN)，NN 为非待排序数组的元素个数。
空间复杂度：取决于交集的元素个数。

*/
class Solutions{
 public:
    bool binarySearch(vector<int>& nums,int left,int right,int target){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return true;
        }
        while(left<right){
            if(nums[mid]<target){
                return binarySearch(nums,mid+1,right,target);
            }
            if(nums[mid]>target){
                return binarySearch(nums,left,mid-1,target);
            }
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
        if(nums1.size()==0 || nums2.size()==0){
            return vector<int>();
        }

        unordered_map<int,int> result;
        bool found =false;
        sort(nums2.begin(),nums2.end());
        vector<int> result1;

        for(auto x:nums1){
            found=binarySearch(nums2,0,nums2.size(),x);
            if(found){
                ++result[x];
            }
        }
        for(auto x:result){
            result1.push_back(x.first);
        }

        return result1;
    }
};

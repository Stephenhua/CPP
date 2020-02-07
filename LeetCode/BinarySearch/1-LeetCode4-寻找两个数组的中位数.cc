#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthElm(vector<int>& num1,vector<int>& num2 ,int k){
        assert(1<=k&&(k<=num1.size()+num2.size()));
        int le=max(0,int(k-num2.size()));
        int ri=min(k,int(num1.size()));
        while(le<ri){
            int m=le+(ri-le)/2;
            if(num2[k-m-1]>num1[m]){
                le=m+1;
            }else{
                ri=m;
            }
        }
        //循环结束时的位置le即为所求位置，第k小即为max(nums1[le-1]),nums2[k-le-1])，但是由于le可以为0、k,所以
        //le-1或者k-le-1可能不存在所以下面单独判断下;
        int nums1LeftMax=le==0?INT_MIN:num1[le-1];
        int nums2RightMax=le==k?INT_MIN:num2[k-le-1];
        return max(nums1LeftMax,nums2RightMax);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        if(n&1){
            return findKthElm(nums1,nums2,(n>>1)+1);
        }else{
             return (findKthElm(nums1,nums2,n>>1)+findKthElm(nums1,nums2,(n>>1)+1))/2.0;
        }        
    }
};
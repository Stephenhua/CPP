/*
题目：两个数组的交集二；
*/
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <algorithm>
using namespace std;

//排序+双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int > result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0;
        int k=0;
        while(i<nums1.size() && k<nums2.size()){
            if(nums1[i]==nums2[k]){
                result.push_back(nums1[i]);
                i++;
                k++;
            }else if(nums1[i]>nums2[k]){
                k++;
            }else{
                i++;
            }
        }
        return result;
        
    }
};


//哈希表
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> temp;
        vector<int> result;

        for(int i=0;i<nums1.size();i++){
            temp[nums1[i]]+=1;
        }

        for(int k=0;k<nums2.size();k++){
            if(temp[nums2[k]]>0){
                result.push_back(nums2[k]);
                temp[nums2[k]]--;
            }
        }
        return result;
    }

};

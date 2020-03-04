/*
题目：寻找右区间；
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

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int length=intervals.size();
        unordered_map<int,int> startmap;
        vector<int> startarr(length,0);
        for(int i=0;i<length;i++){
            startmap[intervals[i][0]]=i;
            startarr[i]=intervals[i][0];
        }

        sort(startarr.begin(),startarr.end());
        
        vector<int> result(length,-1);
        for(int i=0;i<length;i++){
            int index=BinarySearch(startarr,intervals[i][1]);
            if(index<startarr.size()){
                result[i]=startmap[startarr[index]];
            }
        }

        return result;

    }

    int BinarySearch(vector<int>&arr ,int target){
        int start=0;
        int end=arr.size();
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                return mid;//返回序号值
            }
            else if(arr[mid]<target){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return start;
    }
};

//后面的方法没有弄懂；
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> op(intervals.size(), -1);
        
        int minValue = INT_MAX, maxValue = INT_MIN;
        for(int i = 0; i < intervals.size(); i++){
            minValue = min(intervals[i][0], minValue);
            maxValue = max(intervals[i][0], maxValue);
        }
        
        vector<int> st(maxValue-minValue + 1, -1);
        
        for (int i = 0; i < intervals.size(); i++){
            if (st[intervals[i][0] - minValue] == -1) st[intervals[i][0] - minValue] =  i;
        }
        
        for(int i = 0; i < intervals.size(); i++){
            if (intervals[i][1] > maxValue ) continue;
            for(int j = intervals[i][1] - minValue; j <= (maxValue - minValue); j++){
                if (st[j] != -1 && i != st[j]) {
                    op[i] = st[j]; break;
                }
            }
        }
        
        return op;
        
    }
};
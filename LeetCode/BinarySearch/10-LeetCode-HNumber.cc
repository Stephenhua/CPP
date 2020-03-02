/*
题目：H指数II
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

//采用方法：二分法进行求解,效率是最高的
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start=0;
        int size1=citations.size();
        int end =size1-1;
        if(size1==0){
            return 0;
        }

        while(start<=end){
           int  mid=(start+end)/2;
            if(size1-mid <citations[mid]){
                end=mid-1;
                
            }else if(size1-mid >citations[mid]){
                start=mid+1;
            }
            else{
                return size1-mid;
            }
        }
        return size1-start;
    }
};

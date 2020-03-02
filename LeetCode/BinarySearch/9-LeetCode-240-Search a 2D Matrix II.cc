/*
题目：寻找二维数组中的一个数
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int coloums=matrix[0].size();
        
         bool found =false;
         if(rows<1 || coloums <1 ){
             return false;
         }
        
            int row=0;
            int coloum=coloums-1;
            while(row<rows &&coloum>=0){
                if(matrix[row][coloum]==target){
                    found=true;
                    return found;
                }else if(matrix[row][coloum]>target){
                    --coloum;
                }else{
                    ++row;
                }
            }

        return found;
        
    }
};

//方法二：采用二分查找的方式进行求解；

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int coloums=matrix[0].size();
        
         bool found =false;
         if(rows<1 || coloums <1 ){
             return false;
         }
        for(int i=0;i<rows;i++){
            if(matrix[i][0]>target){
                break;
            }
            if(matrix[i][coloums-1]<target){
                break;
            }
            int col=binarySearch(matrix,target);
            if(col!=-1){
                return true;
            }
        }

        return found;
    }

    int binarySearch(vector<int>& nums, int target){
        int start=0;
        int end=nums.size();
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
};
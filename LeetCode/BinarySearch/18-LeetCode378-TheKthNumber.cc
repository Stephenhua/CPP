/*
题目：有序矩阵中dik小的元素；
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


//直接采用暴力法进行，其复杂度为O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<int> temp_queue;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                temp_queue.push(matrix[i][j]);
                if(temp_queue.size()>k){
                    temp_queue.pop();
                }
            }
        }
        return temp_queue.top();
    }
};

//采用二分法进行求解

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left =matrix[0][0];
        int right=matrix.back().back();
        while(left<right){
            int mid=(right+left)/2;
            int upToMid=0;
            for(int i=0;i<matrix.size();++i){
               upToMid+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();

            }
            if(upToMid <k){
                left=mid+1;
            }else{
                    right=mid;
                }

        }
            return left;
    }

};

//采用二分法进行求解，二分法主要针对的是数组中的值得问题，而不是序号的问题；

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0){
            return -1;
        }

        int row=matrix.size();
        int col=matrix[0].size();
        if(row*col<k){
            return -1;
        }
        int start=matrix[0][0];
        int end=matrix[row-1][col-1];
        int result=-1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(countSmaller(matrix,mid)>=k){//如果个数大于k值了，那么则直接进行左移，并且将数值范围限制在一个固定的范围内；
                end=mid-1;
                result=mid;
            }else{
                start=mid+1;
            }

        return result;
        }
    }
    //该函数返回的是小于中间值个数，
    int countSmaller(vector<vector<int>>& m, int n){
        int row=m.size()-1;
        int col=0;
        int count=0;
        while(row>=0 && col<m.size()){
            if(m[row][col]>n){//根据值得大小进行二分法
                row--;
            }else{
                count+=row+1;
                col++;
            }
        }
        return count;
    }

};
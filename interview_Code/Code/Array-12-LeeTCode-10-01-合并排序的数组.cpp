#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
面试题 10.01. 合并排序的数组
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1;
        int k = n + m -1;

        while ( i >=0 && j >= 0)
        {
            if( nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
        
        while( j >= 0 ){
            nums1[k--] = nums2[j--];
        }
        while( i >=0 ){
            nums1[k--]= nums1[i--];
        }
    }
};
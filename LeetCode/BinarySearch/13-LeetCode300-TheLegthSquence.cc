/*
题目：最长子序列
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

//动态规划；
/*
解题思路：
1)状态定义：

dp[i]dp[i] 的值代表 nums 前 ii 个数字的最长子序列长度。
转移方程： 设 j∈[0,i)j∈[0,i)，考虑每轮计算新 dp[i]dp[i] 时，遍历 [0,i)[0,i) 列表区间，做以下判断：

当 nums[i] > nums[j]nums[i]>nums[j] 时： nums[i]nums[i] 可以接在 nums[j]nums[j] 之后（此题要求严格递增），此情况下最长上升子序列长度为 dp[j] + 1dp[j]+1 ；
当 nums[i] <= nums[j]nums[i]<=nums[j] 时： nums[i]nums[i] 无法接在 nums[j]nums[j] 之后，此情况上升子序列不成立，跳过。
上述所有 1. 情况 下计算出的 dp[j] + 1dp[j]+1 的最大值，为直到 ii 的最长上升子序列长度（即 dp[i]dp[i] ）。实现方式为遍历 jj 时，每轮执行 dp[i] = max(dp[i], dp[j] + 1)dp[i]=max(dp[i],dp[j]+1)。
转移方程： dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)。

初始状态：
dp[i]dp[i] 所有元素置 11，含义是每个元素都至少可以单独成为子序列，此时长度都为 11。

返回值：
返回 dpdp 列表最大值，即可得到全局最长上升子序列长度。

复杂度分析：
1)时间复杂度 O(N^2)O(N 
2) ： 遍历计算 dpdp 列表需 O(N)O(N)，计算每个 dp[i]dp[i] 需 O(N)O(N)。
空间复杂度 O(N)O(N) ： dpdp 列表占用线性大小额外空间。

*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        int *dp=new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
        }
        int result=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                result=max(result,dp[i]);                
            }
        }
        return result;
    }
};

//方法二：采用动态规划+二分法进行求解；时间复杂度降为 nlong(n);

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = 0;
        vector<int> t(nums.size());
        for(int x:nums){
            int i = 0, j = sz;
            while(i!=j){
                int m = (i+j)/2;
                if(t[m]<x) i = m+1;
                else j = m;
            }
            t[i] = x;
            if(i==sz) sz++;
        }
        return sz;
        
    }
};

//采用lower_bound()函数进行求解，他里面用到的查找方法依旧是二分查找的方法进行求解；
class Solutions{
    public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.empty()){
            return 0;
        }

        int n=nums.size();
        vector<int> seq;
        seq.reserve(n);
        for(auto v:nums){
            auto it=lower_bound(seq.begin(),seq.end(),v);// 返回一个迭代器，指向键值>= key的第一个元素
            if(it==seq.end()){
                seq.push_back(v);
            }else{
                *it=v;
            }
        }
        return seq.size();
    }
};
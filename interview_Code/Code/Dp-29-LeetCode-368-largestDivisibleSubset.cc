#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
368. 最大整除子集
给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

 

示例 1:

输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)
示例 2:

输入: [1,2,4,8]
输出: [1,2,4,8]

*/

/*
动态规划：
1） 状态分析： dp[i] 表示以nums[i]结尾的最大的整除子集的长度；
                path[i] 表示 在最大序列中nums[i]的上一个元素在nums出现的下标，这样做的目的是构成一个形式上的链表，方便存储的时候使用；

2） 状态方程： dp[i] 和前面的子集挨个进行比较；if( num[i] %nums[j] == 0 ) dp[i] < dp[j+1]

3）初始状态：dp[i] = 1 (i:1 - n) 每一个只有自己的序列长度为1

4) 结果输出：


*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> dp(size,1),path(size,-1),res;

        int mx = 0;
        int end = -1;
        if( size == 0){
            return res;
        }

        sort( nums.begin() ,nums.end());

        for( int i = 0 ;i < size ;i++){
            for( int j = 0 ; j<i ;j++){
                if( nums[i] %nums[j] == 0 && dp[i] <=dp[j]){
                    dp[i] = dp[j]+1;//每个元素中存储的是上一个个数；
                    path[i] = j;//
                }
            }

            if(dp[i] > mx){
                mx = dp[i];//确定下标的个数
                end = i;//最后一个下标；
            }           
        }

        for( int i = end ;i != -1 ;i = path[i]){
            res.push_back(nums[i]);
        }
        return res;
    }
};
/*
题目:213 打家劫舍二
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

//采用动态规划的方法进行求解，由于多加了一个限制条件，就是1和2 只有一个存在的这中情况；

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }

        return max(Core(vector<int>(nums.begin(),nums.end()-1)),Core(vector<int>(nums.begin()+1,nums.end())));        
    }
    int Core(vector<int> nums){
        int pre=0,cur=0,temp;
        for(auto num:nums){//利用两个变量代替第n-1和n-2个最大金额，节省内存；
            temp=cur;
            cur=max(pre+num,cur);
            pre=temp;
        }
        return cur;
    }
};
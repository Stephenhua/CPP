/*
题目:198. 打家劫舍
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

//采用动态规划的方法进行求解
/*
动态规划方程：dp[n] = MAX( dp[n-1], dp[n-2] + num )
由于不可以在相邻的房屋闯入，所以在当前位置 n 房屋可盗窃的最大值，
要么就是 n-1 房屋可盗窃的最大值，要么就是 n-2 房屋可盗窃的最大值加上当前房屋的值，二者之间取最大值
举例来说：1 号房间可盗窃最大值为 33 即为 dp[1]=3，2 号房间可盗窃最大值为 44 即为 dp[2]=4，
3 号房间自身的值为 22 即为 num=2，那么 dp[3] = MAX( dp[2], dp[1] + num ) = MAX(4, 3+2) = 5，
3 号房间可盗窃最大值为 55
时间复杂度：O(n)O(n)，nn 为数组长度

*/
class Solution {
public:
    int rob( vector<int>& nums) {

        int length=nums.size();
        if(length==0){
            return 0;
        }else if(length==1){
            return nums[0];
        }
        else if(length==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(length,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<length;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[length-1];
    }
};
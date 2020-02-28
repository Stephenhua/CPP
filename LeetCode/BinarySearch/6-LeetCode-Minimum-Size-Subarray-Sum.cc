#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
/*
题目：
长度最小的子数组；
从第 0 个数字开始，依次添加数字，记录当总和大于等于 s 时的长度。

从第 1 个数字开始，依次添加数字，记录当总和大于等于 s 时的长度。

从第 2 个数字开始，依次添加数字，记录当总和大于等于 s 时的长度。

...

从最后个数字开始，依次添加数字，记录当总和大于等于 s 时的长度。

从上边得到的长度中选择最小的即可。

*/
//解法一：暴力破解；

//在确定最大值和最小值的时候，可以将值设置为最大值或者最小值，然后利用判断进行选择合适的值；

//时间复杂度O(n^2)；

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min1=INT_MAX;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int start=i;
            int sum=0;
            while(start<n){
                sum+=nums[start];

                start++;
                if(sum>=s){
                    min1=min(min1,start-i);
                    break;
                }
            }
        }
        //min 是否更新，如果没有更新说明数组所有的数字和小于 s, 没有满足条件的解, 返回 0
        return min1==INT_MAX?0:min1;
        
    }
};

//方法二：双指针
/*
用双指针 left 和 right 表示一个窗口。

right 向右移增大窗口，直到窗口内的数字和大于等于了 s。进行第 2 步。
记录此时的长度，left 向右移动，开始减少长度，每减少一次，就更新最小长度。直到当前窗口内的数字和小于了 s，回到第 1 步。

时间复杂度：O(N)；
*/

class Solutions{
    public:
    int minSubArrayLength(int s ,vector<int>& nums){
        int n=nums.size();
        if(n==0){
            return 0;
        }

        int left=0;
        int right =0;
        int sum=0;
        int minValue=INT_MAX;
        while(right<n){
            sum+=nums[right];
            right++;
            while(sum>s){
                minValue=min(minValue,right-left);
                sum-=nums[left];
                left++;
            }
        }
        return minValue==INT_MAX?0:minValue;

    }
};

//方法三：二分查找

/*
对于长度为 n 的数组，我们先去判断长度为 n/2 的连续数字中最大的和是否大于等于 s。

如果大于等于 s ，那么我们需要减少长度，继续判断所有长度为 n/4 的连续数字
如果小于 s，我们需要增加长度，我们继续判断所有长度为 (n/2 + n) / 2，也就是 3n/4 的连续数字。
*/

class Solutions_3{
    public:

    int getMaxValue(int len,vector<int>& nums){
        int n=nums.size();
        int sum=0;
        int maxSum=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
        }
        maxSum=sum ; //初始哈Sum;

        for(int i=len;i<n;i++){
            sum+=nums[i];
            //加一个减去一个，保持数组的长度不变；
            sum=sum-nums[i-len];
            //更新maxSum；
            maxSum=max(maxSum,sum);
        }
        return maxSum;

    }
    int minSubArrayLen(int s,vector<int>& nums){
        int n=nums.size();
        if(n==0){
            return 0;
        }

        int minLen=0;
        int maxLen=n;

        int midLen;
        int minValue=-1;
        while(minLen<=maxLen){
            midLen=(minLen+maxLen)/2;
            //判断当前的长度的最大和是不是大于等于S
            if(getMaxValue(midLen,nums)>=s){
                maxLen=midLen-1;
                minValue=midLen;
            }else{
                midLen=midLen+1;
            }
        }
        return minValue==-1?0:minValue;

    }
};
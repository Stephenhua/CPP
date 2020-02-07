#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
        int size=nums.size();
        vector<vector<int>> result;

        for(int a=0;a<size-3;++a){
            if(a>0&&nums[a]==nums[a-1]){
                continue;
            }
            for(int b=a+1;b<size-2;++b){
                if(b>a+1&&nums[b]==nums[b-1]){
                    continue;
                }
                int i=b+1;
                int j=size-1;
                while(i<j){
                    int sum=nums[a]+nums[b]+nums[i]+nums[j];
                    if(sum<target){
                        while(i<j&&nums[i]==nums[++i]);
                    }
                    else if(sum>target){
                        while(i<j&&nums[j]==nums[--j]);
                    }else{
                        result.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                        while(i<j&& nums[i]==nums[++i]);
                        while(i<j&& nums[j]==nums[--j]);
                    }
                }

            }
        }
        return result;
    }
};
//方法二：进行了剪枝操作
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector <vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;
        sort(nums.begin(),nums.end());
        // begin and end condition 
        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
                break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            // begin and end condition 
            for(int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) 
                    break;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                // looking for answer begin with nums[i] && nums[j]
                int front = j + 1, back = n - 1;
                while (front < back)
                {
                    int sum = nums[i] + nums[j] + nums[front] + nums[back];
                    if (sum < target)
                        ++front;//相比较原来更加方便，减少了不必要的开销
                    else if (sum > target)
                        --back;
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[front], nums[back]});
                        do ++front;
                        while (front < back && nums[front] == nums[front - 1]);
                        do --back;
                        while (front < back && nums[back] == nums[back + 1]);
                    }
                }
            }
        }
        return res;
    }
};
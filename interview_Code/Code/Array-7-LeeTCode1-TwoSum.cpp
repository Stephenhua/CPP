#include <iostream>
#include  <vector>
#include <unordered_map>
#include <map>
using namespace std ;

/*
1. 两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/

//方法一：暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0 ;i < nums.size();i++){
            for( int j = i+1 ;j <nums.size() ;j++){
                if( nums[i]+nums[j] == target){
                    nums.push_back(i);
                    nums.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

//方法二：对for循环进行更加准确的判断；
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0 ;i < nums.size();i++){
            for( int j = i+1 ;j <nums.size() ;j++){
                int sub = target-nums[i];

                if( sub== target){
                    nums.push_back(i);
                    nums.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
//方法三：通过hash判断；
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int >res; 
        unordered_map<int,int> key;

        for( int i = 0 ;i <nums.size() ;i++){
            int sub = target - nums[i];
            if( key[sub] && key[sub] != i+1){
                res.push_back(i);
                res.push_back( key[sub]-1);
                return res;
            }

            key[nums[i]] = i+1;
        }
        return res;
    }
};


//方法四：
class Solution {
public :
    vector<int > twoSum(vector<int>& nums,int target)
    {
        map<int,int> my_map;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(!my_map.count(nums[i]))
            {
                my_map.insert(pair<int,int>(nums[i],i));
                
            }
            if(my_map.count(target-nums[i]))
            {
                int n= my_map[target - nums[i]];
                if(n<i)
                {
                    result.push_back(i);
                    result.push_back(n);
                    return result;
                }
            }
        }
    }
    
} ;
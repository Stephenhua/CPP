#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;


//时间复杂度：O(N)，空间复杂度：O(N)；
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> counts;
        int N = nums.size();
        for(int i = 0 ; i< N ;i ++ ){
            ++counts[nums[i]];
        }

        for(int i = 0 ;i < N ;i++){
            if( counts[nums[i]] == 1 ){
                return nums[i];
            }
        }

        return nums[0];
    }

};

//排序遍历查找；
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();

        if( N == 1){
            return nums[0];
        }

        sort( nums.begin() , nums.end() );

        for(int i = 1 ; i < N-1 ; i++){
            if( nums[i] != nums[i-1] && nums[i] == nums[i+1]){
                return nums[i];
            }
        }

        if( nums[0] == nums[1]){
            return nums[0];
        }
        return nums[N-1];

    }

};
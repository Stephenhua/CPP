 #include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//解法一：采用一次遍历的形式进行，从而是空间复杂度降低
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }
        int i = 0, j = nums.size() - 1, mid = 0;
        while(mid <= j) {
            switch(nums[mid]) {
                case 0: 
                    swap(nums[i++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[j--], nums[mid]);
                    break;
            }
        }
    }
};

//解法二：同样遍历，但是时间将发生变化；
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left= 0;
        int right=nums.size()-1;
        int cur=0;
        while(cur<=right){
            if(nums[cur]==0){
                swap(nums[cur++],nums[left++]);
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[right--]);
            }else{
                ++cur;
            }
        }
        
    }
};
//解法一：采用双指针法进行
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            int minvalue=min(height[l],height[r]);
            int maxArea1=minvalue*(r-l);
            maxArea=max(maxArea,maxArea1);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};
//===========================================
//解法二：
//===========================================
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size() - 1;
        int curr = 0;
        while(left < right)
        {
            curr = max(curr, (right - left)*min(height[left],height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return curr;
    }
};
//===========================================
//解法三：
//===========================================
while(l<r)
{
    area = max(area,( min(height[l] , height[r]) * (r-l)) );
    height[l]<height[r]?l++:r--;
}
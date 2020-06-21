#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <queue>
#include <set>

using namespace std;

/*
349. 两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

*/

//方法一：用unordered_set进行实现；时间复杂度：O(m+n)，空间复杂度：o(m+n);


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> nums( nums1.begin() ,nums1.end());

        vector<int> res;

        for( auto num : nums2){
            if( nums.count( num)){
                res.push_back(num);
                nums.erase(num);
            }
        }
        return res;

    }
};

//方法二：双指针的方法实现；

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort( nums1.begin() ,nums1.end());
        sort( nums2.begin() ,nums2.end());

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int left1 = 0 ;
        int left2 = 0 ;
        set<int> s;

        while ( left1 < nums1_size && left2 <nums2_size)
        {
            if( nums1[left1] == nums2[left2]){
                s.insert( nums1[left1]);
                left1++;
                left2++;
            }else if( nums1[left1] > nums2[left2]){
                left2++;
            }else {
                left1++;
            }
            /* code */
        }
        
        vector<int> res( s.begin() ,s.end());
        return res;
        
    }
};

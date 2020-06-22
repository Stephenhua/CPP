#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

/*
方法一：二分查找法
通过比较中位分解求得；
时间复杂度：O(nLong n );
空间复杂度为： O(1);

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1 ;
        int right = nums.size() -1 ;

        while( left < right){

            int mid  = left +(right-left)/2 ;
            int cnt = 0 ;

            for( int num : nums){
                if( num <= mid ){
                    cnt++;
                }
            }

            if( cnt > mid ){
                // 重复的元素一定出现在 [left, mid] 区间里
                right = mid ;
            }else{
                // if 分析正确了以后，else 搜索的区间就是 if 的反面              
                left = mid+1;
            }
        }

        return right;
    }
};

/*
方法二：采用双指针法进行求解；
*/
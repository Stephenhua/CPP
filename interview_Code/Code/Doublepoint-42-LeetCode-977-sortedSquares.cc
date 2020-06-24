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
977. 有序数组的平方
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

*/

/*
方法：双指针的方法；
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left = 0 ;
        int right = A.size()-1 ;
        int size = A.size()-1;
        vector<int> res(A.size());

        while (size >= 0)
        {
            int value_left = A[left] * A[left];
            int value_right = A[right] * A[right];

            if( value_left > value_right){
                res[size] = value_left;
                left++;
            }else if( value_right >= value_left){
                res[size] = value_right;
                right--;
            }
            size--;           
        }
        return res;        

    }
};

//方法二：采用双指针法实现，同时进行了剪纸判断；，方法一的优化；
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::vector<int> res;
        int i = 0;
        int j = A.size() - 1;
        while(i<j) {
            if (abs(A[i]) < abs(A[j])) {
                res.push_back(A[j]*A[j]);
                j--;
            } else {
                res.push_back(A[i]*A[i]);
                i++;
            }
        }
        res.push_back(A[i]*A[i]);
        std::reverse(res.begin(), res.end());
        return res;
    }
};
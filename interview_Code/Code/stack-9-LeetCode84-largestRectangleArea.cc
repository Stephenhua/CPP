#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
using namespace std;

/*
题目：柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*单调栈的模板；
stack<int> st;
for(int i = 0 ;i<nums.size() ;I++){
    while( !st.empty() && st.top() > nums[i]){
        st.pop();
    }

    st.push(nums[i]);

}
*/


int largestRectangleArea(vector<int>& heights) {
    int  ans = 0;
    stack<int> res;
    heights.insert(heights.begin() , 0);
    heights.push_back(0);

    for(int i =0 ;i<heights.size() ;i++){

        while( !res.empty() && heights[res.top()] > heights[i] ){

            int cur = res.top();
            res.pop();
            int left = res.top() +1 ;
            int right = i-1;

            ans  = max( ans,(right-left+1)*heights[cur]);
        }
        res.push(i);
    }
    return ans;
}
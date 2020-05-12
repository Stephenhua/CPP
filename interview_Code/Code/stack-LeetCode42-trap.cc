#include <iostream>
#include <vector>
#include <map>
#include "BinaryTreeNode.h"
#include <stack>
using namespace std;

/*
题目：接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//方法一：采用单调栈的方法；

/*
使用栈来存储条形块的索引下标。
遍历数组：
当栈非空且 \text{height}[current]>\text{height}[st.top()]height[current]>height[st.top()]
意味着栈中元素可以被弹出。弹出栈顶元素 \text{top}top。
计算当前元素和栈顶元素的距离，准备进行填充操作
\text{distance} = \text{current} - \text{st.top}() - 1distance=current−st.top()−1
找出界定高度
\text{bounded\_height} = \min(\text{height[current]}, \text{height[st.top()]}) - \text{height[top]}bounded_height=min(height[current],height[st.top()])−height[top]
往答案中累加积水量\text{ans} \mathrel{+}= \text{distance} \times \text{bounded\_height}ans+=distance×bounded_height
将当前索引下标入栈
将 \text{current}current 移动到下个位置

作者：LeetCode
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
int trap(vector<int>& height) {

    int ans = 0;

    stack<int> st;

    for(int i =0 ; i<height.size() ;i++){
        while( !st.empty() && height[st.top()] < height[i]){
            int cur = st.top();
            st.pop();
            if( st.empty()){
                break;
            }

            int l = st.top();
            int r = i;
            int h = min( height[r],height[l])-height[cur];

            ans += (r-l-1)*h;
        }
        st.push(i);

    }

    return ans;
    
}

//方法二：采用动态编程的思想进行求解；
/*
1)找到数组中从下标 i 到最左端最高的条形块高度 \text{left\_max}left_max。
2)找到数组中从下标 i 到最右端最高的条形块高度 \text{right\_max}right_max。
3)扫描数组 \text{height}height 并更新答案：
累加 \min(\text{max\_left}[i],\text{max\_right}[i]) - \text{height}[i]min(max_left[i],max_right[i])−height[i] 到 ansans 上

作者：LeetCode
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

int trap( vector<int>& height){
    if( !height.empty()){
        return 0 ;
    }

    int ans = 0;
    int size = height.size();
    vector<int> left_max(size),right_max(size);

    left_max[0] = height[0];

    for( int i =1 ;i< size ;i++){
        left_max[i] = max( left_max[i-1] , height[i]);
    }

    right_max[size-1] = height[size-1];

    for(int i = size -2 ;i>=0;i++){
        right_max[i] = max(height[i],right_max[i+1]);
    }

    for( int i= 1; i<size ;i++){
        ans += min( left_max[i] ,right_max[i])-height[i];
    }

    return ans;


}
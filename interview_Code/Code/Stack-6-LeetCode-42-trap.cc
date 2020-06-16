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
using namespace std;

/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

*/

/*
方法一：按照列进行求解；
    1） 对于当前列，求解最大能够接的水是多少分为三种情况进行讨论
    a_ 当左右两个列中较矮的列 大于 当前列的的高度， 较矮的列-当前的高度；
    b_ 较矮的列的高度小于 当前列的墙的高度， 那么此时没有水；
    c_ 如果相等，那么依旧没有水；

时间复杂度位： o(n^2);

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        int  sum = 0 ;
        for( int i =  0 ;i < size ;i++){
            int max_left = 0 ;
            for(int j = i- 1 ; j>= 0 ;j--){
                if( height[j] > max_left){
                    max_left = height[j];
                }
            }
            //右边的高度
            int max_right = 0 ;
            for(int j = i+1 ;j < size ;j++){
                if( height[j] > max_right){
                    max_right = height[j];
                }
            }


            //找出两端较小的值；
            int minValue = min( max_left ,max_right);

            if( minValue > height[i]){
                sum +=( minValue-height[i]);
            }
        }

        return sum ;

    }

};

//方法二：动态规划
/*
1)用数字max_left[i] 表示 第i 列左边最高的墙的高度，同理 max_right[i] 表示第i列右边最高的墙的高度。
max_left[i] = max( max_left[i-1], height[i-1]);

max_right[i] = max( max_right[i+1] , heigth[i+1]);


*/

class Solution {
public:
    int trap(vector<int>& height) {

        int sum = 0 ;
        int size  = height.size();

        vector<int>  max_left ( size , 0);
        vector<int> max_right( size ,0);

        for( int i = 1 ; i < size-1 ;i++){
            max_left[i] = max( max_left[i-1], height[i-1]);
        }

        for( int j = size-2 ;j >=0 ;j--){
            max_right[j] = max( max_right[j+1], height[j+1]);
        }

        for( int i = 1 ;i < size -1 ;i++){

            int minValue = min( max_left[i], max_right[i]);

            if( minValue > height[i]){

                sum += ( minValue - height[i] );

            }
        }
        return sum ;

    }
};

//方法三： 双指针进行求解；
/*
从左到右更新 max_left，从右到左更新max_right;


*/

class Solution {
public:
    int trap(vector<int>& height) {

        int sum = 0 ;
        int max_left = 0 ;
        int max_right = 0 ;

        int size = height.size() -1 ;
        int left = 1 ;
        int right =  size -2;//指定右指针的范围；

        for(int i = 1 ;i < size-1 ;i++){

            //从左到右进行更新；
            if( height[left-1] < height[right+1]){

                max_left = max( max_left , height[left-1]);

                int min = max_left;

                if( min > height[left]){
                    sum +=( min-height[left]);
                }

                left++;
            }else{
            //从右到左进行更新；
                max_right = max( max_right , height[right+1]);
                int min = max_right;
                if( min > height[right]){
                    sum +=( min - height[right]);
                }

                right--;
            }

        }
        return sum ;
    }
};

//方法四：使用栈进行操作；
/*
基本原则：
1）当前高度小于等于栈顶高度，入栈，指针后移。

2）当前高度大于栈顶高度，出栈，计算出当前墙和栈顶的墙之间水的多少，然后计算当前的高度和新栈的高度的关系，重复第 2 步。直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。

作者：windliang
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0 ;

        stack<int> st;

        for( int i =0 ;i <height.size() ;i++){

            //如果栈不空并且当前指向的高度大于栈顶高度就一直循环    

            while( !st.empty() && height[st.top()] < height[i]){

                int  cur = st.top();

                st.pop();

                if( st.empty()){
                    break;
                }

                int left = st.top();
                int right = i ;

                int h =min( height[left],height[right]) -height[cur];
                ans  += (right - left -1) * h;
            }

            st.push(i);
        }

        return ans;
    }

};
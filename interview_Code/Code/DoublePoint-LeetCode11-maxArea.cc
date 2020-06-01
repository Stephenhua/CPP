#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：采用双指针法进行求解：

int maxArea(vector<int>& height) {
    int res = 0;
    int size = height.size();
    int i = 0 ; 
    int j = size-1;
    while( i< j){
            res = max( res ,min(height[i],height[j])*(j-i));
        if( height[i] < height[j]){

            i += 1; 
        }else{
            j -= 1 ;
        }
    }
    return res;
    
}
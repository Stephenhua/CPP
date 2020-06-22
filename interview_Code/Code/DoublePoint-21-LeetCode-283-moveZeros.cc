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
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

*/
/*
双指针法：
1） 一个指针用于遍历；
2）另一个指针指出0的节点；
当 不为0 时候，这两个指针依次想等；
当遇到0的时候，j就保持不变了，而i依旧进行遍历，此时遇到非0时候，直接可以进行交换；

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if( size == 0 ){
            return ;
        }

        int j = 0 ;
        for( int  i = 0 ; i < size ;i++){
            if( nums[i] != 0 ){
                int temp = nums[i];
                nums[i] = nums[j] ;
                nums[j] = temp;
                j++;
            }
        }
    }
};

//方法二：统计0的个数，然后从当前序号减去0的个数就是，剩余的个数了；

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0 ;
        int zeros = 0;
        int size = nums.size();

        for( i = 0 ;i < size;i++){
            if( nums[i] == 0 ){
                ++zeros;
            }else{
                nums[i-zeros] = nums[i];
            }
        }

        i  = size - zeros;
        while( i < size){
            nums[i] = 0 ;
            i++;
        }
        return ;
    }

};
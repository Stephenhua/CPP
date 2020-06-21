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

457. 环形数组循环--此题困难，没有完全做出来；

给定一个含有正整数和负整数的环形数组 nums。 如果某个索引中的数 k 为正数，则向前移动 k 个索引。相反，如果是负数 (-k)，则向后移动 k 个索引。因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。

确定 nums 中是否存在循环（或周期）。循环必须在相同的索引处开始和结束并且循环长度 > 1。此外，一个循环中的所有运动都必须沿着同一方向进行。换句话说，一个循环中不能同时包括向前的运动和向后的运动。
 

示例 1：

输入：[2,-1,1,2,2]
输出：true
解释：存在循环，按索引 0 -> 2 -> 3 -> 0 。循环长度为 3 。
示例 2：

输入：[-1,2]
输出：false
解释：按索引 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。
示例 3:

输入：[-2,1,-1,-2,-2]
输出：false
解释：按索引 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为按索引 1 -> 2 的运动是向前的运动，而按索引 2 -> 1 的运动是向后的运动。一个循环中的所有运动都必须沿着同一方向进行。
 

提示：

-1000 ≤ nums[i] ≤ 1000
nums[i] ≠ 0
0 ≤ nums.length ≤ 5000
 

进阶：

你能写出时间时间复杂度为 O(n) 和额外空间复杂度为 O(1) 的算法吗？

*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {

    }
};

//循环问题：用快慢指针解决
//计算 next 位置，对于会超出数组的长度的正数，我们可以通过对n取余，
//但是对于负数，若这个负数远大于n的话，取余之前只加上一个n，可能是不够的，所以正确的方法是应该先对n取余，再加上n。
//为了同时把正数的情况也包含进来，最终我们的处理方法是先对n取余，再加上n，再对n取余，这样不管正数还是负数，大小如何，都可以成功的旋转跳跃了。
int getnext(int* nums,int i,int numsSize) {
    return (((nums[i] + i) % numsSize) + numsSize) % numsSize;
}

bool circularArrayLoop(int* nums, int numsSize){
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] == 0) {//如果遇到已经访问过，被标记的地方
            continue;//我们也可以不用 visited 数组，直接在 nums 中标记，由于题目中说了 nums 中不会有0，所以可以把访问过的位置标记为0
        }
        int slow = i;//对于每个i位置，慢指针指向i
        int fast = getnext(nums,i,numsSize);//快指针指向下一个位置，这里调用子函数来计算下一个位置
        int val = nums[i];
        while(val * nums[fast] > 0 && val * nums[getnext(nums,fast,numsSize)] > 0) {
            //慢指针指向的数要和快指针指向的数正负相同，这个不难理解。并且慢指针指向的数还要跟快指针的下一个位置上的数符号相同
            if(slow == fast) {
                if(slow == getnext(nums,slow,numsSize)) {
            //直到当快慢指针相遇的时候，就是环出现的时候，但是这里有个坑，即便快慢指针相遇了，也不同立马返回 true，
            //因为题目中说了了环的长度必须大于1，所以我们要用慢指针指向的数和慢指针下一个位置上的数比较，若相同，则说明环的长度为1，此时并不返回 false，而且 break 掉 while 循环。
            //因为这只能说以i位置开始的链表无符合要求的环而已，后面可能还会出现符合要求的环。但是若二者不相同的话，则已经找到了符合要求的环，直接返回 true。
                    break;
                }
                return true;
            }
            //若快慢指针还不相同的，则分别更新，慢指针走一步，快指针走两步
            slow = getnext(nums,slow,numsSize);
            fast = getnext(nums,getnext(nums,fast,numsSize),numsSize);
        }
        //当 while 循环退出后，我们需要标记已经走过的结点，从而提高运算效率，方法就是将慢指针重置为i，再用一个 while 循环，条件是 nums[i] 和 慢指针指的数正负相同
        slow = i;
        while(val * nums[slow] > 0) {
            int next = getnext(nums,slow,numsSize);//然后计算下一个位置，并且 nums[slow] 标记为0，并且慢指针移动到 next 位置。
            nums[slow] = 0;
            slow = next;
        }
    }
    //最终 for 循环退出后，返回 false 即可
    return false;
}



作者：fuchao
链接：https://leetcode-cn.com/problems/circular-array-loop/solution/c-xun-huan-wen-ti-jiu-yong-kuai-man-zhi-zhen-by-fu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
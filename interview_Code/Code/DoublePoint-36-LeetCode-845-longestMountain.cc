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
845. 数组中的最长山脉
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：

B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）

给出一个整数数组 A，返回最长 “山脉” 的长度。

如果不含有 “山脉” 则返回 0。

 

示例 1：

输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
示例 2：

输入：[2,2,2]
输出：0
解释：不含 “山脉”。
 

提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000

*/

/*
寻找山脉：
1） 先递增然后递减；
2）先检查 是否递增，如果不是，start = end+ 1;
3）如果是 :
        1)检查end++;
        2)如果end++终端，然后进行下山，
            1）如果下山的时候，如果不满足下山的约束条件
            2）更新start和end， 此时start就是end的位置；并且与结果进行判断；

*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        int size = A.size();

        int start = 0 ;
        int end = 0 ;
        int res = 0 ;

        while( start< size-1){
            end = start ;
            if( A[end] < A[end+1]){
                //递增寻找；
                while( end +1< size && A[end] < A[end+1]){
                    end++;
                }
                // 此时end的下一个元素已经不比end指向的元素严格大了
                if( end +1 < size && A[end] > A[end+1]){

                    // 下降到不在严格下降为止，这个时候start和end所包含的区间就是一座山峰了。
                    while( end +1 <size && A[end] > A[end+1]){
                        end++;
                    }

                    res = max( res, end-start+1);

                    start = end;// 尝试寻找下一座山脉，这里体现了start的跳跃性，类似与kmp模式匹配那种
                 }
                 else{
                    start = end +1;
                    continue;
                 }
            }else{
// 如果是平着的，或者到了末尾，就开始下一轮，因为这一轮没有山峰。为什么没有山峰？因为山峰必须要有严格下降，没有就不是山峰。
                start++;
            }
        }
        return res;
    }
};

//方法二：
class Solution {
public:
    int longestMountain( vector<int>& A ) {
        int ret = 0;
        int l = 0, r = 0;
        int i = 1;

        while( i < A.size() ) {
            //当相等的的时候直接跳过；
            while( i < A.size() && A[i] == A[i - 1] ) {
                i++;
            }
            //判断上坡；
            while( i < A.size() && A[i] > A[i - 1] ) {
                l++;
                i++;
            }
            //计算下坡；
            while( i < A.size() && A[i] < A[i - 1] ) {
                i++;
                r++;
            }
            //进行求和；
            if( l > 0 && r > 0 ) {
                ret = max( ret, l + r + 1 );
            }
            //直接复位归0；
            l = 0, r = 0;
        }

        return ret;
    }
};
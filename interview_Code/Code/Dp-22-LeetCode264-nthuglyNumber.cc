#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
264. 丑数 II
编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

*/
/*
动态规划的思想+归并排序的思想进行；

我们可以把丑数分成三组，用丑数序列分别乘 2, 3, 5 。
乘 2: 1×2, 2×2, 3×2, 4×2, 5×2, 6×2, 8×2,9×2,…
乘 3: 1×3, 2×3, 3×3, 4×3, 5×3, 6×3, 8×3,9×3,…
乘 5: 1×5, 2×5, 3×5, 4×5, 5×5, 6×5, 8×5,9×5,…
然后利用归并排序进行求解；
使用三个指针，分别指向他们的首位，每次找到三个数组中最小的一个元素，然后将这个元素的坐标直接后移一位，此时又得到了三个值，进行比较；

*/
class Solution {
public:
    int nthUglyNumber(int n) {

        int urgly[n];

        urgly[0] = 1;

        int index1 =0,index2 =0, index3 = 0 ;

        for(int i = 0 ;i < n ;i++){

            int n1 = 2* urgly[index1];
            int n2 = 3* urgly[index2];
            int n3 = 5* urgly[index3];

            int minValue = min( n1, min(n2 ,n3));
            urgly[i] = minValue;

            if( n1 == minValue){
                index1++;
            }else if( n2 == minValue){
                index2++;
            }else if( n3 == minValue){
                index3++;
            }
        }
        return urgly[n-1];
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>

#include <numeric>

using namespace std;

/*
76-除法

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1; 

        if((a>0 && b<0) || (a<0 && b>0)){
            sign = -1;
        }
        a = a>0?a:-a;
        b = b>0?b:-b;
        long res = div(a,b);
        if(sign>0)return res>INT_MAX?INT_MAX:res;
        return -res;
    }
    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};

//方法二：使用位运算进行；
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        //将int转为long;
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        //判断正负；
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

        while (dvd >= dvs) {

            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }

            dvd -= temp;
            ans += m;
        }
        return (int) (sign * ans);
    }
};
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
923. 三数之和的多种可能
给定一个整数数组 A，以及一个整数 target 作为目标值，返回满足 i < j < k 且 A[i] + A[j] + A[k] == target 的元组 i, j, k 的数量。

由于结果会非常大，请返回 结果除以 10^9 + 7 的余数。

 

示例 1：

输入：A = [1,1,2,2,3,3,4,4,5,5], target = 8
输出：20
解释：
按值枚举（A[i]，A[j]，A[k]）：
(1, 2, 5) 出现 8 次；
(1, 3, 4) 出现 8 次；
(2, 2, 4) 出现 2 次；
(2, 3, 3) 出现 2 次。
示例 2：

输入：A = [1,1,2,2,2,2], target = 5
输出：12
解释：
A[i] = 1，A[j] = A[k] = 2 出现 12 次：
我们从 [1,1] 中选择一个 1，有 2 种情况，
从 [2,2,2,2] 中选出两个 2，有 6 种情况。
 

提示：

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300

*/

//先进行排序，然后进行是三个指针同时运行；

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        sort( A.begin() ,A.end());
        int left = 0 ;
        int size = A.size();
        int right = size -1;
        int res = 0 ;

        int mod = 1000000007;

        for( ; left < size -2;left++){
            if( target < A[left]){
                break;
            }
            for( int mid = left+1 ; mid < size;mid++){

                int value = target -A[left]-A[mid];

                if( value < 0){
                    break;
                }
                pair<vector<int>::iterator, vector<int>::iterator> range =equal_range(A.begin() + mid + 1, A.end(), value);

                res += range.second-range.first;
                res %= mod;
            }

        }
        return res;
    }
};

//方法二：三个指针
class Solution {
public:
    const long M = 1e9 + 7;
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int N = A.size();
        long res = 0;
        for (int i = 0; i < N - 2; ++i) {
            int t = target - A[i];
            //判断边界条件；
            if (t < 2 * A[i]) break;
            int l = i + 1;
            int r = N - 1;
            //内部循环；
            while (A[l] < A[r]) {
                //当大于t的时候，直接进行--；
                if (A[l] + A[r] > t) {
                    --r;
                } else if (A[l] + A[r] < t) {
                    //当小于t的时候直接进行++；
                    ++l;
                } else {
                    //如果相等的时候，统计值；
                    int tl = l;
                    int tr = r;
                    while (A[++l] == A[tl]);
                    while (A[--r] == A[tr]);
                    res += (l - tl) * (tr - r);
                    res %= M;
                }
            }
            //如果相等的时候，那么直接进行数学计算；
            if (A[l] == A[r] && A[l] + A[r] == t) {
                int d = r - l + 1;
                res += d * (d - 1) / 2;
                res %= M;
            }
        }
        return res;
    }
};
//直接进行数学运算：数学组合运算；
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long a[101] = {0};
        //统计各个变量的值；
        for(int i : A){
            ++a[i];
        }
        long ans = 0;
        //坐标就是value值；

        for (int i = 0; i <= 100; ++i){
            for (int j =i; j <= 100; ++j) {
                int k = target - i - j;
                if (k < j ) break;
                else if (k > 100) continue;

                long sum;

                if(i == j && i == k) {
                    sum = a[i] *(a[i]- 1 )*( a[i] - 2) / 6;
                }
                else if (i == j) {
                    sum = a[i] * (a[i] - 1)/2 *a[k];
                }
                else if (i == k) {
                    sum = a[i] * (a[i] - 1)/2 * a[j];
                }
                else if (j == k) {
                    sum =a[j]* (a[j] - 1) / 2 * a[i];
                }
                else {
                    sum = a[i] * a[j] * a[k];
                }
                ans += sum;
            }
        }
        return ans % 1000000007;
    }
};
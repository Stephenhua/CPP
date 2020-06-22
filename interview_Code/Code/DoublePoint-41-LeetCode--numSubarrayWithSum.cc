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
930. 和相同的二元子数组
在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。

 

示例：

输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

提示：

A.length <= 30000
0 <= S <= A.length
A[i] 为 0 或 1
通过次数3,214提交次数8,869

*/
/*
动态规划进行实现；
1）dp[i] 表示何为 i的前缀额和个数；
2）枚举每一个区间的终点，如果sum[i] >=s ,则观察f(sum[i]- S)的个数，

*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        vector<int> s(n + 1, 0), f(n + 1, 0);
        for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + A[i - 1];

        int ans = 0;
        f[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            int sum = s[i];
            if(sum >= S) ans += f[sum - S];
            f[sum] ++;
        }

        return ans;
    }
};

#include <iostream>
#include <vector>
using namespace std;
//=====================================================
//解法一：采用动态规划的方程进行求解：
//  dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，这里为了节省空间，使用一维数组 dp，
//一行一行的刷新也可以
//=====================================================
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return d[n-1];

    }
};

//=====================================================
//解法二：采用动态规划的方程进行求解：
//  dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，这里为了节省空间，使用一维数组 dp，
//一行一行的刷新也可以
//=====================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=0;i<n;i++) dp[0][i]=1;
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return d[m-1][n-1];

    }
};


//=====================================================
//解法三：采用数学模型，求解阶乘的方法进行
//  机器人总共走m+n-2步，其中m-1步往下走，n-1步往右走，本质上就是一个组合问题，也就是从m+n-2个不同元素中每次取出m-1个元素的组合数。根据组合的计算公式，我们可以写代码来求解即可
//=====================================================

 double dom = 1;
    double dedom = 1;
    int small = m<n? m-1:n-1;
    int big = m<n? n-1:m-1;
    for(int i=1;i<=small;i++)
    {
        dedom *= i;
        dom *= small+big+1-i;
    }
    return (int)(dom/dedom)

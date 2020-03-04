/*
题目：不同的二叉搜索树 II；
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>

using  namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//该方法采用构造卡特兰数的应用，采用动态规划的思想进行求解；
/*
我们可以简单的得到：

n=0时，种类数为dp(n)=1；
n=1时，种类数为dp(n)=1；
则可以依次计算得到n个结点时二叉树的种类，即：

dp(n)=dp(0)*dp(n-1)+dp(1)*dp(n-2)+dp(2)*dp(n-3)+...+dp(n-1)*dp(0)

另外也可以直接构造卡特兰数公式求解：

dp(n)=C(2n,n)/(n+1)
*/
class Solution{
    int numTrees(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];//两个数相加起来为n-1;
            }

        }
        return dp[n];
    }
};
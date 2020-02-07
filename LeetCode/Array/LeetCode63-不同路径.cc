#include <vector>
#include <iostream>
using namespace std;
//==========================================
//采用循环的方式进行求解，边界条件不好进行把握；
//其时间复杂度较高；
//==========================================
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.empty()||obstacleGrid[0].empty()||obstacleGrid[0][0]==1){
            return 0;
        }

        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        vector<vector<long>> dp(m+1,vector<long>(n+1,0));

        dp[0][1]=1;

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(obstacleGrid[i-1][j-1]!=0){
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

//==========================================
//方法二：
//采用循环的方式进行求解，边界条件不好进行把握；
//其时间复杂度较低；
//==========================================

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

//==========================================
//方法三：
//采用循环的方式进行求解，边界条件不好进行把握；
//其时间复杂度低；
//==========================================

  int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n,0));
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1)
                {break;}
            else
            {dp[i][0]=1;}
        }
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[0][j]==1)
            {
                break;
                }
            else
            {
                dp[0][j]=1;
                }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    }
                else{

                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
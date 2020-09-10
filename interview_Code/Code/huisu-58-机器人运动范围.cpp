#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*

剑指 Offer 13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

*/
/*
回溯算法可以看作暴力解法的升级版，它从解决问题每一步的所有可能选项里系统地选出一个可行的解决方案。
回溯法非常适合解决由多个步骤组成的问题，而且每个步骤都有多个选项。回溯法一般用递归来实现。

作者：superkakayong
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/zi-jie-ti-ku-jian-13-zhong-deng-ji-qi-ren-de-yun-d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
class Solution {
public:
    int movingCount(int m, int n, int k) {

        if( k == 0){
            return 1 ;
        }

        vector<vector<bool>> isValid(m,vector<bool>(n,true));//记录是否曾今被访问过；

        return dfs(isValid,m,n,0,0,k);
    }
    int num = 0 ;
    
    int  dfs(vector<vector<bool>>& isValid, int m,int n ,int row ,int col ,int k){

        int sum = get(row) +get(col);
        if(row >= m || col >= n || !isValid[row][col]){
            return 0;
        }
        isValid[row][col] = true;
        num = 1+dfs(isValid,m,n,row+1,col,k) +dfs(isValid,m,n,row,col+1,k)+dfs(isValid,m,n,row-1,col,k)+dfs(isValid,m,n,row,col-1,k);//回溯算法；
        return num ;
    }

    int get(int a ){
        if( a < 10 ){
            return a;
        }

        int sum = 0 ;
        while(a > 0 ){
            sum+= a%10;
            a= a/10;
        }
        return sum ;
    }
};




class Solution1 {
public:
    int num = 0 ;
    int movingCount(int m, int n, int k) {

        if( k == 0){
            return 1 ;
        }

        vector<vector<bool>> isValid(m,vector<bool>(n,false));//记录是否曾今被访问过；

         dfs(isValid,m,n,0,0,k);
         return num;
    }

    void dfs(vector<vector<bool>>& isValid, int m,int n,int i,int j,int k){

        if( i >= m || i< 0 || j >=n || j < 0 ){
            return ;
        }

        if(isValid[i][j] ==  true ){
            return ;
        }

        if( (i%10 +i/10 +j%10+j/10) > k ){
            return;
        }
        isValid[i][j]=true;
        num++;
        dfs(isValid,m,n,i+1,j,k);
        dfs(isValid,m,n,i,j+1,k);
        dfs(isValid,m,n,i-1,j,k);
        dfs(isValid,m,n,i,j-1,k);
    }

    
};
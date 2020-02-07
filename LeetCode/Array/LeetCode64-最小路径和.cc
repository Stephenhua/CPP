#include <vector>
#include <iostream>
using namespace std;
//==========================================
//解法一：采用动态递归的形式进行计算
//==========================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    continue;
                }
                else if(i==0){
                    grid[i][j]=grid[i][j-1]+grid[i][j];
                }else if(j==0){
                    gird[i][j]=grid[i][j-1]+gird[i][j];
                }els if{
                    gird[i][j]=grid[i][j-1]+gird[i-1][j]+gird[i][j];
                }
            }
        }        
    }
};
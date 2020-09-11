#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
695. 岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

 

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

*/



class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0 ;

        for(int r = 0 ; r < grid.size() ; r++){
            for(int c = 0 ; c< grid[0].size() ; c++){
                if( grid[i][j] == 1 ){
                    int a = area ( grid,i,j);
                    res = max( res, a );
                }
            }
        }
        return res;
    }

    int area(vector<vector<int>>& grid, int i ,int j ){
        if( !inArea( grid,i,j)){
            return 0 ;
        }
        //对于选过的节点，应该直接跳过；
        if( grid[i][j] != 1 ){
            return 0 ;
        }

        grid[i][j] = 2;
        return 1 + area(grid,i+1,j)+ area(grid,i-1,j)+ area(grid,i,j-1)+ area( grid, i ,j+1 );
    }

    bool inArea(vector<vector<int>>& area , int i ,int j ){

        if( i >= 0 && i < area.size() && j >= 0 && j < area[0].size() ){

            return true;

        }
        return false;
    }
};


//方法二：DFS的变形

bool inArea(vector<vector<int>>& area , int i ,int j ){

    if( i >= 0 && i < area.size() && j >= 0 && j < area[0].size() ){

        return true;

    }
    return false;
}

int dfs(vector<vector<int>>& grid, int i ,int j ){

    if( !inArea(grid,i,j)  || grid[i][j] == 0 ) {
        return 0 ;
    }
    //进行标记说明，防止重新进行选择；
    
    grid[i][j]  = 0 ;
    int num = 1 ;
    num += dfs(grid,i+1,j);
    num += dfs(grid,i-1,j);
    num += dfs(grid,i,j-1);
    num += dfs(grid,i,j+1);

    return num ;
}
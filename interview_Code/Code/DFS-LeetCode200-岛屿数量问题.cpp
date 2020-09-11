#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*

200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1:

输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1
示例 2:

输入:
[
['1','1','0','0','0'],
['1','1','0','0','0'],
['0','0','1','0','0'],
['0','0','0','1','1']
]
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

*/


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i  ,int j ){
        if(!isArea(grid,i,j) || grid[i][j] == '0'){
            return ;
        }

        grid[i][j] = '0';
        int di[4] = { 0, 0, 1, -1 };
        int dj[4] = { 1, -1, 0, 0 };

        for(int index = 0 ; index < 4 ; index++){
            dfs( grid, i+di[index], j+dj[index]);
        }
    }

    bool isArea(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && i < gird.size() && j >= 0 && j< grid[0].size() ){
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>& grid, int i  ,int j ){
        if(!isArea(grid,i,j) || grid[i][j] == '0'){
            return ;
        }

        grid[i][j] = '0';
        dfs( grid, i+1, j );
        dfs( grid, i-1, j );
        dfs( grid ,i ,j - 1 );
        dfs( grid, i ,j + 1 );

    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0 ;j < grid[0].size() ; j++){
                if( grid[i][j] == '1'){
                    res++;
                    dfs( grid,i,j);
                }

            }
        }
        return res;
    }
};


//方法二：采用广度优先遍历的方法进行求解；
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0 ;j < grid[0].size() ; j++){
                if( grid[i][j] == '1'){
                    res++;
                    bfs( grid,i,j);
                }

            }
        }
        return res;
    }
    bool isArea(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && i < gird.size() && j >= 0 && j< grid[0].size() ){
            return true;
        }
        return false;
    }

    void bfs(vector<vector<int>>& grid, int i  ,int j ){

        queue<pair<i,j>> dq;

        dp.push_back({i,j});

        while( !dq.empty()){

            pair<int,int> temp = dp.front();
            int i = temp[0];
            int j = temp[1];
            dp.pop();
            if( isArea(grid,i,j) && gird[i][j] == '1'){

                grid[i][j] = '0';
                dq.push_back({i-1,j});
                dq.push_back({i+1,j});
                dq.push_back({i,j-1});
                dq.push_back({i,j+1});
            }
        }
    }
};
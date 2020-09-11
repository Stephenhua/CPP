#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


/*
463. 岛屿的周长
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16

解释: 它的周长是下面图片中的 16 个黄色的边：


通过次数23,289提交次数34,213


*/


/*

采用DFS的方式进行求解，在方格为1的情况下，才会进行求解；

*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0 ; i< row ;i++){
            for(int j = 0 ;j < col ;j++){
                if( grid[i][j] == 1 ){
                    return dfs(grid,i,j);
                }
            }
        }
        
        return 0 ;
    }
    int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}};
    int dfs(ector<vector<int>>& grid, int i ,int j){
        if( !inArea(grid,i,j)){
            return 1;
        }

        if( grid[i][j] == 0){
            return 1;
        }

        if( grid[i][j] == 2 ){
            return 0;
        }

        grid[i][j] = 2 ;
    
        int temp = 0 ;

        for(auto& d : dir ){
            int x = i + d[0];
            int y = j + d[1];
            temp += dfs( grid,x, y);
        }
        return temp;
    }

};
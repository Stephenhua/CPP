#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>

#include <numeric>

using namespace std;

/*
980. 不同路径 III
在二维网格 grid 上，有 4 种类型的方格：

1 表示起始方格。且只有一个起始方格。
2 表示结束方格，且只有一个结束方格。
0 表示我们可以走过的空方格。
-1 表示我们无法跨越的障碍。
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。

 

示例 1：

输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
输出：2
解释：我们有以下两条路径：
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
示例 2：

输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
输出：4
解释：我们有以下四条路径： 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
示例 3：

输入：[[0,1],[2,0]]
输出：0
解释：
没有一条路能完全穿过每一个空的方格一次。
请注意，起始和结束方格可以位于网格中的任意位置。
 

提示：

1 <= grid.length * grid[0].length <= 20

*/

/*
思路：采用DFS+回溯的思想进行求解；
存在的问题：
1）起始位置不确定；
2)存在障碍物；
3） 求解路径的数目；

约束条件：
1）全部遍历，只能遍历一次；
2）边界条件；
3）存在障碍物；

*/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx ,starty ,stepNum =1;

        for(int i = 0 ;i < grid.size(); i++){
            for(int j = 0 ;j < grid[i].size() ;j++){
                if( grid[i][j] == 1){
                    startx = i;
                    starty = j;
                    continue;
                }
                if( grid[i][j] == 1 ){
                    stepNum++;
                }
            }
        }

        return dfs( grid,startx,starty,stepNum);
    }

    int dfs(vector<vector<int>>& grid ,int i ,int j ,int stepNum){
        if( !isArea){
            return 0;
        }
        if( grid[i][j] == 2 ){
            return stepNUm == 0 ?1 :0 ;//针对深度遍历的时候，中间的时候到达2这个点，那么该如何操作？直接应该返回不，这是不符合条件的；
        }

        grid[i][j] = -1 ;//进行标志位0；

        int res = 0 ;      

        res += dfs( grid, i+1,j, stepNum-1);
        res += dfs( grid, i, j+1, stepNum-1);
        res += dfs( grid, i-1 ,j ,stepNum -1 );
        res += dfs( grid ,i, j-1 ,stepNum -1 );

        grid[i][j] = 0;
        return res;
    }

    bool isArea(vector<vector<int>>& grid ,int i ,int j ){
        if(  i>=0 && i< gird.size() && j >=0 && j< gird[0].size()){
            return true;
        }
        return false ;
    }


};


//方法二：DFS+回溯，DFS中没有返回值；
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int path_count = 0 ;//记录路径的数量；
        int zero_count = 0 ;//记录0的个数；
        int x, y ;

        for(int i =0  ;i < grid.size() ;i ++){
            for(int j = 0 ;j < grid[0].size() ; j++){
            
                if( grid[i][j] == 1 ){
                    x = i;
                    y = j ;
                    zero_count++;//开始点应该也算一个点的个数，相当于遍历整个表格中的n*m-1个节点；
                }

                if( grid[i][j] == 0 ){
                    zero_count++;
                }

            }
        }

        dfs(grid, x, y, zero_count,path_count);//深度优先搜索；
        return path_count;
    }

    void dfs(vector<vector<int>>& grid, int i ,int j ,int zero_count ,int& path_count){

        if( !isArea(grid,i,j)){
            return ;
        }

        if( grid[i][j] == -1 ){//已经走过了，应该直接返回去；
            return ;
        }
        //每次深度优先搜索会将zero_count-1,当其为0时且到达终点时，才表明找到一条路，path++
        if( grid[i][j] == 2 && zero_count != 0){
            return ;
        }

        if( grid[i][j] == 2 && zero_count == 0 ){
            path_count++ ;
            return ;
        }

        int temp = grid[i][j] ;
        grid[i][j] = -1 ;//进标记；

        dfs( grid ,i-1,j,zero_count-1 ,path_count);
        dfs( grid ,i+1 ,j ,zero_count-1,path_count);
        dfs( grid ,i,j-1,zero_count-1,path_count);
        dfs( grid ,i, j+1 ,zero_count-1 ,path_count);

        grid[i][j] = temp;

    }

    bool isArea(vector<vector<int>>& grid, int i ,int j){
        if( i >= 0 && i <grid.size() && j >= 0 && j < grid[0].size()){
            return true;
        }
        return false ;
    }


};

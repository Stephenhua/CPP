#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

/*

827. 最大人工岛
在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。

进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）

示例 1:

输入: [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
示例 2:

输入: [[1, 1], [1, 0]]
输出: 4
解释: 将一格0变成1，岛屿的面积扩大为 4。
示例 3:

输入: [[1, 1], [1, 1]]
输出: 4
解释: 没有0可以让我们变成1，面积依然为 4。
说明:

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 1

*/


class Solution {
public:
    unsigned tag[50][50] = {0};//对于面积内部的每个部分进行打编号，方便area的统计求解；
    int area[700] = {0};//用于记录编号为landNum时的数量；即是求解连续的面积；
    unsigned landNum = 0, X, Y;

    void search( vector<vector<int>>& grid ,int x ,int y ){

        if( grid[x][y] == 1 && tag[x][y] == 0 ){
            area[landNum]++;
            tag[x][y] = landNum;
            //边界检查；
            if(inArea(grid,i,j)){
                search(grid ,x+1,y);
                search(grid,x-1,y);
                search(grid,x,y-1);
                search(grid,x,y+1);
            }
        }
    }

    bool inArea(vector<vector<int>>& grid, int x ,int y ){
        if( x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()){
            return true;
        }

        return false;
    }


    int largestIsland(vector<vector<int>>& grid) {

        unsigned maxRes = 0 , ans;
        x = grid.size();
        y = grid[0].size();
        //进行搜索方格，根据搜索到的面积进行打标签；
        
        for(int i = 0 ; i < x; i++){
            for(int j  = 0 ;j < y ;j++){
                if( grid[i][j] == 1 && tag[i][j] == 0){
                    landNum++;
                    search(grid,i,j);
                }
            }
        }


        enum{
            up = 0 ;
            right;
            down ;
            left;
        }

        int tagIslan[4];
        unordered_map<unsigned ,unsigned > count ;

        for(unsigned i = 0 ; i < x ; i++){
            for( unsigned j = 0  ; j < y ; j++){
                if( grid[i][j] == 0 ){
                    //主要寻找方格中为0 的元素；
                    ans =  1 ;
                    tagIslan[up] = i >=1 ? tag[i-1][j] : 0;
                    tagIslan[right] = j <  y-1 ? tag[i][j+1]:0;
                    tagIslan[down] = i < x-1 ? tag[i][j-1]:0;
                    tagIslan[left] = j >= 1 ? tag[i][j-1]:0 ;

                    for( unsigned k = up ; k <= left ; k++){
                        if( count[tagIslan[k]] == 0 && tagIslan[k] != 0){
                            ans += area[tagIslan[k]];
                            count[tarIslan[k]] = 1;
                        }

                    }

                    maxRes = max( ans , masRes);
                    count .clear();

                }
            }
        }

        if( maxRes == 0 ){
            return X*Y;
        }

        return maxRes;
    }
};


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0 ;i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if( i == 0 || i == row-1 || j == 0 || j== col-1){
                    dfs(board,i,j);
                }
            }
        }

        for(int i = 0 ;i < row ;i++){
            for(int j =0 ;j < col ;j++){
                if( grid[i][j] == '#'){
                    grid[i][j] ='O';
                }

                if( grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
            }
        }
        
    }

    void dfs(vector<vector<char>>& board, int i ,int j ){
        if( !isArea(board,i,j) || board[i][j] == 'X'){
            return ;
        }

        grid[i][j] = '#';
        dfs( board, i+1, j );
        dfs( board, i-1 ,j );
        dfs( board ,i, j-1 );
        dfs( board ,i , j+1 );

    }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(int i, int j , vector<vector<char>>& board){

        queue<pair<int,int>>  sta;

        sta.push_back({i,j});

        board[i][j] = '#';

        while( !sta.empty()){

            pair<int,int> cur = sta.front();
            sta.pop();

            if( cur.i -1 >= 0 && board[current.i-1][current.j] == 'O' ){
                sta.push(new pos(cur.i-1,cur.j));
                board[i][j] = '#';

            }

            if(cur.i + 1 <= board.size() && board[cur.i+1][cur.j] == 'O'){
                sta.push(new pos(cur.i+1,cur.j));
                board[i][j] = '#';
            }

            if(cur.j + 1 <= board[0].size() && board[cur.i][cur.j+1] == 'O'){
                sta.push(new pos(cur.i,cur.j+1));
                board[i][j] = '#';
            }

            if(cur.j - 1 <= board.size() && board[cur.i][cur.j -1 ] == 'O'){
                sta.push(new pos(cur.i,cur.j-1));
                board[i][j] = '#';
            }
            //如果上下左右都搜不到，那么本次搜索就会结束；
            //sta.();
        }
    }

    
    bool isArea(vector<vector<char>>& board, int i, j ){
        if( i >=0 && i< board.size() && j >= 0 && j< board[0].size()){
            return true;
        }
        return false;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
130. 被围绕的区域
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

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

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。


*/

/*
思路：从边缘开始进行判断，看其是否与内部有连接，如果有链接的话，则进行标记，如果没有连接的话，则不需要进行标记；
采用方法：深度优先搜索和广度优先搜素；

*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int size = board.size();
        int (size == 0 ){
            return ;
        }
        int cols = board[0].size();

        //dfs进行标记“O”节点；
        for(int i = 0 ; i< size ;i++){
            for(int j = 0 ; j < cols ;j++){

                if( (i== 0 || i =size-1  || j == 0 || j == cols-1 ) && board[i][j] == ''O){
                    dfs(i,j,board);
                }
            }
        }

        for(int i = 0 ; i < size ;i++){
            for(int j = 0 ; j< board[0].size() ;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }

    void dfs(int i, int j , vector<vector<char>>& board){

        if( i < 0 || j <0 || i >= board.size() || j >= board.size() || board[i][j] == 'X' || board[i][j] == '#'){
            return;
        }
        //被包围的区域是设置为#；
        board[i][j] = '#';

        dfs( i+1, j, board);
        dfs( i-1 , j ,board);
        dfs( i , j-1 ,board );
        dfs( i , j+1, board);


    }
};

//dfs的非递归写法，采用栈的形式进行求解；

struct pos{
    int i; 
    int j  ;
    pos(int x, int y ):i(x),j(y){};
};

class Solution2 {
public:

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0 ;i < rows ;i++){
            for(int j = 0 ; j < cols ;j++){
                bool isEdgs == i==0||i==rows-1 || j == 0 || j ==cols-1;
                if(isEdge && board[i][j]){
                    dfs(board,i,j);
                }
            }
        }

        for(int i = 0 ; i < rows ;i++){
            for( int j = 0 ; j <cols ;j++){
                if( board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(int i, int j , vector<vector<char>>& board){

        stack<pos>  sta;

        sta.push_back(new pos(i,j));
        board[i][j] = '#';

        while( !sta.empty()){

            pos cur = sta.top();

            if( cur.i -1 >= 0 && board[current.i-1][current.j] == 'O' ){
                sta.push(new pos(cur.i-1,cur.j));
                board[i][j] = '#';
                continue;
            }

            if(cur.i + 1 <= board.size() && board[cur.i+1][cur.j] == 'O'){
                sta.push(new pos(cur.i+1,cur.j));
                board[i][j] = '#';
                continue;
            }

            if(cur.j + 1 <= board[0].size() && board[cur.i][cur.j+1] == 'O'){
                sta.push(new pos(cur.i,cur.j+1));
                board[i][j] = '#';
                continue;
            }

            if(cur.j - 1 <= board.size() && board[cur.i][cur.j -1 ] == 'O'){
                sta.push(new pos(cur.i,cur.j-1));
                board[i][j] = '#';
                continue;
            }
            //如果上下左右都搜不到，那么本次搜索就会结束；
            sta.pop();
        }
    }

    //采用非递归的形式进行求解；
    
    void bfs(int i, int j , vector<vector<char>>& board){

        stack<pos>  sta;

        sta.push_back(new pos(i,j));
        board[i][j] = '#';

        while( !sta.empty()){

            pos cur = sta.top();

            if( cur.i -1 >= 0 && board[current.i-1][current.j] == 'O' ){
                sta.push(new pos(cur.i-1,cur.j));
                board[i][j] = '#';
                continue;
            }

            if(cur.i + 1 <= board.size() && board[cur.i+1][cur.j] == 'O'){
                sta.push(new pos(cur.i+1,cur.j));
                board[i][j] = '#';
                continue;
            }

            if(cur.j + 1 <= board[0].size() && board[cur.i][cur.j+1] == 'O'){
                sta.push(new pos(cur.i,cur.j+1));
                board[i][j] = '#';
                continue;
            }

            if(cur.j - 1 <= board.size() && board[cur.i][cur.j -1 ] == 'O'){
                sta.push(new pos(cur.i,cur.j-1));
                board[i][j] = '#';
                continue;
            }
            //如果上下左右都搜不到，那么本次搜索就会结束；
            sta.pop();
        }
    }

}；
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
52. N皇后 II
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 
提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或七步，可进可退。（引用自 百度百科 - 皇后 ）

*/

vector<vector<string>> res;

/* 是否可以在 board[row][col] 放置皇后？ */
bool isVaild( vector<int>& cols, int n){

   if( cols.size() <= 1){
       return true;
   }

   int row = cols.size() - 1;
   int col = cols.back();

    for( int r = 0 ; r < row ;++r){
        int c = cols[r];

        if( c == col || abs(c-col)==abs(r- row)){
            return false;
        }
    }
    return true;
}




// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行

void  Core( vector<int>& rows, int& res, int n){
    //进行减枝判断；
    if( !isVaild(rows,n)){
        return;
    }

    if( rows.size() == n){
        res++;
        return;
    }

    for(int col= 0 ; col <n ; col++){


        rows.push_back( col);

        Core(rows ,res,n);

        rows.pop_back();
    }
}

int totalNQueens(int n) {
    
    vector<int> rows;
    int res = 0 ;
    Core( rows ,res, n );

    return res;
}

//方法二：
/* 是否可以在 board[row][col] 放置皇后？ */
bool isVaild( vector<string>& board , int row ,int col){

    int n  = board.size();

    // 检查列是否有皇后互相冲突
    for( int i =0 ; i <n ;i++){
        if( board[i][col] == 'Q'){
            return false;
        }
    }

    //检查右上方是否有皇后冲突；

    for( int i = row- 1 , j = col+1; i>=0 && j< n ;i--,j++ ){
        if( board[i][j] == 'Q'){
            return false;
        }
    }

    //检查左上方的值是否有重复的值；
    for( int i =row-1 ,j= col-1 ; i>=0&& j>=0 ;i--,j--){

        if( board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}




// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
int count = 0 ;

void  Core( vector<string>& board, int row){

    if( board.size() == row){
        count++;
        return;
    }

    int n = board[row].size();

    for(int col= 0 ; col <n ; col++){
        //进行减枝判断；
        if( !isVaild( board ,row ,col)){
            continue;
        }

        board[row][col]  = 'Q';
        Core( board ,row+1);
        board[row][col]  = '.';
    }
}

int totalNQueens(int n) {
    vector<string> board( n,string(n,','));
    Core( board ,0 );
    return count;
}
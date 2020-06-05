#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自 百度百科 - 皇后 ）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/*
回溯算法的实现：
解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

写 backtrack 函数时，需要维护走过的「路径」和当前可以做的「选择列表」，当触发「结束条件」时，将「路径」记入结果集。

作者：labuladong
链接：https://leetcode-cn.com/problems/n-queens/solution/hui-su-suan-fa-xiang-jie-by-labuladong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
vector<vector<string>> res;

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

void  Core( vector<string>& board, int row){

    if( board.size() == row){
        res.push_back( board);
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
vector<vector<string>> solveNQueens(int n) {
    vector<string> board( n,string(n,','));
    Core( board ,0 );
    return res;
}
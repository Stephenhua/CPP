#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

/*
思路：从方格中的任意时刻都可一开始；

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0 ;i < board.size() ;i ++){
            for(int j = 0 ; j<board[0].size() ;j++){
                if(Core(board,word,i,j,0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool Core(vector<vector<char>>& board,string& word, int x, int y ,int wordIndex){
        if(board[x][y] != word[wordIndex]){//当前位的字母不相等，此路表示不同；
            return false;
        }

        if(word.size()-1 == wordIndex){
            return true;
        }

        char temp = board[x][y];
        board[x][y] = 0;
        wordIndex++;

        if( (x> 0 && Core(board,word,x-1,y,wordIndex)) || (y>0&& Core(board,word,x,y-1,wordIndex)) || (x < board.size()-1 && Core(board,word,x+1,y,wordIndex) || ) && (y < board[0].size()-1 && Core(board,word,x,y+1,wordIndex))){
            return true;//有一条路走通就算成功；
        }

        board[x][y] = temp;
        return false ;
    }
};


class Solution1 {
public:
int direction[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0 ;i < board.size() ;i ++){
            for(int j = 0 ; j<board[0].size() ;j++){
                if(Core(board,word,i,j,0)){
                    return true;
                }
            }
        }

        return false;
    }
   bool Core(vector<vector<char>>& board,string& word, int x, int y ,int wordIndex){
       if( wordIndex ==  word.length() -1 ){
           return board[i][j] == word[wordIndex];
       }

       if(board[i][j] == word[wordIndex]){
            char temp = board[x][y];
            board[x][y] = 0;
            for(int i = 0 ;i < 4 ;i ++){
                int newX = x + direction[i][0];
                int newY = y + direction[i][1];
                if( inArea(newX ,newY) && board[newX][newY]){
                    if(Core(board,word,newX,newY,wordIndex+1){
                        return true;
                    })
                }
            }

            board[x][y] = temp;
       }
       return false ;
   }

   bool inArea( int x, int y){
       return x >= 0 && x < board.size() && y >=0 && y < board[0].size();
   }
};
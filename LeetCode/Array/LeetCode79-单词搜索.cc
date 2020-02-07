#include <vector>
#include <iostream>
#include <queue>
using namespace std;

//==========================================
//解法一：采用深度优先的算法
/*
这道题是典型的深度优先遍历 DFS 的应用，
原二维数组就像是一个迷宫，可以上下左右四个方向行走，
我们以二维数组中每一个数都作为起点和给定字符串做匹配，
我们还需要一个和原数组等大小的 visited 数组，是 bool 型的，
用来记录当前位置是否已经被访问过，因为题目要求一个 cell 只能被访问一次。
如果二维数组 board 的当前字符和目标字符串 word 对应的字符相等，
则对其上下左右四个邻字符分别调用 DFS 的递归函数，只要有一个返回 true，那么就表示可以找到对应的字符串，否则就不能找到*/
//==========================================

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||board[0].empty()){
            return false;
        }

        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(search(board,word,0,i,j,visted)){
                    return true;
                }
            }
        }
    }

    bool search(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& visited){
        if(index==word.size()){
            return true;
        }

        int m=board.size(),n=board[0].size();
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||board[i][j]!=word[index]){
            return false;
        }

        visited[i][j]=true;

        bool res=search(board,word,index+1,i-1,j,visited)||search(board,word,index+1,i+1,j,visited)||search(board,word,index+1,i,j-1)||
        search(board,word,index+1,i,j+1);
        vistied[i][j]=false;
        return res;
    }
};
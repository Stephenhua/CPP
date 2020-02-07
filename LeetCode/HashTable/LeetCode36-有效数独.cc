#include<map>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty()) return false;
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>  rowFlag(m,vector<bool>(n,false));
        vector<vector<bool>>  colFlag(m,vector<bool>(n,false));
        vector<vector<bool>>   cellFlag(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]>='1'&&board[i][j]<='9')
                {
                    int c=board[i][j]-'1';
                    if(rowFlag[i][c]||colFlag[c][j]||cellFlag[3*(i/3)+j/3][c])
                        return false;
                    rowFlag[i][c]=true;
                    colFlag[c][j]=true;
                    cellFlag[3*(i/3)+j/3][c]=true;
                }
            }
        }
        
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> cols(9),rows(9),blocks(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int index=(i/3)*3+(j/3);
                    if(cols[i].count(board[i][j])||rows[j].count(board[i][j])||blocks[index].count(board[i][j])){
                        return false; 
                    }
                    cols[i][board[i][j]]=rows[j][board[i][j]]=blocks[index][board[i][j]]=1;
                }
            }
        }
        return true;
    }

};

//方法三：采用三次循环的形式进行判断
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int item , presentArray[9];

        //进行行遍历
        for(int i=0;i<9;i++){
            memset(presentArray,0, sizeof(presentArray));
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    item=int(board[i][j])-int('0')-1;

                    if(presentArray[item]==0){
                        presentArray[item]=1;//即表明每一个表中的元素只能为一个，其他的不能为0;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        //进行列的遍历
        for(int i=0;i<9;i++){
            memset(presentArray,0, sizeof(presentArray));
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    item=int(board[j][i])-int('0')-1;

                    if(presentArray[item]==0){
                        presentArray[item]=1;//即表明每一个表中的元素只能为一个，其他的不能为0;
                    }
                    else{
                        return false;
                    }
                }
            }
        }


        //进行块儿的遍历
        for(int i=0;i<3;i++){

            for(int j=0;j<3;j++){
                memset(presentArray,0, sizeof(presentArray));
                    for(int k=i*3;j<(i+1)*3;k++){//首先进行大的模块的遍历，然后进行更小模块的遍历，先大后小，小和大的方法是相同的
                        for(int l=j*3;l<(j+1)*3;l++){
                             if(board[j][i]!='.'){
                                item=int(board[j][i])-int('0')-1;

                                if(presentArray[item]==0){
                                    presentArray[item]=1;//即表明每一个表中的元素只能为一个，其他的不能为0;
                                }
                                else{
                                    return false;
                                }
                      ··········}

                       · }
                    }
                   

        }

    }
    return true;

};
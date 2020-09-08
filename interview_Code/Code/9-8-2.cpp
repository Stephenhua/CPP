#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>

using namespace std;

bool Core(vector<vector<char>>& board,string& s, int wordIndex, int i , int j){
    if(board[i][j] !=s[wordIndex]){
        return false;
    }

    if(s.size()-1 == wordIndex){
        return true;
    }

    char temp =board[i][j];
    board[i][j] = 0;
    wordIndex++;
    if(( i > 0 && Core(board,s,wordIndex,i-1,j)) || ( j > 0 && Core(board,s,wordIndex,i,j-1) ) ||( i < board.size()-1 && Core(board,s,wordIndex,i+1,j)) || (j < board[0].size()-1 && Core(board,s,wordIndex,i,j+1)) ){
        return true;
    }
    board[i][j] = temp;
    return false;
}
bool exit(vector<vector<char>>& board, string s){
    for(int i = 0 ;i < board.size();i++){
        for(int j = 0 ;j <board[0].size() ;j++){
            if(Core(board,s,0,i,j)){
                return true;
            }
        }
    }
    return false;
}


int main(int argc,char*argv[]){
    string s;
    cin >> s ;
    
vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    bool res = exit(board,s);
    if(res){
        cout <<"true"<<endl;
    }else{
        cout <<"false"<<endl;
    }
    system("pause");
    return 0 ;
}
#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    string s;
    while(cin >> s){
        int size = s.size();
        if( size<8 || size>120 ){
            cout << 1 << endl;
        }else {
            int xz=0;
            int dz=0;
            int sz=0;
            int fh =0 ;
            for(int i = 0 ;i < size; i++){
                if(s[i]>='0'&&s[i]<='9'){
                    sz++;
                }else if(s[i]>='a'&& s[i]<='z'){
                    xz++;
                }else if(s[i]>='A'&& s[i]<='Z'){
                    dz++;
                }else if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'){
                    fh++;
                }
            }

            if(xz&&dz&&sz&&fh){
                cout<<0<<endl;
            }else{
                cout <<1<<endl;
            }

        }
    }
    system("pause");
    return 0 ;
}

vector<vector<int>> board;
board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
bool exit(vector<vector<char>>&board, string s){
    for(int i = 0 ;i < board.size();i++){
        for(int j = 0 ;j <board[0].size() ;j++){
            if(Core(borad,s,0,i,j)){
                return true;
            }
        }
    }
    return false;
}

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
    if(( i > 0 && Core(board,s,wordIndex,i-1,y)) || ( j > 0 && Core(board,s,wordIndex,i,y-1) ) ||( i < board.size()-1 && Core(board,s,wordIndex,i+1,y)) || (j < board[0].size()-1 && Core(board,s,wordIndex,i,y+1)) ){
        return true;
    }
    board[i][j] = temp;
    return false;
}
int main(int argc,char*argv[]){
    string s;
    cin >>s ;
    bool res = exit(board,s);
    if(res){
        cout <<"true"<<endl;
    }else{
        cout <<"false"<<endl;
    }

}
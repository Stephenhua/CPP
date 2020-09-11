#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int X ,Y;
int StartX,StartY;
int endX ,endY;

vector<vector<int>> arr(11,vector<int>(11,0));
int  dp[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int res ;

/*
bool check(int x,int y,vector<vector<int>>& dp){
    if(x >= 0 && x <= X&& y >= 0 && y <= Y && arr[x][y]==0){
        return true;
    }
    return false;
}

void Core(int startx, int starty,int endx,int endy,int num){
    if( startx == endx && starty == endy ){
        if( num = X*Y-1){
              res++;
        }
        return ;
    }
    if(check(startx,starty,arr)){
        arr[startx][starty] = 1;
         Core(startx+1,starty,endx,endy,num+1) ;
         Core(startx-1,starty,endx,endy,num+1) ;
         Core(startx,starty-1,endx,endy,num+1) ;
         Core(startx,starty+1,endx,endy，num+1);
        arr[startx][starty] = 0;
    }
    return;
}*/

/*
题目：一个X*Y的方格，任意起始点，到达任意一点作为终点，有多少种遍历的方法；
方法：采用深度搜索的方法进行求解；DFS + 回溯；

*/
void dfs( int x, int y ,int cnt ){
    //回溯终止条件；
    if( x == endX && y == endY){
        if( cnt == endX*endY-1){
            res++;
        }
        return;
    }

    for(int i = 0 ;i < 4 ;i++){
        int xx = x+dp[i][0];
        int yy = y +dp[i][1];
        if(!(xx >= 0 && xx < X && yy >= 0 && yy < Y )){
            continue;
        }
        if(arr[xx][yy]){
            continue;
        }

        arr[xx][yy] = 1;
        dfs(xx,yy,cnt+1);
        arr[xx][yy] = 0 ;
    }

}

int main(int argc,char*argv[]){

    cin >> X >>Y ;

    cin >>StartX >> StartY;

    cin >> endX >> endY;

    dfs( StartX, StartY,0);
    cout << res << endl;
    system("pause");
    return 0 ;
}



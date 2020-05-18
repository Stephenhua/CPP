#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include <algorithm>
using namespace std;
int res_x,res_y,countH;

void FindPathCore(vector<vector<int>>& hei ,int x, int y){

    while( x>0 && x<hei[0].size()&& y>0&& y<hei.size()){
        hei[x+1][y] 
    }
}
void FindPath( vector<vector<int>>& hei ,int x, int y){
    if( x == 0 || y==0){
        res_x =x;
        res_y = y;
        countH =0;
    }else{

        FindPathCore( hei,x,y);
    }

}
int main(){

    int W ,H ;
    cin >> W >>H;
    int Position_X ,Position_Y;
    cin >>Position_X >>Position_Y;
    vector<vector<int>> Hei;
    for( int i=0 ;i <W ;i++){
        for( int j =0 ;j < H ;j++){
            int height ;
            cin >>height;
            Hei[i][j] = height;
        }
    }

    FindPath( Hei , Position_X ,Position_Y);
    
    cout << res_x <<" " << res_y <<" " <<countH <<endl;
    
    return 0 ;
}
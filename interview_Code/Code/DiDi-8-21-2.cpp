#include<iostream>
#include <vector>

using namespace std;

/*

题目：斐波那契数列+旋转矩阵；

*/

void core(vector<int >& arr, vector<vector<int>>& res){

    int size = res.size();
    int left = 0, right = size-1;
    int up= 0, down = size-1;
    int length = arr.size()-1;
    while (true)
    {
        for(int c =left ; c <= right;c++){
            res[up][c]=arr[length--];
        }
        if(++up > down ){
            break;
        }

        for(int c = up ;  c <= down ; c++ ){
            res[c][right]=arr[length--];
        }
        if( right-- < left ){
            break;
        }

        for(int c= right ;  c >=left; c--){
            res[down][c]=arr[length--];
        }
        if( --down < up ){
            break;
        }

        for(int c = down; c >=up;c--){
            res[c][left] = arr[length--];
        }
        if ( ++left > right){
            break;
        }

    }
    
}
int main( int argc, char* argv[]){
    int n ;
    cin >> n;

    vector<int> v(n*n);

    int first= 1 ;
    int second = 1 ;
    v[0] =1 ;
    v[1] = 1;
    //构建数列；
    for(int i = 2; i < n*n ;i++){
        v[i] = first+second;
        first =  second ;
        second = v[i];
    }

    //旋转矩阵；
    vector<vector<int>> res(n,vector<int>(n, 0 ));

    core(v,res);

    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j <n ; j++){
            cout<< res[i][j]<<" ";
        }
        cout <<endl;
    }
    system("pause");
    return 0 ;

}
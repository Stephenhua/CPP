#include<iostream>
#include <vector>

using namespace std;

/*

题目：斐波那契数列+旋转矩阵；

*/

void core(vector<int >& arr, vector<vector<int>>& res, int left ,int right ,int up ,int down ,int length){

    while (true)
    {
        for(int c =left ; length >= 0 && c <= right;c++){
            res[up][c]=arr[length--];
        }
        if(++up > down || length<0){
            break;
        }

        for(int c = up ; length >=0 && c <= down ; c++ ){
            res[c][right]=arr[length--];
        }
        if( right-- < right || length < 0 ){
            break;
        }

        for(int c= right ; length >= 0&& c >=left; c--){
            res[down][c]=arr[length--];
        }
        if( --down <up || length > 0){
            break;
        }

        for(int c = down; length >= 0 && c >=up;c++){
            res[left][c] = arr[length--];
        }

        if ( ++left >right || length >0 ){
            break;
        }

    }
    
   

    core(arr,res,left+1,right-1,up+1,down-1,length);

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

    core(v,res,0,n-1,0,n-1,n*n-1);

    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j <n ; j++){
            cout<< res[i][j]<<" ";
        }
        cout <<endl;
    }
    system("pause");
    return 0 ;

}
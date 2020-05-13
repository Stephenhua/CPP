
/*
  已知输入一个大矩阵 m 行 n 列，求第 i行到j行(包含)，a列 到 b列(包含)的和，要求计算的复杂度为O(1). 可以进行预处理。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void Process( vector<vector<int>> arr,int m, int n ,int a ,int b){

    int sumIA = 0;
    int i =0;
    int j=0;
    //左上方；
    for(;i<m;i++){
        for(;j<a;j++){
            sumIA += arr[i][j];
        }
    }
    //左下方
    int sumJA = 0;
    for( ;i<n;i++){
        for (int k=0;k<a;k++){
            sumJA += arr[i][j];
        }
    }
    //右上方；
    int sumIB=0;

    for(int l = 0 ; l<m ;l++){
        for( ;j<b;j++){
            sumIB +=arr[l][j];
        }
    }
    //中间部分
    int  SumJB = sumJA+sumIA+sumIB;
    for( int  c= m ; c<n ;c++ ){
        for(int d= a ;d < b ;d++){

            SumJB += arr[c][d];
        }
    }

    


}
int main( int argc, char* argv[]){

    int m ,n;
    cin >> m >> n;
    vector<vector<int>> Arr;

    for(int i = 0 ;i< m ;i++){
        for(int j =0 ;j<n ;j++){
            int temp ;
            cin >>temp;
            Arr[i][j] = temp;
        }
    }
    int i,j,a,b;

    Process(Arr,i,j,a,b);

    int sum =Caculate(i,j,a,b);

   cout << sum <<endl; 
}
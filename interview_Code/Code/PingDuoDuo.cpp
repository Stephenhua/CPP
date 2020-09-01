#include <iostream>
#include <vector>
using  namespace std;


void Core( int n ,vector<vector<int>>& dp){

    int res = n%2;
    int temp = n/2;

    if( res == 1){
        //奇数；
        for(int i = 0 ; i < temp; i++){
            for(int j = 0 ; j < temp;j++ ){
                if(i > j){
                      dp[i][j] = 3;
                }else if( i < j ){
                    dp[i][j] = 2;
                }
            }
            for(int j = temp+1 ; j<n ;j++){
                if( i+j < n-1 ){
                    dp[i][j] = 1;
                }else if(i+j>n-1){
                    dp[i][j] = 8;
                }
            }
        }
        for(int i =temp+1 ;i < n ;i++){
            for(int j=0 ; j< temp;j++){
                if(i+j < n-1){
                    dp[i][j]=4;
                }else if(i+j >n-1){
                    dp[i][j]=5;
                }
            }
            for(int j = temp+1 ;j < n ;j++){
                if( i < j ){
                    dp[i][j]=7;
                }else if( i > j ){
                    dp[i][j]=6;
                }
            }
        }
    }else {
        //偶数；
        for(int i = 0 ; i < temp; i++){
            for(int j = 0 ; j < temp;j++ ){
                if(i > j){
                      dp[i][j] = 3;
                }else if( i < j ){
                    dp[i][j] = 2;
                }
            }
            for(int j = temp ; j<n ;j++){
                if( i+j < n-1 ){
                    dp[i][j] = 1;
                }else if(i+j>n-1){
                    dp[i][j] = 8;
                }
            }
        }
        for(int i =temp ;i < n ;i++){
            for(int j=0 ; j< temp;j++){
                if(i+j < n-1){
                    dp[i][j]=4;
                }else if(i+j >n-1){
                    dp[i][j]=5;
                }
            }
            for(int j = temp ;j < n ;j++){
                if( i < j ){
                    dp[i][j]=7;
                }else if( i > j ){
                    dp[i][j]=6;
                }
            }
        }
    }
}

void Print(vector<vector<int>>& dp){
    int size = dp.size();
    for(int i =0 ;i < size ;i++){
        for(int j =0 ; j< size;j++){
            cout << dp[i][j]<<" ";
        }
        cout << endl;
    }
}
int main(int argc ,char* argv[]){
    int n;
    cin >> n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    Core(n,dp);
    Print(dp);
    system("pause");
    return 0 ;
}
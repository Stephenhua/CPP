#include <string.h>
#include <iostream>
#include <vector>



 using namespace std;

 int minDist( string s1, string s2){
     int length1 = s1.size();
     int length2 = s2.size();
     vector<vector<int> > dp(length1+1,vector<int>(length2+1,0));
     for(int i = 0; i < length1 ; i++){
         dp[i][0] = i+1 ;
     }
     for(int i =0;i < length2 ; i++ ){
         dp[0][i] = i+1;
     }

     for(int  i =1 ; i<=length1 ;i++){
         for(int j = 1 ; j <= length2 ; j++){
             if( s1[i] == s2[j]){
                 dp[i][j] = dp[i-1][j-1];
             }else{
                 dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
             }
         }
     }

     return dp[length1][length2];
 }

 int main(int argc, char* argv[]){

    int res = minDist(" ","abc");
    int res1 = minDist("abcd"," ");
    int res2 = minDist( "horse","rose");

    cout <<res <<endl;
    cout <<res1 << endl;
    system("pause");
    return 0 ;
 }

#include<iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;



int getMinTime(vector<vector<int>>& res , int X){

    int size = res.size();
   vector<int> dp(size,res[0][0]);
   for(int i = 1; i< size;i++){
       dp[i] = res[0][i] +dp[i-1];
   }

   for( int i = 1 ;i <size; i++){
       dp[0] += res[i][0];
       for(int i = 1 ;i < size; i++){
           dp[j] = res[i][j]+min(dp[j],dp[j-1]);
       }
   }
    return dp[X-1];
}

int main(){
    int N,P;
    cin >>N;
    cin >>P;

    vector<vector<int>> dp(P,vector<int>(P,INT_MAX));
    while (P>0)
    {
        int r,w,val;
        cin >>r;
        cin>>w;
        cin>>val;
        dp[r][w] = val;
        P--;
    }

    int X ;
    cin >>X;

    int result = getMinTime(dp,X);

    cout <<result<<endl;

    return 0;  
}


int FindMaxValue( vector<int>& val ,vector<int>& day){
            int size = val.size();
        vector<vector<int>> dp(size,vector<int>(size,0));

        for(int i= 0 ;i < size;i++){
            dp[i][0] = 0;
        }

        for( int j = 0 ; j <size ;j++){
            dp[0][j] = 0;
        }

        for( int i = 1; i < size ;i++){
            for(int j =1 ;j <size;j++){
                if(j < day[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-day[i]]+val[i]);
                }
            }
        }

        return dp[size-1][size-1];
    }


int main(){


    int N ,X ;
    cin >>N;
    cin >>X;
    vector<int> val(N,0);
    vector<int> day(N,0);
    
    for(int i= 0 ;i < N ;i++)
        int A ;
        int B ;
        cin >>A;
        cin >> B ;
        val[i] =A;
        day[i] =B;
    }

    int res = FindMaxValue(val,day);
    cout <<res << endl;
    return 0 ;


}


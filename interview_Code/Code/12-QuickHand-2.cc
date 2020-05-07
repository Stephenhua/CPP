#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
#include <assert.h>
#include <map>
using namespace std;

map<pair<long long , long long > , long long > m;

void temp_add( long long i ,long long j , long long c){
    if( i > j && i ==2*j){
        m[{j,i}] += c;
        return;
    }else if( j> i && j == 2*i){
        m[{i,j}] += c;
    }
    else if( i == j){
        return;
    }

    if( j > i ){
        m[{j/2 , j}] += c;
        temp_add( i, j/2 ,c);
    }else{
        m[{i,i/2}] += c;
        temp_add( i/2, j,c);
    }
}

void getSum( long long i , long long j ,long long &res){
    if( i>j && i == 2*j){
        res += m[{j,i}];
    }else if( j >i && j == 2*i){
        res += m[{i,j}];
    }
    //判断右子树的值；
    if( i == j){
        return ;
    }

    if( j > i ){
        res += m[{j/2, j}];
        getSum(i,j/2,res);
    }else{
        res += m[{i/2 , i}];
        getSum( i/2, j , res);
    }
}
int main(){

    int n ;
    cin >> n;

    while( n--){
        int num ;
        cin >>num;
        if( num == 1 ){
            long long a,b,c;
            cin >> a ;
            cin >> b;
            cin >> c;

            temp_add( a,b,c);
        }else{
            long long a,b;
            cin >>a >> b;
            long long result = 0 ;
            getSum( a ,b ,res) ;
            cout << result << endl ;
        }
    }

    return 0 ;
}
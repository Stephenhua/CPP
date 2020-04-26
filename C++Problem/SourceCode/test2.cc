#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
map<pair <long long , long long> , long long > m ;

void add ( long long i , long long j , long long c){
    if( i > j && i == 2*j){
        m[{j,i}] += c;
        return ;
    }else if( j>i && j == 2*i){
        m[{i,j}] +=c;
        return ;
    }
    else if( j == i){
        return ;
    }

    if( j > i){
        m[{ j/2, j}] += c;
        add(i,j/2 ,c);
    }else{
        m[{i/2,i}] += c;
        add( i/2, j , c);
    }
}

void getSum( long long i , long long j, long long &res){

    if( i >j && i = 2*j ){
        res += m[{j,i}];

    }
}
int main(){
    int n;
    cin >> n ;
    vector<vector<long>> res;

    vector<vector<long>> temp;

    vector<vector<long>> Dis[1000000][1000000000];

    for(int i=1; i<=n ;i++){
        long long u,v,w;
        long j ;
        cin >> j >> u >>v >>w ;
        vector<long> result ;
        result.push_back(j) ;
        result.push_back(u) ;
        result.push_back( v);
        result.push_back(w) ;

        res.push_back(result);

        if(n ==1 ){

            if(j == 1){
                cout <<0 <<endl;
            }else if( j==2){
                cout <<0 <<endl;
            }
        }else{
            if( j == 1){
                //进行矩阵更新
            }else if( j == 2){
                //进行矩阵求和运算；
            }
        }

    }

    system("pause");
    return 0 ;

}
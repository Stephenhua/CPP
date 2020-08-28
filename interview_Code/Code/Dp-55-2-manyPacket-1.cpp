#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
题目：多重背包
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<vi,wi,si≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10

特点：每个物品的个数发生了改变，所以基于此，需要对节点的个数进行修改；

*/

//方法一：普通算法；

int main( int argc, char* argv[]){
    
    int n,m ;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    vector<int> v(n+1,0);
    vector<int> w(n+1,0);
    vector<int> s(n+1,0);

    for(int i = 1 ;i <= n ;i++){
        cin >> v[i] >> w[i] >> s[i];
    }

    for( int i= 1 ; i <=n ; i++){//遍历每个元素；
        for(int j = m ; j >=0 ;j--){//从最高的体积进行递减遍历；
            for(int k=0 ; k <=s[i] ; k++){//依次取个数，
                if( j >= k*v[i]){
                    dp[i][j] = max( dp[i][j] ,dp[i-1][j-k*v[i]]+ k*w[i]);
                }
            }
        }
    }

    cout << dp[n][m] << endl;
    system("pause");
    return  0;
}

//方法二：进行降维，这时候只需要对重量进行降序既可以；

int main( int argc, char* argv[]){
    
    int n,m ;
    cin >> n >> m;
    vector<int> dp(m+1,0);

    vector<int> v(n+1,0);
    vector<int> w(n+1,0);
    vector<int> s(n+1,0);

    for(int i = 1 ;i <= n ;i++){
        cin >> v[i] >> w[i] >> s[i];
    }

    for( int i= 1 ; i <=n ; i++){//遍历每个元素；
        for(int j = m ; j >=0 ;j--){//从最高的体积进行递减遍历；
            for(int k=0 ; k <=s[i] ; k++){//依次取个数，
                if( j >= k*v[i]){
                    dp[j] = max( dp[j] ,dp[j-k*v[i]]+ k*w[i]);
                }
            }
        }
    }

    cout << dp[m] << endl;
    system("pause");
    return  0;
}
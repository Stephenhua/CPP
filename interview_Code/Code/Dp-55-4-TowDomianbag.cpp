/*
题目：二维费用的背包问题
有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。

每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。

接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V,M≤100
0<vi,mi≤100
0<wi≤1000
输入样例
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6
输出样例：
8
*/

/*
题解：0-1背包的变形，加了一个限制条件；实际还是0-1背包问题；
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;

int n ,V ,M;//n表示个数，V表示体积，M表示重量；
int dp[N][N];

int main( int argc ,char* argv[]){
    cin >> n >> V >>M;

    for(int i = 0 ;i < n ; i++){
        int v,m,w;//v表示体积；m表示价值；W表重量；
        cin >> v >> m >> w;

        for(int j = V ; j>=v ; j--){
            for(int k = M ;k >= m; k--){
                dp[j][k] = max( dp[j][k] , dp[j-v][k-m]+w);
            }
        }
    }

    cout << dp[V][M] << endl;
    system("pause");
    return 0 ;
}

//方法二：

int main ( int argc, char* argv[]){
    int n ,V,M;
    cin >> n >>V >> M;
    vector<int> v(n,0);
    vector<int> m(n,0);
    vector<int> w(n,0);

    for(int i = 0 ; i < n ;i++){
        cin >>v[i] >> m[i] >> w[i];
    }
//数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。
    vector<vector<int>> dp(2*V,vector<int>(2*M,0));
    for(int i = 0 ; i < n ;i++){
        for(int j = V ; j>=v[i] ;j--){
            for(int k = M ; k >= m[i] ;k--){
                dp[j][k] = max( dp[j][k] , dp[j-v[i]][k-m[i]]+w[i]);
            }
        }
    }

    cout << dp[V][M] << endl;
    system("pause");
    return 0 ;
}
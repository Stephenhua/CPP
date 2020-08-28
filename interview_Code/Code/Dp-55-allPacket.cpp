#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
有 N种物品和一个容量是 V 的背包，每种物品都有无限件可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi, wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000

输入样例
4 5
1 2
2 4
3 4
4 5
输出样例
10
*/

/*
完全背包：每一个物品不限使用次数
dp[i][j]表示选择前i物品，选出的物品体积不大于j ，物品最大价值；
状态选择：
    第一个物品选择 0， 1，，2,3,4,5,6，；
    dp[i][j] =max(dp[i][j-0*v]+ v0 , dp[i][j-1*v] +v1 ,dp[i][j-2*v]+2v ,)
根据上面的要求，可以写出基础版本的完全背包问题；
*/

int main( int argc ,char* argv[]){
    int n , m ;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> v(n+1,0);
    vector<int> w(n+1,0);

    //此处需要注意序号
    for(int i = 1 ;i <= n ; i++ ){
        cin >> v[i] >> w[i];
    }

    //核心代码；
    for( int i = 1 ;i <= n ;i++){
        for(int j= 0 ;j <= m ;j++){
            for(int k =0 ; k*v[i] <= j ;k++){
                dp[i][j] = max(dp[i][j] ,dp[i-1][j-k*v[i]] + k*w[i]);
            }
        }
    }

    cout << dp[n][m] << endl;

    system("pause");
    return 0 ;
}
/*
const int N = 1010;
int f[N][N];
int v[N],w[N];
int main()
{
    int n,m;
   cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = 0 ; j<=m ;j++)
    {
        for(int k = 0 ; k*v[i]<=j ; k++)
            f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
    }

    cout<<f[n][m]<<endl;
    system("pause");
    return 0 ;
}*/

/*
优化思路：
f[i][j] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....),当k=0,1,2,3,4,5,6....
对于上式减去一个重量 v;
即等式两边就会变成：
f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-2*v]+2*w , .....)
如果对于（2）式中，加上 w，相当于加上价值，那么等式2就会变成；
f[i , j-v]+ w = max(            f[i-1,j-v]+ w ,f[i-1,j-2*v] + 2w , f[i-1,j-2*v]+3*w , .....)
此时就会发现等式就是等式（1）中的一部分，所以等式（1）就可以变为

f[i][j] = max( f[i-1][j] , f[i-1][j-v]+w);

根据上面的思路就可以写出下面的等式；
*/


int main( int argc ,char* argv[]){
    int n , m ;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> v(n+1,0);
    vector<int> w(n+1,0);

    //此处需要注意序号
    for(int i = 1 ;i <= n ; i++ ){
        cin >> v[i] >> w[i];
    }

    //核心代码；
    for( int i = 1 ;i <= n ;i++){
        for(int j= 0 ;j <= m ;j++){
            dp[i][j]= dp[i-1][j];//相当于此时没有进行添加；
            if( j >= v[i]){
                dp[i][j] = max(dp[i][j] ,dp[i-1][j-v[i]] + w[i]);
            }
        }
    }

    cout << dp[n][m] << endl;

    system("pause");
    return 0 ;
}

//实现降维变换；

int main( int argc ,char* argv[]){
    int n , m ;
    cin >> n >> m;
    vector<int> dp(m+1,0);
    vector<int> v(n+1,0);
    vector<int> w(n+1,0);

    //此处需要注意序号
    for(int i = 1 ;i <= n ; i++ ){
        cin >> v[i] >> w[i];
    }

    //核心代码；
    for( int i = 1 ;i <= n ;i++){
        for(int j= v[i] ;j <= m ;j++){//进行正序就可以；
            
            dp[j] = max(dp[j] ,dp[j-v[i]] + w[i]);
        }
    }

    cout << dp[m] << endl;

    system("pause");
    return 0 ;
}
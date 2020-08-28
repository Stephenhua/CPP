/*
题目：分组背包；
有 N 组物品和一个容量是 V 的背包。

每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

输出最大价值。

输入格式
第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。

接下来有 N 组数据：

每组数据第一行有一个整数 Si，表示第 i 个物品组的物品数量；
每组数据接下来有 Si 行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i 个物品组的第 j 个物品的体积和价值；
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<Si≤100
0<vij,wij≤100
输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/

#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char* argv[] ){
    int n , m ;
    cin >> n >> m ;//n表示物品组数，m表示背包的容量；

    vector<vector<int>> v(101,vector<int>(101,0));
    vector<vector<int>> w(101,vector<int>(101,0));
    vector<vector<int>> dp(101,vector<int>(101,0));
    
    vector<int> s(101,0);
    for(int i = 1 ;i <= n ;i++){
        cin >>s[i];
        for(int j = 0 ;j < s[i] ;j++){
            cin >> v[i][j] >> w[i][j] ;
        }
    }
//dp[i][j]表示第i组，重量为j时，它的最大价值；
    for(int i = 1 ;i <= n ; i++){//遍历整个数组；
        for(int j = 0 ; j <= m ;j++){//重量的变化；
            dp[i][j] = dp[i-1][j];//当不变化的时候；
            for(int k =0 ; k <s[i] ; k ++){//某一个组内，顺序；
                if( j >= v[i][k]){
                    dp[i][j] = max( dp[i][j] , dp[i-1][j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    cout << dp[n][m] <<endl;
    system("pause");
    return 0 ;
}

//方法二：还是按照0-1背包的方法进行求解；
int main( int argc, char* argv[] ){
    int n , m ;
    cin >> n >> m ;//n表示物品组数，m表示背包的容量；

    vector<vector<int>> v(101,vector<int>(101,0));
    vector<vector<int>> w(101,vector<int>(101,0));
    vector<int> dp(101,0);
    
    vector<int> s(101,0);
    for(int i = 1 ;i <= n ;i++){
        cin >>s[i];
        for(int j = 0 ;j < s[i] ;j++){
            cin >> v[i][j] >> w[i][j] ;
        }
    }
//dp[i][j]表示第i组，重量为j时，它的最大价值；
    for(int i = 1 ;i <= n ; i++){//遍历整个数组；
        for(int j = m; j >= 0 ;j--){//重量的变化；
            for(int k =0 ; k <s[i] ; k ++){//某一个组内，顺序；
// 不能合并为for(int k=0; k < s[i] && v[i][k]<=j; k++)
// 当不满足条件v[i][k]<=j时，就退出for循环，后面的k即使满足v[i][k]<=j也无法执行                
                if( j >= v[i][k]){
                    dp[j] = max( dp[j] , dp[j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    cout << dp[m] << endl;
    system("pause");
    return 0 ;
}

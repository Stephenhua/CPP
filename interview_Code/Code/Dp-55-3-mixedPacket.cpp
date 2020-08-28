/*
题目：
题目描述
有 N 种物品和一个容量是 V的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si次（多重背包）；
每种体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

样例
输入
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
输出
8
*/

/*
方法一：混合算法进行求解；
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int N = 1010;
int n ,m ;
int f[N];

struct Thing
{
    int kind;
    int v,w;
};

vector<Thing> things;

int main( int argc, char* argv[] ){

    cin >> n >> m;
    //将背包问题全部转换为0-1背包和完全背包；

    for(int i= 0 ; i< n ; i++){

        int v,w,s;

        cin >> v >>w >>s;

        if(s < 0 ){
            things.push_back({-1,v,w});
        }else if( s == 0 ){
            things.push_back({0,v,w});
        }else{
            for(int k = 1 ; k <= s ; k*= 2 ){
                s -= k ;
                things.push_back({-1,v*k,w*k});//k表示个数；
            }
            if( s > 0 ){
                things.push_back({-1,v*s, w*s});
            }
        }
    }

    for( auto thing : things ){
        if( thing.kind < 0 ){
            for(int j = m ; j >= thing.v ; j--){
                f[j] = max(f[j] ,f[j-thing.v]+thing.w);
            }
        }else{
            for(int j = thing.v ; j <= m ; j++){
                f[j] = max( f[j] , f[j-thing.v]+ thing.w);
            }
        }
    }

    cout << f[m] << endl;
    system("pause");
    return 0 ;
}

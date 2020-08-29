/*
题目描述
有 NN 件物品和一个容量是 VV 的背包。每件物品只能使用一次。

第 ii 件物品的体积是 vivi，价值是 wiwi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7109+7 的结果。

输入样例
4 5
1 2
2 4
3 4
4 6
输出样例
2
*/

/*
思路：将价值和方案数分别建立数组，V[i]表示存储背包体积为i时的最佳方案总价值；
cnt[i]表示背包容积为i时，总价值为最佳的方案数；
比较，当装第i个物品时的价值与不装第i个物品的价值之间的关系；
如果装入后的方案总价值更大，
    那么V[j-v[i]] +w[i] 更新 V[i];
    cnt[j] 就会变为 cnt[j-v]；由于当前不是最大总价值，所以方案树为cnt[j-v]；
如果装入的值是最大的价值；
那么就会更新最大价值的方案数；
*/

#include <iostream>
#include <vector>
using namespace std;

int main( int argc ,char* argv[]){
    int mod = 1e9+7;
    int n , m ;
    cin >> n >> m;
    vector<int> v(n+1,0);
    vector<int> w(n+1,0);
    vector<int> cnt(m+1,1);
    vector<int> f(m+1,0);
    for(int i = 1 ; i<=n ; i++){
        cin >> v[i] >> w[i] ;
    }

    for(int i =1 ;i <= n ;i++){
        for(int j = m ; j >= v[i] ; j--){

            int value = f[j-v[i]] +w[i];
            //此处的f[j]表示不装入；f[j] = f[j-1];
            if( value > f[j] ){
                f[j] = value;
                cnt[j] = cnt[j-v[i]];
            }else if( value == f[j] ){
                cnt[j] = (cnt[j]+cnt[j-v[i]]) %mod;
            }
        }
    }

    cout << cnt[m] << endl;
    system("pause");
    return 0 ;

}
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
using namespace std;

/*
题目和 manyPacket-1相同，

限制条件：实现二进制优化，如果数据范围发生了改变，应该如何改变；
数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
*/

/*
解题思路：
1）进行二进制拆分；所有的数都都可以转换为二进制，所以基于此，将数据进行分割；

*/

int main(int argc, char* argv[]){
    int n ,m ;
    cin>>n >> m;

    vector<int> dp(250000,0);

    vector<int> v(n+1,0);
    vector<int> w(n+1,0);
    vector<int> s(n+1,0);
    vector<int>  a(25000,0),b(25000,0);

    for(int i = 1 ;i <= n ;i++){
        cin >> v[i] >> w[i] >> s[i];
    }

    int total = 0 ;
    for(int i = 1 ;i <=n ;i++){
        for(int j = 1 ; j < s[i] ;j <<=1){
            a[total] = j*w[i];//存储价值；
            b[total++] = j* v[i] ;//存容量；
            s[i]-=j;
        }

        if(s[i]){//如果s[i]  > 0;对于不是2的倍数，还有余数，那么应该直接进行存储；
            a[total] =  s[i] * w[i];
            b[total++] = s[i] * v[i];
        }
    }

    for(int i = 0 ;i < total ;i++){
        for(int j = m; j>=b[i] ; j--){
            dp[j] = max(dp[j] , dp[j-b[i]]+a[i]);
        }
    }
    cout << dp[m] << endl;
    system("pause");
    return 0 ;
}
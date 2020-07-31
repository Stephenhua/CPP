#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
题目：京都有n个驿站排成一行，且从左到右由1~n依次编号，并且有（n-1）个道路相连的驿站。对于每条道路都有一个权重；
小强定义：当每次经过一次道路，其对应权重减1，但你会获得1分的价值；
现在请帮小强计算出在选择任意的一个站点作为起点，并且满足不经过权重为0 的道路的条件下，所能多的最大价值是多少？

输入描述：
1）第一行输入一个正整数n,表示驿站的数量；
第二行表示n-1个正整数a[i]（1<i<n）；表示驿站i到i+1之间道路的初始权重；
1《n< 100000; 1 < a[i] < 1------ ;

输出描述：
输出一个整数表示答案；
*/

/*

思路：动态规划

作者：tuogy
链接：https://www.nowcoder.com/discuss/462000
来源：牛客网

分析：题中涉及到一个图An，An的n个顶点是n个客栈。其中第k-1个客栈到第k个客栈的边的权重用v[k-1]表示。我们采用动态规划去求解这个问题。假设Lk是由第0,…,k个客栈所组成的An的子图，Rk是由第k, …,n-1个客栈所组成的An的子图。

作者：tuogy
链接：https://www.nowcoder.com/discuss/462000
来源：牛客网

定义以下变量：
1）-f_l[k] // 从第k个客栈出发，在L_k中获得的最大利益
2）-f_r[k] // 从第k个客栈出发，在R_k中获得的最大利益
3）-g_l[k] // 从第k个客栈出发，并在第k个客栈结束，在L_k中获得的最大利益
4）-g_r[k] // 从第k个客栈出发，并在第k个客栈结束，在R_k中获得的最大利益

如果v[k-1]是奇数，那么：

    f_l[k] = f_l[k-1] + v[k-1]  // 首先在客栈k-1和k中反复横跳耗尽该边的权重
    g_l[k] = (v[k-1] > 1) ? (g_l[k-1] + v[k-1] - 1) : 0 
    // 因为要回到出发点，v[k-1]只能遍历偶数次


如果v[k-1]是奇数，那么：

    g_l[k] = (v[k-1] > 0) ? (g_l[k-1] + v[k-1]) : 0  
    //在客栈k-1和k中反复横跳耗尽该边的权重
    f_l[k] = max((v[k-1] > 0) ? (f_l[k-1] + v[k-1] - 1) : 0, g_l[k])  
    // 要么最终回到客栈k；要么不回到客栈k，但此时v[k-1]只能遍历奇数次
作者：tuogy
链接：https://www.nowcoder.com/discuss/462000
来源：牛客网

我们可以令k=0,1,...,n-1，利用DP计算出所有的f_l[k], g_l[k]。初始条件显然有f_l[0] = g_l[0] = 0。
对f_r[k]和g_r[k]的计算是完全对称的，只不过按照k=n-1,...,1,0逆序计算。时间复杂度为O(n)。

在计算出了f_l, f_r, g_l, g_r后，我们考虑计算原问题的解。假设我们从第k个客栈出发，并在第k’个客栈结束。
如果k’≤k，最大收益为f_l[k]+g_r[k]。因为对于客栈k右边的权值，我们必须从第k个客栈出发开始遍历，并最终回到第k个客栈。类似地，
如果k’≥k，最大收益为f_r[k]+g_l[k]。
因此，原问题的解为max((fl[k]+gr[k],fr(k)+gl[k])) ，可以在O(n)的时间内求解。

*/

int slove(){
    int n ,ret = 0 ;

    cin >> n ;

    vector<int> v(n-1),f_l(n,0),f_r(n,0),g_l(n,0),g_r(n,0);

    for( int i = 0 ; i < n -1 ; i++){
        cin >> v[i];
    }

    for( int k =1 ; k<n ; k++){
        if( v[k-1] & 1){
            f_l[k] = f_l[k-1] +v[k-1];
            g_l[k] = v[k-1] >1 ? g_l[k-1]+v[k-1]-1:0;
        }else{
            g_l[k] = v[k-1]? g_l[k-1]+v[k-1] : 0;
            f_l[k] = max( g_l[k],v[k-1]?f_l[k-1]+v[k-1]-1:0);
        }
    }


    for( int k = n -2 ; k >= 0 ; k--){
        if( v[k]&1){
            f_r[k] = f_r[k+1] +v[k];
            g_r[k] = v[k] > 1 ? g_r[k+1]+v[k]-1:0;
        }else{
            g_r[k] = v[k] ? g_r[k+1]+v[k] :0;
            f_r[k] = max( g_r[k],v[k] ? f_r[k+1]+v[k]-1:0);
        }
    }

    for( int k = 0 ; k < n ; k++){
        ret = max( ret, max( f_l[k]+g_r[k],f_r[k]+g_l[k]));
    }

    return ret;
}
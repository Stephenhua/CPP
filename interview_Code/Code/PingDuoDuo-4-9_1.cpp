
#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

/*
求出在1到N之间能背集合M中的元素整除的个数
这是一道简单的容斥原理应用题。先找出1...n内能被集合中任意一个元素整除的个数，再减去能被集合中任意两个整除的个数，即能被它们两只的最小公倍数整除的个数，因为这部分被计算了两次，然后又加上三个时候的个数，然后又减去四个时候的倍数...。用dfs得到集合M中所有元素的组合，
从0到n-1枚举当前数的所有组合情况，组合数为奇的加，为偶的减。题目要注意除去M集合中为0的数，它对最后的结果没影响，但会对gcd造成影响。
*/
int N,M,num,t,c[15];

//求解最大公约数；
long long gcd( long long a, long long b ){

    return b ==0?a:gcd(b,a%b);

}
void dfs(int i ,int flag ,int k){
    k = k*c[i]/gcd(k,c[i]);//最小公倍数；
    if(flag == 1 ){
        num +=N/k;
    }else {
        num -=N/k;
    }


    for(int j = i+1;j < M ;j++){
        dfs(j,!flag,k);
    }

}
int main( int argc ,char* argv[]){
/*
    cin >> N >> M;
    for(int i = 0 ; i < M; i++){
        cin >> c[i];
    }
    N--;
    for(int i =0 ; i<M;i++){
        dfs(i,1,c[i]);
    }
*/
    long long  res = gcd(100,5);
    cout << res << endl;
    system("pause");
    return 0;
}
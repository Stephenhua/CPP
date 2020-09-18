#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
const int  maxNum = 2e5+5;
struct node
{
    int  left ;
    int rihgt ;
    int value ;
       /* data */
};
node Node[maxNum];
int pre[maxNum];
int dep[maxNum];
int fat[maxNum];

int treeConstruct( int v, int f ){
    int x ;
    int now = ++cnt ;
    cin >> x;
    Node[now].value = x;
    dep[now] = v;
    fat[now] = f;
    
    if( x != -1){
        pre[x] = now;
        Node[now].left = treeConstruct(v+1,now);
        Node[now].rihgt = treeConstruct(v+1,now);
    }
    
}
int Fath(int a, int b ){

    if( dep[a] < dep[b]){
        swap( a,b);
    }

    int x = dep[a] -dep[b];
    for(int i = 0 ; i <= 28 ;i++){
        if( x&( 1 <<i )){
            a =dp[a][i];
        }
    }

    if
    return Node[a].value;
    
}
int Fath(int a, int b ){

    if( dep[a] < dep[b]){
        swap( a,b);
    }

    while (dep[a] != dep[b])
    {
        a = fat[a];
    }

    while (a != b)
    {
        a = fat[a];
        b = fat[b];
    }
    return Node[a].value;
    
}
int main( int argc, char* argv[] ){

    treeConstruct(1,0);
    int n ,m;
    cin >> n >> m;
    int res = Fath(n, m);
    return 0 ;
}
//https://www.jianshu.com/p/0bbf1fcbe070


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
#define max_len 9
int TheNthDigit(long long f[], int n){
    if(n<0){
        return -1;
    }

    if(n<=9){
        return n;
    }

    int pos=0;
    for(int i=1;i<=max_len;i++){
        if(f[i]>=n){
            pos=i;
            break;
        }

    }

    n=n-f[pos-1];
    int temp1=n/pos;
    int temp2=n%pos;
    int temp3= temp1+pow(10,pos-1);

    return (int)(temp3/pow(10,pos-temp2-1))%10;
}

int main(){
    long long f[] = {0,10,190,2890,38890,488890,5888890,68888890,788888890,8888888890};//初始化长度数组
    int n;
    cin >> n;
    cout<<TheNthDigit(f,n)<<endl;
    system("pause");
    return 0;
}
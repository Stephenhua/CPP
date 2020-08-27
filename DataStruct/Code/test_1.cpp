#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace  std;
char a[255];
int cnt = 0 ;

int reverseNum(int n ){
    if( n == 0 ){
        return 0 ;
    }
    vector<int> sta;
    int temp =0 ;
    while( n >= 10){
        temp = n % 10;
        sta.push_back(temp);
        n = n/10;
    }
    sta.push_back(n);
    int res = 0 ;
    int i=0 ;
    for(i =0 ;i <sta.size() ;i++){
        if(sta[i] !=0 ){
            break;
        }
    }

    for(int j = i ; j< sta.size() ;j++){
        res = res*10 +sta[j];
    }
    return res;
}

int tenTofive(int num){
    while(num){
        a[cnt++] = num% 5;
        num = num/5;
    }

    int res = 0 ;
    for(int i =cnt -1 ; i>=0; i--){
        res =res*10 +a[i];
    }
    return res;
}
int main(int argc ,char* argv[]){
    int n;
    cin>>n;
    int revsernum = reverseNum(n);
    int res = tenTofive(revsernum);
    cout <<res << endl;
    system("pause");
    return 0 ;
}

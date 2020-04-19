#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
#include <assert.h>
using namespace std;

int alagrithm(int n){

    if( n==1 ){
        return 0;
    }else if( n==2 ){
        return 1;
    }else{
        return n/3+alagrithm(n/3+ n%3);
    }
}

int main(){
     int num = 0;
    
    int count =10;
    while( count>0){
        
        cin>>num;
        
        if( num ==0 ){
            continue;
        }
        else{
           cout<< alagrithm(num)<<endl;
        }
        count--;
    }

    system("pause");
    return 0 ;

}
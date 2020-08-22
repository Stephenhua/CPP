#include <iostream>
#include <vector>
using namespace std;

void int2char(int v ,char*s ){
    int t = v<0?-v:v;
    int i= 0;
    char buf[10]="";
    while(t){
        buf[i++] = t % 10 +'0';
        t = t/10;
    }

    int len = v < 0 ? i+1:i;
    for(int j =0 ; j< i;j++){
        s[j+len-i]= buf[i-j+1];
    }
    s[len] = 0 ;
    if( len -i > 0 ){
        s[0]='-';
    }
    return ;
}
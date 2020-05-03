#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define M 1010


//方法二：采用另一种形式进行求解；


int a[M] ,b[M] ,c[M];
string s1 ,s2 ;

void addCore( int len ){

    memset( c,0,sizeof(c));

    for(int i = 1 ;i<= len ;i++){

        c[i] = a[i]+b[i] + c[i];

        c[i+1] = c[i] /10;

        c[i] %= 10;
    }

    if(c[len+1] ){
         len++ ;
    }

}

void add( string s1,string s2){

    memset( a, 0 ,sizeof(a));
    memset( b, 0 ,sizeof(b));

    for(int i = 0, j=s1.length() ; i<s1.length() , j >0 ;++i , j-- ){
        a[j] = s1[i] - '0';
    }

    for(int i = 0 ,j = s2.length() ;i <s2.length(), j>0 ;++i ,j--){
        b[j] = s2[i] -'0';
    }

    int len = max( s1.length() ,s2.length());

    addCore( len );

    for(int i=len ;i>0 ;i--){
        cout <<c[i];
    }
    cout <<endl;

}

int main( int argc ,char* argv[]){
    
    cin >>s1>>s2;

    add(s1,s2);
    system("pause");
    return 0 ;

}
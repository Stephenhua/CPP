#include <iostream>
#include <vector>

using namespace std;

int main (){
    int num;
    int res = 0 ;

    cin >>num ;

    while( num){

        res = res*10 + num%10;
        
        num /= 10;
    }

    cout <<res <<endl;
   int result = 0;

    int n ;
    cin >>n ;

    for( ; n ; n/=10){
        
        result = result *10 +n%10 ;

    }

    cout <<result <<endl;

    system("pause");
    return 0 ;

}
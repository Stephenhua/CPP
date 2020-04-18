#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double sqrt( double x){

    double low = 0;
    double up = x;
    double mid = (low + up)/2;

    while( fabs(low-up) > 1e-6){

        if( mid * mid >x){
            up = mid ;
        }else if ( mid * mid < x){
            low = mid ;
        }else{
            return mid ;
        }
        mid = ( low + up )/2;
    }
    return mid ;
}

int main( int argc ,char * argv[]){

    double x = 9;
    
    double result = sqrt(x);

    cout << "result " << result << endl;

    system("pause");

    return 0 ;
}
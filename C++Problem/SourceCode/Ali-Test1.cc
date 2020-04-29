#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int T;
    cin >>T ;

    for(int i =0 ;i<T ;i++){
        int n , m ;
        cin >> n >> m ;
        if(n > 1000000){
            break;
        }
        map<int,unsigned long> a;

        for(int i=1;i<=n;i++){

            unsigned long value;
            cin >>value;
            a[i] =value;
        }
        unsigned long min = LONG_MAX;
        unsigned long sum = 0;
        for(int i =1;i<=n;i++){

            if( min >a[i]){

                min = a[i];
            }

            sum += a[i];
        }

        if( n >= m ){
            
            cout << min << endl;
        }else{

            int num = sum / m ;

            if( num < min){
                
                cout << num <<endl;
            }

        }

    }

    system("pause");
    return 0 ;

}
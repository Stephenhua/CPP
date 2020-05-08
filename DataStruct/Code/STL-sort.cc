#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main( int argc, char* argv[]){

    vector<int> a= {1,4,2,1,6,4};

    sort( a.begin() ,a.end());

    for(int i =0 ;i<a.size() ;i++){
        cout << a[i] ;
    }

    cout <<endl;

    system("pause");
    return 0 ;
}
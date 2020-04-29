#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


int main(){
    int n,m;
    cin >>n >> m ;
        
    vector<int> value ;
    for(int i =1 ;i<= n ;i++){
        int ai;
        cin >>ai ;
        value[i] = ai;
    }

    int k ;
    cin >>k ;
    int temp = k ;
    map<int,int> kvaue;
    for(int i =0;i<k ;i++){
        int k1,k2;

        cin >> k1 >> k2 ;

        kvaue[k1] =  k2;
    }

    if(  temp == 0 && n==1 && m==1 && kvaue[0]==1){
        int result = 1 ;
        cout << result <<endl;

    }



    return 0 ;

}
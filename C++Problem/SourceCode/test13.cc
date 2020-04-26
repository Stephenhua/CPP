#include <iostream>
#include <vector>

#include <map>

#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >>n ;
    if(n>18){
        return 0 ;
    }
    vector<int> temp_Postive(n);
    for(int i=0;i<n;i++){
        int temp ;
        cin>>temp;
        temp_Postive.push_back(temp);
    }
    cout <<endl;

    vector<int> temp_Neg(n);
    for(int i= 0 ;i< n;i++){
        int temp = 0 ;
        cin >>temp ;
        temp_Neg.push_back(temp);
    }

    
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int  main(){

    int n ;
    long int k ;
    
    cin >> n >> k;

    vector<int> value;

    for(int i=0;i<n ;i++){

        cin >> value[i];

    }
    
    sort(value.begin() , value.end());

    vector<pair<int,int>> temp ;
    for(int i=0 ; i<value.size() ; i++){
        for( int j=0; j<value.size() ; j++){
            pair<int,int > temp_value ;
            temp_value.first = i;
            temp_value.second = j ;
             temp.push_back(temp_value);
        }
    }

    //return temp[k-1];
    cout<<temp[k-1].first << temp[k-1].second <<endl;

    system("pause");
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){
    int n ;
    cin >> n;
    vector<int> eggSize(n,0);
    while( n ){
        int m ;
        cin >> m ;
        eggSize.push_back( m );
    }

    int res = 0 ;
    unordered_map<int,int> cal;
    int size = eggSize.size();

    int days = 1;

    while( days){

        for(int i =0 ; i<size ; i++){
            eggSize[i] = i+1;
            cal[eggSize[i]]++;
        }

        for( auto const & value : cal){
            
            if(value.second > 1 ){
                res = days;
                break;
            }
        }

        days++;

    }
    cout<< days << endl;
    return 0 ;
}
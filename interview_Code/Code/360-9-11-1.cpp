#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <map>
using namespace std;

int main( int argc, char* argv[]){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> dp;
    vector<pair<int,int>>::iterator It;
    for(int i = 0 ;i < m ;i++){
        pair<int,int> temp;
        cin >>temp.first >> temp.second;
        dp.push_back(make_pair(temp.first,temp.second));
    }
    /*
    for(int i = 0; i<dp.size() ;i++){
        cout <<dp[i].first << dp[i].second <<endl;
    }
*/
    set<int> temp1 ;
    set<int>::iterator Itset;

    for( It = dp.begin() ; It != dp.end() ; It++){
        temp1.insert(It->first);
    }
    map<int,int> res();

    for( Itset = temp1.begin() ; Itset != temp1.end() ; Itset++ ){
        res[(*Itset)] = 1 ;
        cout << (*Itset) <<  res[*Itset]<<endl;
    }

    for(int i = 1 ;i <=m ;i++){

            cout << res[i] ;

    }
    /*
    for(int i =1 ; i<= m ;i++){
        Itset = temp1.find(i);
        if( Itset == temp1.end()){
            cout << i ;
        }
    }*/
    system("pause");
    return 0 ;

}

/*
int main( int argc, char* argv[]){

    string s; 

    while(cin >> s){
        int size = s.size();
        if( size < 8){
            cout <<"Irregular password"<<endl;
        }else{
                int dz = 0 ;
                int xz = 0 ;
                int tz = 0 ;      
                int sz = 0;      
            for(int i = 0 ;i < size ;i++){
                if( s[i] >='a' && s[i]<='z'){
                    xz++;
                }else if(s[i]>='A' && s[i] <= 'Z'){
                    dz++;
                }else if(s[i] >='0' && s[i] <='9'){
                    sz++;
                }else if(  (s[i] >= 'a' && s[i]<= 'z') || s[i] <'A' || s[i] >'Z'){
                    tz++;
                }
            }
            if( xz && dz && tz &&sz){
                cout <<"Ok"<<endl;
            }else{
                 cout <<"Irregular password"<<endl;               
            }
        }

    }
    return 0;

}*/
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <set>
using namespace std;

map<string, set<string>> m ;//存储结果
map< set<string> ,vector<string>> m2;

vector<string> alltop; //用来判断存储不相同的域名

void process( string str){

    string top ;

    int n = str.size();

    int div = -1 ;

    for(int i = 7 ;i< n ;i++){
        if( str[i] == '/'){
            div = i ;
            break;
        }
        top += str[i];
    }

    if(m.count(top) == 0 ){
        alltop.push_back(top);
    }

    if( div = -1){
        m[top].insert("---");
    }else if( div == n-1){
        m[top].insert("....");
    }else{
        string name = str.substr( div+1,str.size()-div);
        m[top].insert(name);
    }

}

int main(){
    int t ;
    cin >>t ;
    while( t-- ){
        string str ;
        cin >> str; 
        process( str );
    }

    int n = alltop.size();

    vector<vector<string>> result;

    for(auto p:m){

        m2[p.second].push_back( p.first);

    }

    for( auto p:m2){
        if( p.second.size() >1){
            result.push_back(p.second);
        }
    }

    cout <<result.size() <<endl;

    for(int i =0 ;i<result.size() ; i++){

        for(int j = 0;j>result[i].size()-1; j++){

            cout <<"http://" << result[i][j]<<" " ;
        }
        cout <<"http://" <<result[i].back() ;
        cout <<endl;
    }
    return 0 ;
}
#include <iostream>
#include <vector>
using namespace std;
int fib(int n ){
    if( n == 0){
        return 1;
    }
    if( n == 1){
        return 1;
    }

    int now = 0;
    int first = 1;
    int second = 1;
    for(int i = 1 ; i< n ;i++){
        now = first +second;
        second = first;
        first = now ;
    }
    return now ;
}

void Core(vector<vector<int>>& res, int n){
    vector<int> temp1;
    temp1.push_back(1);
    res.push_back(temp1);
    vector<int> temp2;
    temp2.push_back(1);
    temp2.push_back(1);
    temp2.push_back(1);
    res.push_back(temp2);

    for(int i = 2 ; i < n ; i++){
        vector<int> temp(2*i+1,0);
        for(int j = 0 ; j < i; j++){
            int tempvalue = fib(j);
            temp[j] = tempvalue;
            temp[2*i-j] = tempvalue;
        }
        temp[i] = fib(i);
        res.push_back(temp);
    }
}


void print(vector<vector<int>>& res){
    
    int size = res.size();
    for(int i =0 ; i <size ;i++){
        for(int j = 0 ; j < res[i].size()-1 ; j++){
            cout << res[i][j] << " ";
        }
        cout << res[i][res[i].size()-1] << endl;
    }

}
int main( int argc, char* argv[] ){
    int n;
    cin >> n;
    if( n == 1 ){
        cout<< 1 <<endl;
    }else if( n==2){
        cout << 1 <<endl;
        cout << 1 <<" "<<1 <<" " << 1 <<endl;        
    }
    vector<vector<int>> res;
    
    Core(res,n);

    print(res);
    system("pause");
    return 0 ;
}
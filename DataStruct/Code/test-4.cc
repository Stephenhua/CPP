#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n , k ;

    cin >> n >> k ;
    
    cout << n <<","<<k <<endl;

    if( n==0 || k==0){
        return 0;
    }

    if( n == 1){
        return 1;
    }

    vector<int> temp;
    int value;
    for(int i = 0 ;i < n; i++){
        cin >> value;
        temp.push_back(value);
    }

    int midValue =(n+1)/2;
    int Position = 0;

    int start =0 ;
    int end = temp.size();

    while(start < end){
        cout <<"Start"<<start <<"end "<< end <<endl;
        int mid = (start+ end) >>2;

        if(temp[mid] > k){
            end = mid -1;
        }else if( temp[mid] < k){
            start = mid +1;
        }else{
            Position =mid;
        }
    }
    int result = abs(midValue - Position)+1;
    
    cout<< result <<endl;
    system("pause");
    return 0;
}
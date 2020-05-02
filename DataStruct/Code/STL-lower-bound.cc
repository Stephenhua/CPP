
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lowerBound( vector<int>& num,int x){
    int left = 0 ;
    int right =num.size();

    while(left <right){

        int mid = (left+right) /2;
        if( num[mid] >= x){
            right = mid;
        }else{
            left = mid+1;
        }

    }

    return left;
}

int main( int argc ,char* argv[]){

    vector<int> a={1,3,4,5,6};

    int result = lowerBound( a,3);

    cout<<"result "<< result <<endl;

    system("pause");
    return 0;
    
}
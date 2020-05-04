#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

vector<int> dailyTempture( vector<int> tempture){

    int n = tempture.size();

    stack<int> index; 
    vector<int> result(n,0) ;



    for(int i = 0; i< n ;i++){

        while( !index.empty() && tempture[i] >tempture[index.top()]){
            
            int top = index.top();

            index.pop();

            result[top] = i - top;
        }

        index.push(i);
    }

    return result;
}

int main( int argc ,char* argv[]){

    vector<int> temp = {32 ,42,12,23,24,25};

    vector<int> result = dailyTempture( temp);

    for(int i=0 ;i <result.size() ;i++){
        cout<< result[i] ;
    }
    cout <<endl;

    system("pause");
    return 0 ;
}
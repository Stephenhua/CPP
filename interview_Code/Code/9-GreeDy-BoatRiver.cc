#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <Windows.h>
using namespace std;

/*
题目：小船过河
N个人过河，船每次只能坐两个人，船载每个人过河的所需时间不同t[i]，
每次过河的时间为船上的人的较慢的那个，求最快的过河时间。(船划过去要有一个人划回来)

*/

int getTime( vector<int>& times){
    int time = 0;

    sort(times.begin() , times.end());
    int size = times.size();

    while( size >3){
        if( 2*times[0]+ times[size-1]+ times[1] > 2*times[0]+ times[size-2]+ times[size-1]){

            time += 2*times[0]+ times[size-2]+ times[size-1];
        }else{
            
            time += 2*times[0]+ times[size-1]+ times[1];
        }
        size = size -2 ;
    }

    if( size ==3){
        time += times[0]+ times[1] + times[2];
    }else if( size == 2){
        time += times[1];
    }else if( size == 1){
        time += times[0];
    }

    return time ;

}

int main( int argc ,char* argv[]){

    vector<int> times = {1,3,4,8,4,3,9};
    int time = getTime(times);
    cout<<time <<endl; 
    
    system("pause");
    return 0;
}
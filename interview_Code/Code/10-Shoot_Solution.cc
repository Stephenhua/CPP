#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <Windows.h>
using namespace std;

/*
题目：
一个射击运动员打靶，靶一共有10环，连开10 枪打中90环的可能的组合有多少种？
*/

void shootSolutions( int num ,int sum ,vector<int>& result ,int * total ){
    //int total = 0 ;

    if( sum <=0 || num*10 < sum){
        return ;
    }
    if( num == 1){
        

        if( sum <= 10){

            (*total)++;
            return ;
        }else{
            return;
        }
    }

    for(int i=0 ;i<=10 ;i++){

        result.push_back(i);

        shootSolutions(num-1 ,sum-i , result , total);

        result.pop_back();
    }
}

int main(int argc, char* argv[]){
    int num =10 ;
    int sum = 90 ;

    vector<int> result;
    

    static int total = 0;

    shootSolutions(num , sum , result ,&total );
    
    
    cout <<total <<endl;

    system("pause");
    return 0 ;
}
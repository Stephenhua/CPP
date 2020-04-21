#include<stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/*
题目：
在一维空间中告诉你N条线段的起始坐标与终止坐标，
要求求出这些线段一共覆盖了多大的长度。

*/

int LengthMax( vector<int> start , vector<int> end, int sum ){

    if(start.size()!=end.size()){
        return 0;
    }

    for(int i = 1,j = 0 ; i < start.size() ;i++){

        if( start[i] >= end[j] ){

            sum += (end[i]-start[j]);
            j = i ;

        }else{

            if( end[i] <= end[j]){
                continue;
            }else{

                sum += end[i]-end[j];

                j =i;
            }
        }
    }

    return sum ;
}

int main( int argc ,char * argv[]){

	vector<int> s= {2,3,4,5,6,7,8,9,10,11};
	vector<int> f = {3,5,7,6,9,8,12,10,13,15};
	int TotalLength = (3-2);   
    TotalLength=LengthMax( s,f,TotalLength);

    cout<< "TotalLength"<<TotalLength <<endl;

    system("pause");
    return 0;
}
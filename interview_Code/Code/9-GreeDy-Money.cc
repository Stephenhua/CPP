#include<stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
/*
题目：指定币值和相应的数量，用最少的数量凑齐某金额。
*/

vector<int> getMoneyNumber( int sum , vector<int> values, vector<int> numbers){

    vector<int> result;

    int add = 0 ;

    for(int i= values.size()-1; i>= 0 ;i-- ){

        int num = (sum - add) / values[i];

        if(num > numbers[i]){
            num = numbers[i];
        }
        add = add+ values[i]*num;
        result.push_back(num) ;
    }
    return result;

}

int main ( int argc ,char * argv[]){

    vector<int> values = { 1, 2, 5, 10, 20, 50, 100 };
    vector<int> counts = { 3, 3, 2, 1, 1, 3, 3 };

    vector<int> result = getMoneyNumber( 435, values ,counts);

    for(int i =0 ;i<result.size(); i++){
        cout<<"Values"<<values[i] << "count"<<counts[i] <<endl;
    }
    system("pause");
    return 0;
}
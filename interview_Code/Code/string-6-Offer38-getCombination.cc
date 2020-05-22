#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

//题目：字符串组合

void combinationCore( char * str, int len , vector<char>& rs){

    if( len == 0){
        vector<char>::iterator it;

        for( it = rs.begin();it<rs.end() ; it++){

            cout <<(*it);
        }
        cout <<endl;
        return;
    }

    rs.push_back(*str);
    combinationCore(str+1,len-1,rs);
    rs.pop_back();
    combinationCore(str+1, len,rs);

}
void getCombination( char* str){

    if( str == nullptr){
        return;
    }

    int length = strlen(str);

    vector<char> rs;

    for( int i =1 ;i<=length ;i++){
        combinationCore( str, i, rs);
    }
}
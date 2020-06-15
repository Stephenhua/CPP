#include<stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/*
矩阵乘法：
方法：
一般朴素乘法；斯塔拉森算法；降低时间复杂度；
*/

vector<vector<int>> Matrix(vector<vector<int>> a, vector<vector<int>> b){

    vector<vector<int>> result;
    int a_Raw = a.size();
    int a_Col = a[0].size();

    int b_Raw = b.size();
    int b_Col = b[0].size();

    if( a[0].size != b.size()){
        return result;
    }

    for(int i=0;i<a_Raw;i++){

        for( int j=0 ;j < b_Col ;j++){

            if(a[i][j]){//通过判断是否为 0 ，减少相乘次数；

                for(int m =0 ;m <a_Col ;m++){

                    result[i][j] += a[i][m] * b[m][j];
                }

            }

        }
    }

    return result;
}
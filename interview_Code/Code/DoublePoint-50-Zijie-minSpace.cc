#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;


/*
某一个大文件被拆成了N个小文件，每个小文件编号从0至N-1，
相应大小分别记为S(i)。给定磁盘空间为C，试实现一个函数从N个文件中连续选出若干个文件拷贝到磁盘中，
使得磁盘剩余空间最小。

*/

 class Solution {
    vector<int> findMin(vector<int> s,int c){

        int i = 0;
        int j = 0 ;
        int minVaule = INT_MAX;
        int sum = 0;
        int left = 0 ;
        int right = 0;
        vector<int> res;

        while (j < s.size())
        {
            if( sum <= c){
                right++;
                sum += s[j];
                minVaule = min( minVaule, c -sum);
                if( minVaule == c - sum){
                    left= i;
                    right= j;
                }
            }else if( sum > c){
                i++;
                sum -= s[i];//缩小左边的窗口；
            }
            /* code */
        }

        for( int i = left ;i < right ;i++){
            
            res.push_back( i);
        }
        return res;
        
        
    }

 };
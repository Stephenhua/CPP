#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;

/*

一个无序数组，从小到大找到第一个缺的数，比如[8 2 4 3 6 9 7 11 12],第一个缺的就是5 

*/


/*
方法一：通过vector构建哈希表，将数字i放在数组中的i索引处，然后找出中间没有出现的位置，c从而可以找到剩余的点；

*/
class Solutions{
    int findLost(vector<int>& nums){
        
        int minValue = nums[0];
        int maxValue = nums[0];
        for( int value : nums){
            minValue = min(minValue , value);
            maxValue = max( maxValue, value);
        }
        vector<int> res(maxValue-minValue+1);

        for( int i = 0 ;i < res.size() ;i++){
            res[i] = minValue -1 ;
        }


        for( int value : nums){
            res[value] = value;
        }

        int i = 0 ;
        while( i <res.size()){
            if( res[i] == minValue -1){
                break;
            }
        }
        return i;
    }
};
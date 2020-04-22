#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <Windows.h>
using namespace std;

/*
题目：摇摆序列；
一个整数序列，如果两个相邻元素的差恰好正负(负正)交替出现，则该序列呗成为摇摆序列，
一个小于2个元素的序列直接为摇摆序列，给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度。
*/

int WiggleSubsquence( vector<int>& nums){

    const int begin = 0 ;
    const int up =1; 
    const int down = 2;

    int state = begin ;
    int max_lenght = 1;
    if(nums.size() <2){
        return nums.size();
    }

    for(int i= 1; i<nums.size() ;i++){

        int def = nums[i] - nums[i-1];
        
        switch (state)
        {
            case begin:
                if(def>0){
                    state = up;
                    max_lenght++;
                }else if(def<0){
                    state = down ;
                    max_lenght++;
                }
                /* code */
                  break;

            case up:
                if(def<0){
                    state = down ;
                    max_lenght++;
                }
                break;
            
            case down :
                if(def > 0){
                    state =up ;
                    max_lenght++;
                }
                break;
        }

    }
    return max_lenght;
}
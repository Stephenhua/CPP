/*
题目：猜数字游戏
*/
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <algorithm>
using namespace std;
int guess(int num);

//采用二分法进行求解；时间复杂度为Olog（n);
class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right =n;
        while(left<=right){
           int mid=left+(right-left)/2;

           int flag =guess(mid);
           if(flag==-1){
               right=mid-1;
           }else if(flag ==1){
               left=mid+1;
           }else{
               return mid ;
           }

        }
        return -1;
        
    }
};
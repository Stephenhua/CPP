/*
题目：有效的完全平方
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


//利用完全平方的性质进行求解；其复杂度为O(sqrt(N))
/*
1 = 1;
4 = 1 + 3;
9 = 1 + 3 + 5;
16 = 1 + 3 + 5 + 7;
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0){
            return false;
        }

        int i=1;
        while(num>0){
            num-=i;
            i+=2;
        }
        return num==0?true:false;
    }
};

//利用二分法进行查找

class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num==1) return true;
        int l = 2;
        int r = num>>1;
        long m=1;
        while(l <= r){
            m = (l+r)>>1;            
            if(m*m > num){
                r = m-1;
            }else{
                l = m+1;
            }
        }        
        return r*r==num;
    }

};

//利用牛顿迭代的方法进行求解；

class Solution {
public:
    bool isPerfectSquare(int num) {

        int i=num;
        while (i*i>num)
        {
            i=(i+num/i)/2;
            /* code */
        }
        return i*i==num;        
    }
};
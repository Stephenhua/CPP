/*
题目：First Bad Version
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

//采用方法：二分法进行求解,效率是最高的

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;        
    }
};
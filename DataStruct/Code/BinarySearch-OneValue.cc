#include <iostream>
#include <vector>
using namespace std ;

int BinarySearch( vector<int>& arr ,int target){
    
    int left = 0;
    int right = arr.size()-1;

    while( left <= right){

        int mid = left+ (right-left)/2;

        if( arr[mid] == target){

            return mid ;
        }
        else if( num[mid] < target){

            left = mid+1;
        }else if(num[mid] > target){
            
            right = mid -1;
        }

        return -1;
    }
}
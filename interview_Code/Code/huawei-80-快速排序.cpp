#include <vector>
#include <iostream>
#include <string>

using namespace std;

void Quick_sort( vector<int> & nums ){
    int size = nums.size();
    int left =  0 ;
    int right = size - 1 ;

    Core( nums, 0 ,right);
}

void Core( vector<int>& nums, int left , int right ){
    if( left >= right ){
        return ;
    }
    int index = Core_min(nums , left ,right);
    Core( nums,left ,index -1 );
    Core(nums, index+1, right);

}

int  Core_min( vector<int>& nums, int left ,int right ){

    int & key = nums[right];

    while( left < right ){
        
        while (left < right && nums[left] <= key)
        {
            left++;
        }

        while ( left < right && nums[right] >= key  )
        {
            right--;
        }

        swap(nums[left] , nums[right] );   
        
    }

    swap(nums[left],key);

    return left ;
}
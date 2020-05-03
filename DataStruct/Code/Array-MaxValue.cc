#include <iostream>
#include <vector>

using namespace std ;
//题目：找出数组中的最大值和次大值；

vector<int> FindValue( vector<int>& nums){
    int Max = 0 ;
    int Mid = 0;

    for(int i =0 ;i<nums.size() ; i++){

        if( nums[i] > Max){
            Mid = Max ;
            Max = nums[i];
        }else if( nums[i] >Mid){

            Mid = nums[i];

        }
    }

    return {Mid,Max};
} 

int main( int argc ,char* argv[]){
    
    vector<int> a = { 3,4,5,2,4,7,4,2,6};

    vector<int> result = FindValue(a);

    cout <<"MaxValue" <<result[1]<<endl;

    cout <<"MidValue" <<result[0] <<endl;

    system("pause");
    
    return 0 ;
}
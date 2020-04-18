# include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void  reOrderArray(vector<int>& nums){
    int size = nums.size();

    int k = 0; //记录已经存放好的个数；

    for(int i =0 ; i <= size ; i++){

        if( nums[i] % 2 == 1 ){

            int j = i;

            while( j > k ){//当j大于k时，就表示当前的值已经超过了最后一个奇数；
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
                j--;
            }

            k++;
        }
    }
}

int main( int argc ,char* argv[]){

    vector<int> result1 = { 1,2,3,4,5,6,7,8};
    reOrderArray(result1);
    for(int i=0;i<result1.size();i++){
        cout<< result1[i];
    }
    cout <<endl;

    system("pause");
    return 0;
}
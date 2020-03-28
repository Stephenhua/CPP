#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//查找第一个不小于目标值的数，可变形为查找最后一个小于目标值的数,不小于即大于等于target；
int find(vector<int>& arr, int target){
    int left=0;
    int right=arr.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return arr[left];

}

//查找最后一个小于目标值的数
int findLastVALUE(vector<int>& arr, int target){
    int left=0;
    int right=arr.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return arr[left-1];

}


// ====================测试代码====================
void Test(vector<int>& arr, int target,int expected)
{   
    int result;
    if(arr[arr.size()-1]<target){
        cout<<"No number"<<endl;
        result=expected;
    }else{
     result=find(arr,target);
         }
    if(result ==expected){
        cout<<"Passed"<<endl;
        cout<<result<<endl;
        }else{
        cout<<"Failed"<<endl;
        cout<<result<<endl;
    }

}

void Test2(vector<int>& arr, int target,int expected)
{   
    int result;
    if(arr[0]>target){
        cout<<"No number"<<endl;
        result=expected;
    }else{
     result=findLastVALUE(arr,target);
         }
    if(result ==expected){
        cout<<" Value Passed"<<endl;
        cout<<result<<endl;
        }else{
        cout<<" Valied Failed"<<endl;
        cout<<result<<endl;
    }

}

int main(int argc, char* argv[])
{
    vector<int> array1={  1, 3, 4, 5, };
    int target=2;
    Test(array1,2,3);
    Test2(array1,2,1);

    vector<int> array21={ 3, 5 };
    int target2=2;
    Test(array21,2,3);
    Test2(array21,5,3);


    vector<int> array31={ 3, 5,8 };
    int target32=2;
    Test(array31,target32,INT_MIN);
    Test2(array31,target32,INT_MIN);


    system("pause");

    return 0;
}
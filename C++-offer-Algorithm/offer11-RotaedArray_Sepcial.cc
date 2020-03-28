#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;
//旋转数组查找特定的值；

bool serachSpecialNum(vector<int>& arr ,int target){
    if(arr.size()==0){
        return false;
    }

    int start=0;
    int end=arr.size()-1;
    int mid;
    while(start+1<end){
        mid=start+(start+(end-start)>>1);
        if(arr[mid]==target){
            return true;
        }else if(arr[end]<arr[mid]){
            if(arr[start]<=target && target<arr[mid]){
                end=mid;
            }else{
                start=mid;
            }
        }else if(arr[mid]<arr[end]){
            if(arr[mid]<target&& arr[end]>=target){
                start = mid;
            }else{
                end = mid;
            }
        }else{
            --end;
        }
    }
    if(arr[start]==target){
        return true;
    }
    if(arr[end]==target){
        return true;
    }
    return false;
}


void Test1(vector<int>& arr, int target ,bool isf){

    bool hasNum=serachSpecialNum(arr,target);
    if(hasNum == isf){
        cout<<"passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }

}

int main(int argc,int *argv[]){
    // 典型输入，单调升序的数组的一个旋转
    vector<int> array11={ 3, 4, 5, 1, 2 };
    Test1(array11,3,1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    vector<int> array22={ 3, 4, 5, 1, 1, 2 };
    Test1(array22,2,1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    vector<int> array33={ 3, 4, 5, 1, 2, 2 };
    Test1(array33,1,1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    vector<int> array44={ 1, 0, 1, 1, 1 };
    Test1(array44,2,0);


    // 数组中只有一个数字

    vector<int> array66={ 2};
    Test1(array66,2,1);

    // 输入nullptr
    vector<int> array77={ };
    Test1(array77,0,0);

    system("pause");

    return 0;
}
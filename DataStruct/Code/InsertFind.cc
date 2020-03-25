#include <iostream>
#include <vector>
using namespace std;

bool InsertiongSearch(vector<int>& arr, int target ,int first,int last){
    int mid = first+ (target-arr[first])/(arr[last]-arr[first])*(last-first);
    if(first>last){
        return -1;
    }
    if(arr[mid]==target){
        return mid ;
    }

    if(arr[mid]>target){
        return InsertiongSearch(arr, target,first,mid-1);
    }

    if(arr[mid]<target){
        return InsertiongSearch(arr, target,mid+1,last);
    }

}

//测试代码
void Test(vector<int>& arr ,int target){

    int size=arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   bool hasNum=InsertiongSearch(arr,target,0,size);

    if(hasNum==1){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

//存在
void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    int arr_sort=6;
    Test(arr,arr_sort);
}

void Test2(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    int arr_sort=10;
    Test(arr,arr_sort);

}
void Test3(){
    vector<int> arr={1};
    int arr_sort=1;
    Test(arr,arr_sort);
}
void Test4(){
    vector<int> arr={};
    int arr_sort=-1;
    Test(arr,arr_sort);
}
int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    Test4();
    system("pause");
    return 0;
}
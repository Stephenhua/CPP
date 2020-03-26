#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

void MergeArray(vector<int>& arr,int first,int mid,int last ){
    int i=first,j=mid+1;
    int m=mid ,n=last;
    //int k=0;
    vector<int> temp;
    while(i<=m && j<=n){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=m){
        temp.push_back(arr[i++]);
    }
    while(j<=n){
        temp.push_back(arr[j++]);
    }
    int k=temp.size();
    /*
    //将该部分的值，最终赋给arr里面；
    for(int l=first ,k=0;l<=last;k++,l++){
        arr[l]=temp[k];
    }*/
    
    for(int i=0;i<k;i++){
        arr[first+i]=temp[i];
    }
}

void MergeSort(vector<int>& arr, int first,int last){
    if(first<last){
        int mid=(first+last)/2;
        MergeSort(arr,first,mid);//分、
        MergeSort(arr,mid+1,last);
        MergeArray(arr,first,mid,last);//和 治，同时进行比较大小；
    }
}


//测试代码
void Test(vector<int>& arr ,vector<int>& arr_sort){

    int size=arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   MergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int number=0;
    for(int i=0;i<size;i++){
        if(arr[i]==arr_sort[i]){
            number++;
            cout<<arr[i]<<"  "<<arr_sort[i]<<endl;
        }
    }
    if(number==size){
        cout<<"Passed"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
}

void Test1(){
    vector<int> arr={72,6,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
    Test(arr,arr_sort);
}

void Test2(){
    vector<int> arr={};
    vector<int> arr_sort={};
    Test(arr,arr_sort);

}
void Test3(){
    vector<int> arr={1};
    vector<int> arr_sort={1};
    Test(arr,arr_sort);
}
void Test4(){
    vector<int> arr={6,72,57,8,60,42,83,73,48,85};
    vector<int> arr_sort={6,8,42,48,57,60,72,73,83,85};
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
